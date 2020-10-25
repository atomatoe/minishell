/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarry <skarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 17:13:10 by atomatoe          #+#    #+#             */
/*   Updated: 2020/10/24 21:57:21 by skarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
void	do_cmd(t_commands *cmd, t_data *all)
{
	if (cmd->cmd)
	{
		if(ft_compare_str(cmd->cmd, "pwd") == 1)
			ft_give_pwd(cmd);
		else if(ft_compare_str(cmd->cmd, "env") == 1)
			ft_give_env(cmd, all);
		else if(ft_compare_str(cmd->cmd, "echo") == 1)
			ft_give_echo(cmd);
		else if(ft_compare_str(cmd->cmd, "export") == 1)
			ft_give_export(cmd, all);
		else if(ft_compare_str(cmd->cmd, "unset") == 1)
			ft_give_unset(cmd, all);
		else if(ft_compare_str(cmd->cmd, "cd") == 1)
			ft_give_cd(cmd, all);
		else if(cmd->dir_find == 1)
			ft_give_command(cmd, all);
	}
}

int ft_start (t_commands *cmd, t_data *all)
{
	// t_commands	*pipe;
	t_commands	*next;
	// t_commands	*redir;

	next = cmd;
	while (next)
	{
		if (!next->invalid)
			do_cmd(next, all);
		next = next->next;
		dup2(all->fd1, 1);
		dup2(all->fd0, 0);
	}
	return(0);
}
