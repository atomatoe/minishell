/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_give_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarry <skarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 17:32:30 by atomatoe          #+#    #+#             */
/*   Updated: 2020/10/24 20:12:21 by skarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int ft_give_command(t_commands *cmd, t_data *all)
{
	int			fd;
	t_commands	*redir;

	redir = cmd;
	while (redir->redir)
	{
		if (redir->type_redir == 2 && !redir->redir->invalid)
			fd = open(redir->redir->cmd, O_CREAT | O_RDWR | O_TRUNC, S_IRWXU);
		if (redir->type_redir == 3 && !redir->redir->invalid)
			fd = open(redir->redir->cmd, O_CREAT | O_RDWR | O_APPEND, S_IRWXU);
		redir = redir->redir;
		dup2(fd, 1);
	}
	pid_t pid = fork();
	if(pid < 0)
		perror(NULL);
	else if(pid == 0)
	{
		execve(cmd->cmd_dir, cmd->arg, all->env);
		perror(NULL);
	}
	else
		wait(0);
	if (cmd->type_redir)
	{
		dup2(all->mainfd, 1);
		close(fd);
	}
	return (0);
}
