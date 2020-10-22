/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   give_directory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarry <skarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 17:41:33 by skarry            #+#    #+#             */
/*   Updated: 2020/10/22 15:59:14 by skarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int ft_give_directory(t_data *all, char *command)
{
	// all->env[all->env_path_i]  =   PATH=/Users/atomatoe/.brew/bin:/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/munki:/Users/atomatoe/.brew/bin
	// comand = ls
	printf("command = '%s'\n", command);
	printf("'%s'\n", all->env[all->env_path_i]);
	int i;
	int g;
	char *tmp;
	char *buf;
	g = 0;
	i = 5;
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
			buf = ft_strdup(tmp);//здесь работает только оригинальные strdup
			tmp = ft_strjoin(buf, command);
			// printf("command' = '%s'\n", tmp);
			free(buf);
			//printf("command = '%s'\n", tmp);
			if(access(tmp, 0) == 0)
			{
				all->file_dir = ft_strdup(tmp);
				free(tmp);
				tmp = NULL;
				return(1);
			}
			tmp = ft_strzero(tmp);
			g = 0;
		}
	}
	return (0);
}

void	give_directory(t_commands *lst, t_data *all)
{
	if (ft_give_directory(all, lst->cmd) == 1)
	{
		lst->dir_find = 1;
		lst->cmd_dir = ft_strdup(all->file_dir);
		free(all->file_dir);
		all->file_dir = NULL;
	}
	else
		return ;
}
