/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   give_directory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 17:41:33 by skarry            #+#    #+#             */
#include "../minishell.h"

static int ft_give_directory(t_data *all, char *command, t_commands *lst)
{
	int i;
	int g;
	char *tmp;
	char *buf;
	g = 0;
	i = 5;
	// ft_putstr_fd(all->env[all->env_path_i], 1);
	if(!(tmp = (char *)malloc(sizeof(char) * (ft_strlen(all->env[all->env_path_i]) + 1))))
		return(-1);
	tmp[ft_strlen(all->env[all->env_path_i])] = '\0';
	while(all->env[all->env_path_i][i] != '\0')
	{
		tmp[g] = all->env[all->env_path_i][i];
		g++;
		i++;
		if(all->env[all->env_path_i][i] == ':' || all->env[all->env_path_i][i] == '\0')
		{
			if (all->env[all->env_path_i][i] == ':')
				i++;
			tmp[g] = '/';
			buf = ft_strdup(tmp);
			free(tmp);
			tmp = ft_strjoin(buf, command);
			free(buf);
			if(access(tmp, 0) == 0)
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

void	give_directory(t_commands *lst, t_data *all)
{
	if (ft_give_directory(all, lst->cmd, lst) == 1)
	{
		lst->dir_find = 1;
	}
}
