/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_give_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 16:40:59 by atomatoe          #+#    #+#             */
/*   Updated: 2020/10/21 16:18:17 by atomatoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_give_export(t_commands *cmd, t_data *all)
{
	char **arg;
	if(!(arg = (char **)malloc(sizeof(char*) * (2 + 1))))
		return (-1);
	if (!(arg[0] = (char *)malloc(sizeof(char) * 8)))
		    return (0);
	if (!(arg[1] = (char *)malloc(sizeof(char) * 8)))
		    return (0);
	arg[0] = "a=hello";
	arg[1] = "b=world";

	int i;
	int g;
	int count;
	char **tmp;

	count = 0;
	g = 0;
	i = 0;
	if(!(tmp = (char **)malloc(sizeof(char*) * (ft_strlen_msv(all->env) + ft_strlen_msv(arg) + 2))))
		return (-1);
	while(all->env[count])
	{
		while(ft_str_check(all->env[count], arg) == 1)
			count++;
		tmp[i] = ft_strdup(all->env[count]);
		count++;
		i++;
	}
	while(arg[g])
	{
		tmp[i] = ft_strdup(arg[g]);
		i++;
		g++;
	}
	//all->env = free_msv(all->env);
	all->env = ft_strdup_msv(tmp);
	return (0);
}
