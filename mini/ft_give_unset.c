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

static int ft_str_check_uns(char *str, char **arg)
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
			if(arg[count][g] == '\0' && str[g] == '=')
				return(1);
		}
		count++;
		i--;
	}
	return (0);
}

static int ft_str_check_declares(char *str, char **arg)
{
	int i;
	int g;
	int count;
	int len;

	count = 1;
	len = ft_strlen_msv(arg);
	while(len != 1)
	{
		g = 0;
		i = 0;
		while(str[i] == arg[count][g])
		{
			g++;
			i++;
			if(arg[count][g] == '\0')
				return(1);
		}
		len--;
		count++;
	}
	return(0);
}

static int ft_unset_declare(t_commands *cmd, t_data *all)
{
	int i;
	int count;
	char **tmp;

	i = 0;
	count = 0;
	if(!(tmp = (char **)malloc(sizeof(char*) * (ft_strlen_msv(all->env_declare) + 1))))
		return (-1);
	while(all->env_declare[count])
	{
		if(ft_str_check_declares(all->env_declare[count], cmd->arg) != 1)
		{
			tmp[i] = ft_strdup(all->env_declare[count]);
			i++;
		}
		count++;
	}
	tmp[i] = NULL;
	free_msv(all->env_declare);
	all->env_declare = NULL;
	all->env_declare = tmp;
	return(0);
}

int ft_give_unset(t_commands *cmd, t_data *all)
{
	int i;
	int count;
	char **tmp;

	count = 0;
	i = 0;
	if(!(tmp = (char **)malloc(sizeof(char*) * (ft_strlen_msv(all->env) + 1))))
		return (-1);
	while(all->env[count] != NULL)
	{
		if(ft_str_check_uns(all->env[count], cmd->arg) != 1)
		{
			tmp[i] = ft_strdup(all->env[count]);
			i++;
		}
		count++;
	}
	tmp[i] = NULL;
	free_msv(all->env);
	all->env = NULL;
	all->env = tmp;
	ft_unset_declare(cmd, all);
	return(0);
}