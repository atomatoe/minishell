/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_give_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarry <skarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 17:32:30 by atomatoe          #+#    #+#             */
/*   Updated: 2020/10/26 18:01:21 by skarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		redirects(t_commands *redir)
{
	int			fd;

	while (redir->redir)
	{
		if (redir->type_redir == 1 && !redir->redir->invalid)
		{
			if ((fd = open(redir->redir->cmd, O_RDWR)) == -1)
				return (1);
		}
		else
		{
			if (redir->type_redir == 2 && !redir->redir->invalid)
				fd = open(redir->redir->cmd, O_CREAT | O_RDWR | O_TRUNC, S_IRWXU);
			if (redir->type_redir == 3 && !redir->redir->invalid)
				fd = open(redir->redir->cmd, O_CREAT | O_RDWR | O_APPEND, S_IRWXU);
			
		}
		dup2(fd, (redir->type_redir == 1)? 0 : 1);
		redir = redir->redir;
	}
	return (0);
}

void		pipe_end(t_commands *pip, t_data *all)
{
	if (pip->pipe)
	{
		close(1);
		dup2(all->fd1, 1);
		do_cmd(pip->pipe, all);
	}
}

void		wait_ex(int fd0, int fd1)
{
	{
		wait(0);
		dup2(fd0, 0);
		close(fd1);
		close(fd0);
	}
}


int			ft_give_command(t_commands *cmd, t_data *all)
{
	
	t_commands	*redir;
	t_commands	*pip;
	pid_t		pid;
	int		fd[2];

	redir = cmd;
	pip = cmd;
	if (pip->pipe)
	{
		pipe(fd);
		dup2(fd[1], 1);
	}
	pid = fork();
	if(pid < 0)
		perror(NULL);
	else if(pid == 0)
	{
		if (!(redirects(redir)))
			execve(cmd->cmd_dir, cmd->arg, all->env);
		exit(1);
	}
	else
		wait_ex(fd[0], fd[1]);
	pipe_end(pip, all);
	return (0);
}
