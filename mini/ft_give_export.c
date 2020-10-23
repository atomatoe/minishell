/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_give_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 17:45:59 by atomatoe          #+#    #+#             */
/*   Updated: 2020/10/23 15:01:49 by atomatoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int ft_find_char(char *str)
{
	int i;

	i = 1;
	if(str[0] == '\0')
		return(0);
	while(str[i] != '\0')
	{
		if(str[i] == '=')
			return(1);
		i++;
	}
	return(0);
}

static int ft_check_arg(t_commands *cmd)
{
	int i;
	int g;
	char **tmp;

	g = 1;
	if(!(tmp = (char **)malloc(sizeof(char*) * (ft_strlen_msv(cmd->arg) + 1))))
		return (-1);
	i = 1;
	tmp[0] = ft_strdup(cmd->arg[0]);
	while(cmd->arg[i] != NULL)
	{
		if(ft_find_char(cmd->arg[i]) == 1)
		{
			tmp[g] = ft_strdup(cmd->arg[i]);
			g++;
		}
		i++;
	}
	tmp[g] = NULL;
	free_msv(cmd->arg);
	cmd->arg = NULL;
	cmd->arg = tmp;
	return(0);
}

static int ft_str_check_exp(char *str, char **arg)
{
	int i;
	int g;
	int k;
	int count;

	if(str == NULL)
		return(0);
	k = 0;
	while(str[k] != '=')
		k++;
	count = 1;
	i = ft_strlen_msv(arg);
	while(i != 1)
	{
		g = 0;
		while(str[g] == arg[count][g])
		{
			g++;
			if(arg[count][g] == '=' && str[g] == '=')
				return(1);
		}
		count++;
		i--;
	}
	return (0);
}

int ft_give_export(t_commands *cmd, t_data *all)
{
	int i;
	int g;
	int count;
	char **tmp;

	count = 0;
	g = 0;
	i = 0;
	ft_check_arg(cmd);
	if(!(tmp = (char **)malloc(sizeof(char*) * (ft_strlen_msv(all->env) + ft_strlen_msv(cmd->arg) + 1))))
		return (-1);
	while(all->env[count] != NULL)
	{
		tmp[i] = ft_strdup(all->env[count]);
		count++;
		i++;
		if(ft_str_check_exp(all->env[count], cmd->arg) == 1)
			count++;
	}
    g++;
	while(cmd->arg[g])
	{
		tmp[i] = ft_strdup(cmd->arg[g]);
		i++;
		g++;
	}
	tmp[i] = NULL;
	free_msv(all->env);
	all->env = NULL;
	all->env = tmp;
	return (0);
}
