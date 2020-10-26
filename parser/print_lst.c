/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarry <skarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 14:58:19 by skarry            #+#    #+#             */
/*   Updated: 2020/10/26 18:04:00 by skarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	print_lst(t_commands *cmd)
{
	int	i = 0;

	if(cmd)
	{
		if (cmd->arg)
		{
			printf("---cmd[%s]\n", cmd->cmd);
			while (cmd->arg[i])
			{
				printf("---arg[%s]\n", cmd->arg[i]);
				i++;
			}
			printf("---type_redir: %d\n", cmd->type_redir);
			printf("---invalid: %d\n", cmd->invalid);
			printf("---dir_find: %d\n", cmd->dir_find);
			if (cmd->cmd_dir)
				printf("---dir[%s]\n", cmd->cmd_dir);
			printf("\n");
			if (cmd->redir)
			{
				printf("---go to redir from [%s]\n", cmd->cmd);
				print_lst(cmd->redir);
			}
			if (cmd->pipe)
			{
				printf("---go to pip from [%s]\n", cmd->cmd);
				print_lst(cmd->pipe);
			}
			if (cmd->next)
			{
				printf("---go to next from [%s]\n", cmd->cmd);
				print_lst(cmd->next);
			}
		}
	}
}
