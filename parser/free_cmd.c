/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cmd->c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarry <skarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 19:57:55 by skarry            #+#    #+#             */
/*   Updated: 2020/10/17 20:09:54 by skarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	free_cmd(t_commands *cmd)
{
	if(cmd)
	{
		if (cmd->redir)
			free_cmd(cmd->redir);
		if (cmd->pipe)
			free_cmd(cmd->pipe);
		if (cmd->next)
			free_cmd(cmd->next);
		// cmd->cmd;
		if (cmd->arg)
			free_str(&cmd->arg);
		free (cmd);
	}
}