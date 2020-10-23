/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   give_directory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 17:41:33 by skarry            #+#    #+#             */
#include "../minishell.h"

int		if_local_path(t_commands *lst, char *command, char *pwd)
{
	char	*tmp;

	tmp = ft_strjoin(pwd + 4, command);
	if(access(tmp, F_OK) == 0)
	{
		lst->cmd_dir = tmp;
		free(lst->arg[0]);
		lst->arg[0] = ft_strdup((ft_strrchr(tmp, '/') + 1));
		return(1);
	}
	free(tmp);
	return (0);
}

int		if_full_path(t_commands *lst, char *command)
{
	if(access(command, F_OK) == 0)
	{
		lst->cmd_dir = ft_strdup(command);
		free(lst->arg[0]);
		lst->arg[0] = ft_strdup((ft_strrchr(command, '/') + 1));
		return(1);
	}
	return (0);
}

int		ft_give_directory(t_data *all, char *command, t_commands *lst)
{
	int i;
	int	j;
	int g;
	char **tmp;

	g = i = 0;
	if (!command || !all->env || !all->env[all->env_path_i])
		return (0);
	tmp = ft_split(all->env[all->env_path_i] + 5, ':');
	while(tmp[i])
	{
		tmp[i] = re_malloc('/', tmp[i]);
		j = 0;
		while (command[j])
		{
			tmp[i] = re_malloc(command[j], tmp[i]);
			j++;
		}
		if(access(tmp[i], F_OK) == 0)
		{
			lst->cmd_dir = ft_strdup(tmp[i]);
			free_msv(tmp);
			return(1);
		}
		i++;
	}
	free_msv(tmp);
	if (if_full_path(lst, command))
		return (1);
	if (if_local_path(lst, command, all->env_dir))
		return (1);
	return (0);
}

int	give_directory(t_commands *lst, t_data *all)
{
	if (ft_give_directory(all, lst->cmd, lst) == 1)
		lst->dir_find = 1;
	return (0);
}
