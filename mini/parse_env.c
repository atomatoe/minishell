/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 14:57:13 by atomatoe          #+#    #+#             */
/*   Updated: 2020/10/21 16:18:13 by atomatoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_env_update(t_data *all, char *str, char *arg, int count)
{
    str = ft_strjoin(arg, str);
    all->env[count] = ft_strdup(str);
    return 0;
}

char *ft_env_replace_home(char *str)
{
    char *res;
    int i;
    int j;

    j = 0;
    i = 0;
    if (str[0] == 'H' && str[1] == 'O' && str[2] == 'M' && str[3] == 'E' && str[4] == '=')
    {
        i = 4;
        if (!(res = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1 - 4))))
		    return (NULL);
        while (str[++i] != '\0')
        {
            res[j] = str[i];
            j++;
        }
        return (res);
    }
    return (NULL);
}

int ft_old_dir(t_data *all)
{
    char *tmp;
    int len;
    int i;

    i = 0;
    if(!(tmp = (char *)malloc(sizeof(char) * (ft_strlen(all->env[all->env_dir_i]) + 1))))
		    return (-1);
    getcwd(tmp, ft_strlen(all->env[all->env_dir_i]));
    all->env_old_dir = tmp;
    len = ft_strlen(tmp);
    while (tmp[len] != '/')
        len--;
    if (len == 0)
        len = 1;
    if (!(all->env_skip_dir = (char *)malloc(sizeof(char) * (len + 1))))
		    return (-1);
    while(i != len)
    {
        all->env_skip_dir[i] = tmp[i];
        i++;
    }
    //free(tmp);
    //tmp = NULL;
    return (0);
}

void ft_parse_env(t_data *all)
{
	int i;

	i = 0;
	while(all->env[i])
	{
		if(all->env[i][0] == 'P' && all->env[i][1] == 'W' && all->env[i][2] == 'D')
        {
            all->env_dir = ft_strdup(all->env[i]);
            all->env_dir_i = i;
        }
		if(all->env[i][0] == 'H' && all->env[i][1] == 'O' 
			&& all->env[i][2] == 'M' && all->env[i][3] == 'E' && all->env[i][4] == '=')
            all->env_home_dir = all->env[i];
        if(all->env[i][0] == 'O' && all->env[i][1] == 'L' && all->env[i][2] == 'D')
            all->env_old_dir_i = i;
		if(all->env[i][0] == 'P' && all->env[i][1] == 'A' 
			&& all->env[i][2] == 'T' && all->env[i][3] == 'H' && all->env[i][4] == '=')
            all->env_path_i = i;
		i++;
	}
    all->last_env = i;
}
