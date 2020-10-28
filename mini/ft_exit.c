/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarry <skarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 12:50:42 by skarry            #+#    #+#             */
/*   Updated: 2020/10/28 12:57:06 by skarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_exit(t_commands *cmd, t_data *all, t_commands *pip)
{
	if (!pip->pipe)
	{
		write(1, "exit\n", 5);
		if (cmd->arg[1])
		{
			ft_putstr("minishell: exit: ");
			ft_putstr(cmd->arg[1]);
			ft_putstr(": numeric argument required\n");
		}
		exit(ft_atoi(all->error));
	}
}
