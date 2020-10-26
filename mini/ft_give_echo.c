/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_give_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 12:09:28 by atomatoe          #+#    #+#             */
/*   Updated: 2020/10/26 17:43:13 by atomatoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int ft_give_echo(t_data *all, t_commands *cmd)
{
	int i;

	i = 1;
	if(cmd->arg[i] != NULL)
	{
		if(ft_compare_str(cmd->arg[i], "-n") == 1)
		{
			i++;
			while(cmd->arg[i])
			{
				if(ft_compare_str(cmd->arg[i], "$?") == 1)
				{
					ft_putstr(all->error);
					i++;
				}
				else
					ft_putstr(cmd->arg[i++]);
				//write(1, " ", 1);
			}
			free(all->error);
			all->error = ft_strdup("0");
			return(0);
		}
		else if(ft_compare_str(cmd->arg[i], "-n") != 1)
		{
			while(cmd->arg[i])
			{
				if(ft_compare_str(cmd->arg[i], "$?") == 1)
				{
					ft_putstr(all->error);
					i++;
				}
				else
					ft_putstr(cmd->arg[i++]);
				//write(1, " ", 1);
			}
			write(1, "\n", 1);
			free(all->error);
			all->error = ft_strdup("0");
			return(0);
		}
	}
	write(1, "\n", 1);
	free(all->error);
	all->error = ft_strdup("0");
	return (0);
}
