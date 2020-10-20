/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarry <skarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 14:58:19 by skarry            #+#    #+#             */
/*   Updated: 2020/10/20 15:11:47 by skarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	print_lst(t_commands *cmd)
{
	int	i = 0;

	if(cmd)
	{
		while (cmd->arg[i])
		{
			printf("---arg[%s]\n", cmd->arg[i]);
			i++;
		}
		printf("---type_redir: %d\n", cmd->type_redir);
		printf("---invalid: %d\n\n", cmd->invalid);
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