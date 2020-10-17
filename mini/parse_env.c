/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 14:57:13 by atomatoe          #+#    #+#             */
/*   Updated: 2020/10/17 17:37:57 by atomatoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char *ft_env_replace(char *str)
{
    char *res;
    int i;
    int j;

    j = 0;
    i = 0;
    if(str[0] == 'H' && str[1] == 'O' && str[2] == 'M' && str[3] == 'E' && str[4] == '=')
    {
        i = 4;
        if (!(res = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1 - 4))))
		    return (NULL);
        while(str[++i] != '\0')
        {
            res[j] = str[i];
            j++;
        }
        res[j] = '\0';
        return(res);
    }
    return (NULL);
}

static int ft_skip_dir_full(t_data *all, char *str, int j)
{
    int count;
    int i;

    i = 0;
    count = 0;
    if (!(all->env_skip_dir_full = (char *)malloc(sizeof(char) * (j + 1))))
	    return (-1);
    while(i != j)
    {
        all->env_skip_dir_full[count] = str[i];
        i++;
        count++;
    }
    all->env_skip_dir_full[count] = '\0';
    return (0);
}

int ft_skip_dir(t_data *all, char *str)
{
    int i;
    int j;
    int count;

    count = 0;
    i = 4;
    j = ft_strlen(str);
    if(str[4] == '\0')
        return (0);
    if(ft_compare_str(str, "PWD=/Users") == 1) // если дошли до папки системы ./
    {
        free(all->env_skip_dir);
        all->env_skip_dir[0] = '/';
        all->env_skip_dir[1] = '\0';
        all->env_skip_dir_full = "PWD=/";
        return (0);
    }
    while (str[j] != '/')
        j--;
    if (!(all->env_skip_dir = (char *)malloc(sizeof(char) * (j - 4 + 1))))
	    return (-1);
    while(i != j)
    {
        all->env_skip_dir[count] = str[i];
        i++;
        count++;
    }
    all->env_skip_dir[count] = '\0';
    ft_skip_dir_full(all, str, j);
    return (0);
}

void ft_parse_env(t_data *all, char **env)
{
	int i;

	i = 0;
	all->env = env;
	while(all->env[i])
	{
		if(all->env[i][0] == 'P' && all->env[i][1] == 'W' && all->env[i][2] == 'D')
        {
            all->count_dir = i;
            all->env_dir = env[i];
        }
		if(all->env[i][0] == 'H' && all->env[i][1] == 'O' 
			&& all->env[i][2] == 'M' && all->env[i][3] == 'E' && all->env[i][4] == '=')
            all->env_home_dir = env[i];
		i++;
	}
}