/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   give_directory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarry <skarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 17:41:33 by skarry            #+#    #+#             */
/*   Updated: 2020/10/22 13:26:35 by skarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int ft_give_directory(t_data *all, char *command)
{
	int i;
	int count;
	char *adress;
	char *ad;

	count = 0;
	i = ft_strlen(all->env[all->env_path_i]) + ft_strlen(command);
	if(!(adress = (char *)malloc(sizeof(char) * i + 1)))
		return(-1);
	adress[i] = '\0';
	i = 4;
	while(all->env[all->env_path_i][++i] != '\0')
	{
		if(all->env[all->env_path_i][i] == ':')
		{
			i++; // пропускает ':'
			adress[count] = '/';
			ad = ft_strjoin(adress, command);
			free(adress);
			adress = ad;
			ad = NULL;
			if(access(adress, 0) == 0)
			{
				all->file_dir = ft_strdup(adress);
				free(adress);
				adress = NULL;
				return(1);
			}
			else
			{
				adress = ft_strzero(adress);
				count = 0;
			}
		}
		adress[count] = all->env[all->env_path_i][i];
		count++;
	}
	free(adress);
	return(0);
}

void	give_directory(t_commands *lst, t_data *all)
{
	if (ft_give_directory(all, lst->cmd) == 1)
	{
		free(lst->arg[0]);
		lst->arg[0] = ft_strdup(all->file_dir);
		free(all->file_dir);
		all->file_dir = NULL;
	}
}
