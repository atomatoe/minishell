/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_give_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 12:09:28 by atomatoe          #+#    #+#             */
/*   Updated: 2020/10/22 12:24:52 by atomatoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int ft_give_echo(t_commands *cmd)
{
	int i;

	i = 1;
	if(cmd->arg[i] != NULL)
	{
		if(ft_compare_str(cmd->arg[i], "-n") == 1)
		{
			i++;
			while(cmd->arg[i])
				printf("%s", cmd->arg[i++]);
			return(0);
		}
		else if(ft_compare_str(cmd->arg[i], "-n") != 1)
		{
			while(cmd->arg[i])
				printf("%s", cmd->arg[i++]);
			printf("\n");
			return(0);
		}
	}
	printf("\n");
	return (0);
}
