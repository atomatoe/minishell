/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_give_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarry <skarry@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 17:32:30 by atomatoe          #+#    #+#             */
/*   Updated: 2020/10/26 20:36:39 by skarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int			redirects(t_commands *redir)
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

void		pipe_end(t_commands *pip, t_data *all, int fd0, int fd1)
{
	dup2(fd0, 0);
	close(fd1);
	close(fd0);
	if (pip->pipe)
	{
		close(1);
		dup2(all->fd1, 1);
		do_cmd(pip->pipe, all);
	}
}

int			ft_give_command(t_commands *cmd, t_data *all)
{
	pid_t	pid;
	
	pid = fork();
	if(pid < 0)
		perror(NULL);
	else if(pid == 0)
	{
		execve(cmd->cmd_dir, cmd->arg, all->env);
		exit(1);
	}
	else
		wait(0);
	return (0);
}
