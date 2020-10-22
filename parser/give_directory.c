/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   give_directory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 17:41:33 by skarry            #+#    #+#             */
#include "../minishell.h"

int ft_give_directory(t_data *all, char *command, t_commands *lst)
{
	int i;
	int	j = 0;
	int g;
	char *tmp;
	g = 0;


	i = 5;
	if (!command || !all->env || !all->env[all->env_path_i])
		return (0);
	if(!(tmp = (char *)ft_calloc(sizeof(char) * (ft_strlen(all->env[all->env_path_i]) + 1), 1)))
		return(0);
	while(all->env[all->env_path_i][i] != '\0')
	{
		tmp[g] = all->env[all->env_path_i][i];
		g++;
		i++;
		if(all->env[all->env_path_i][i] == ':' || all->env[all->env_path_i][i] == '\0')
		{
			
			if (all->env[all->env_path_i][i] == ':')
				i++;
			tmp[g++] = 47;
			j = 0;
			while (command[j])
			{
				tmp[g] = command[j];
				g++;
				j++;
			}
			if(access(tmp, F_OK) == 0)
			{
				lst->cmd_dir = tmp;
				return(1);
			}
			tmp = ft_strzero(tmp);
			g = 0;
		}
	}
	free(tmp);
	return (0);
}

int	give_directory(t_commands *lst, t_data *all)
{
	if (ft_give_directory(all, lst->cmd, lst) == 1)
		lst->dir_find = 1;
	return (0);
}
