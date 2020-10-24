/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_declare_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 12:45:59 by atomatoe          #+#    #+#             */
/*   Updated: 2020/10/24 19:24:57 by atomatoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int ft_creat_declare(t_data *all)
{
    int i;

	i = 0;
	if(!(all->env_declare = (char **)malloc(sizeof(char*) * (ft_strlen_msv(all->env) + 1))))
		return (-1);
	while(all->env[i])
	{
		all->env_declare[i] = ft_strdup(all->env[i]);
		i++;
	}
	all->env_declare[i] = NULL;
	return(0);
}

int ft_str_check_declare(char **arg)
{
    int i;
    int g;

    i = 0;
    while(arg[i])
    {
        g = 0;
        while(arg[i][g] != '\0')
        {
            if(arg[i][g] == '=')
                return(1);
            g++;
        }
        i++;
    }
    return(0);
}

static int ft_str_arg(t_commands *cmd, t_data *all)
{
	char **tmp;
    int i;
    int g;
    
    g = 1;
    i = 0;
    if(!(tmp = (char **)malloc(sizeof(char*) * (ft_strlen_msv(all->env) + ft_strlen_msv(cmd->arg) + 1))))
		return (-1);
    while(all->env_declare[i])
    {
        tmp[i] = ft_strdup(all->env_declare[i]);
        i++;
    }
    while(cmd->arg[g])
    {
        tmp[i] = ft_strdup(cmd->arg[g]);
        i++;
        g++;
    }
    tmp[i] = NULL;
    free_msv(all->env_declare);
	all->env_declare = NULL;
	all->env_declare = tmp;
    return(0);
}

static int ft_final_declare(t_data *all)
{
    int i;
    int g;
    int len;
    char *buf;

    i = 0;
    // while(ft_strcmp_declare(all->env_declare[i], "declare -x ") == 0)
    //     i++;
    while(all->env_declare[i])
    {
        if(!(buf = (char *)ft_calloc(sizeof(char) * (ft_strlen(all->env_declare[i]) + 14), 1)))
            return(-1);
        g = 0;
        buf = ft_str_union(buf, "declare -x ");
        len = 11;
        while(all->env_declare[i][g] != '\0')
        {
            buf[len] = all->env_declare[i][g];
            if(all->env_declare[i][g] == '=')
            {
                len++;
                buf[len] = '"';
            }
            len++;
            g++;
        }
        buf[len] = '"';
        free(all->env_declare[i]);
        all->env_declare[i] =  buf;
        buf = NULL;
        i++;
    }
    return(0);
}

int ft_declare_x(t_commands *cmd, t_data *all)
{
    int i;
    int g;

    i = 0;
    ft_str_arg(cmd, all);
    while(all->env_declare[i])
    {
        g = 0;
        while(all->env_declare[g])
        {
            if(ft_strcmp(all->env_declare[i], all->env_declare[g]) == -1)
                ft_str_replace(all->env_declare, i, g);
            g++;
        }
        i++;
    }
    //if(flag == 1)
        ft_final_declare(all);
    i = 0;
    while(all->env_declare[i])
        printf("%s\n", all->env_declare[i++]);
    return(0);
}