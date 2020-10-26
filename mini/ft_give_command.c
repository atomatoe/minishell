/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_give_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 17:32:30 by atomatoe          #+#    #+#             */
/*   Updated: 2020/10/26 17:02:35 by atomatoe         ###   ########.fr       */
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
	int		fd[2];

	if (!cmd->dir_find)
		return (1);
	redir = cmd;
	pip = cmd;
	if (pip->pipe)
	{
		pipe(fd);
		dup2(fd[1], 1);
		// dup2(fd[0], 0);
	}
	pid_t pid = fork();
	if(pid < 0)
		perror(NULL);
	else if(pid == 0)
	{
		if (!(redirects(redir)))
			execve(cmd->cmd_dir, cmd->arg, all->env);
		exit(1);
	}
	else
	{
		wait(0);
		dup2(fd[0], 0);
		close(fd[1]);
		close(fd[0]);
	}
	dup2(all->fd1, 1);
	if (pip->pipe)
	{
		dup2(fd[0], 0);
		close(1);
		dup2(all->fd1, 1);
		do_cmd(pip->pipe, all);
		return (0);
	}
	close(0);
	dup2(all->fd0, 0);
	return (0);
}
