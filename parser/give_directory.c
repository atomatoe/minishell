/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   give_directory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 17:41:33 by skarry            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2020/10/22 17:55:54 by atomatoe         ###   ########.fr       */
=======
/*   Updated: 2020/10/22 16:08:47 by skarry           ###   ########.fr       */
>>>>>>> 3272c6707a0d0b492c03bb2bbd867fcc3ee56bda
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int ft_give_directory(t_data *all, char *command)
{
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
			buf = ft_strdup(tmp);
			free(tmp);
			tmp = ft_strjoin(buf, command);
			free(buf);
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
	free(tmp);
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
