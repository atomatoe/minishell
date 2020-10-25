/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_give_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarry <skarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 17:32:30 by atomatoe          #+#    #+#             */
/*   Updated: 2020/10/24 21:59:31 by skarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void		redirects(t_commands *redir)
{
	int			fd;

	while (redir->redir)
	{
		if (redir->type_redir == 1 && !redir->redir->invalid)
		{
			fd = open(redir->redir->cmd, O_CREAT | O_RDWR, S_IRWXU);
			dup2(fd, 0);
		}
		else
		{
			if (redir->type_redir == 2 && !redir->redir->invalid)
				fd = open(redir->redir->cmd, O_CREAT | O_RDWR | O_TRUNC, S_IRWXU);
			if (redir->type_redir == 3 && !redir->redir->invalid)
				fd = open(redir->redir->cmd, O_CREAT | O_RDWR | O_APPEND, S_IRWXU);
			dup2(fd, 1);
		}
		redir = redir->redir;
	}
}

// int		*pipes(t_commands *pip)
// {
// 	int		*fd;

// 	if (pip->pipe)
// 	{
// 		fd = (int *)malloc(sizeof(int) * 2);
// 		pipe(fd);
// 		dup2(fd[1], 1);
// 	}
// 	return (fd);
// }


int			ft_give_command(t_commands *cmd, t_data *all)
{
	
	t_commands	*redir;
	t_commands	*pip;
	int		*fd;

	if (!cmd->dir_find)
		return (1);
	redir = cmd;
	pip = cmd;
	if (pip->pipe)
	{
		fd = (int *)malloc(sizeof(int) * 2);
		pipe(fd);
	}
	pid_t pid = fork();
	if(pid < 0)
		perror(NULL);
	else if(pid == 0)
	{
		redirects(redir);
		write(1, "s\n", 2);
		execve(cmd->cmd_dir, cmd->arg, all->env);
		perror(NULL);
	}
	else
		wait(0);
	if (pip->pipe)
	{
		// dup2(1, all->fd1);
		// dup2(fd[0], 1);
		do_cmd(pip->pipe, all);

	}
	return (0);
}
