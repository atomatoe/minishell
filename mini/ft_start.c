/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 17:13:10 by atomatoe          #+#    #+#             */
/*   Updated: 2020/10/25 16:50:30 by atomatoe         ###   ########.fr       */
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
		else if(ft_compare_str(cmd->cmd, "exit") == 1)
		{
			write(1, "exit\n", 5);
			exit(0);
		}
		else if(cmd->dir_find == 1)
			ft_give_command(cmd, all);
		else
		{
			ft_putstr(cmd->cmd);
			write(1, ": command not found\n", 20);
		}
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
			if(ft_valid_argument(cmd) == 0)
				do_cmd(next, all);
		next = next->next;
		dup2(all->fd1, 1);
		dup2(all->fd0, 0);
	}
	return(0);
}
