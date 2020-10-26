/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_give_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 17:32:30 by atomatoe          #+#    #+#             */
/*   Updated: 2020/10/26 15:21:56 by atomatoe         ###   ########.fr       */
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
	return (0);
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
	// int		fd[2];

	if (!cmd->dir_find)
		return (1);
	redir = cmd;
	pip = cmd;
	// if (pip->pipe)
	// {
	// 	pipe(fd);
	// 	dup2();
	// }
	pid_t pid = fork();
	if(pid < 0)
		perror(NULL);
	else if(pid == 0)
	{
		if (!(redirects(redir)))
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
