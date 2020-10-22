/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_give_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 17:45:59 by atomatoe          #+#    #+#             */
/*   Updated: 2020/10/22 11:58:26 by atomatoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int ft_give_export(t_commands *cmd, t_data *all)
{
	int i;
	int g;
	int count;
	char **tmp;

	count = 0;
	g = 0;
	i = 0;
	if(!(tmp = (char **)malloc(sizeof(char*) * (ft_strlen_msv(all->env) + ft_strlen_msv(cmd->arg) + 2))))
		return (-1);
	while(all->env[count])
	{
		// while(ft_str_check(all->env[count], arg) == 1)
		// 	count++;
		tmp[i] = ft_strdup(all->env[count]);
		count++;
		i++;
	}
    g++;
	while(cmd->arg[g])
	{
		tmp[i] = ft_strdup(cmd->arg[g]);
		i++;
		g++;
	}
	all->env = free_msv(all->env);
	all->env = ft_strdup_msv(tmp);
	printf("TESTING\n");
	return (0);
}
