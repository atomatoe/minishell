/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_give_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 13:47:54 by atomatoe          #+#    #+#             */
/*   Updated: 2020/10/20 13:47:54 by atomatoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int ft_give_unset(t_commands *cmd, t_data *all)
{
	ft_strlen(cmd->cmd);
	ft_strlen(all->env[0]);
	// int i;
	// int count;
	// char **tmp;

	// count = 0;
	// i = 0;
	// if(!(tmp = (char **)malloc(sizeof(char*) * (ft_strlen_msv(all->env) - ft_strlen_msv(cmd->arg) + 2))))
	// 	return (-1);
	// while(all->env[count])
	// {
	// 	// while(ft_str_check(all->env[count], arg) == 1)
	// 	// 	count++;
	// 	tmp[i] = ft_strdup(all->env[count]);
	// 	count++;
	// 	i++;
	// }
	// all->env = free_msv(all->env);
	// all->env = ft_strdup_msv(tmp);
	return(0);
}