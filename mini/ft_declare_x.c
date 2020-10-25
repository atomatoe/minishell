/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_declare_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 12:45:59 by atomatoe          #+#    #+#             */
/*   Updated: 2020/10/25 13:50:14 by atomatoe         ###   ########.fr       */
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

static int ft_str_check_dec(char *str, char **arg)
{
    int i;
    int g;
    int len;
    int count;

    i = 0;
    count = 1;
	if(str == NULL)
		return(0);
    len = ft_strlen_msv(arg);
    while(len != 1)
    {
        g = 0;
		while(str[g] == arg[count][g])
		{
			g++;
			if(arg[count][g] == '\0' && str[g] == '\0')
				return(1);
		}
		count++;
		len--;
    }
	return (0);
}

static int ft_str_arg(t_commands *cmd, t_data *all)
{
	char **tmp;
    int i;
    int g;
    int count;
    
    count = 0;
    g = 1;
    i = 0;
    if(!(tmp = (char **)malloc(sizeof(char*) * (ft_strlen_msv(all->env_declare) + ft_strlen_msv(cmd->arg) + 1))))
		return (-1);
    while(all->env_declare[count])
    {
        if(ft_str_check_dec(all->env_declare[count], cmd->arg) != 1)
        {
            tmp[i] = ft_strdup(all->env_declare[count]);
            i++;
        }
        count++;
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
    int flag;

    i = 0;
    while(all->env_declare[i])
    {
        flag = 0;
        if(!(buf = (char *)ft_calloc(sizeof(char) * (ft_strlen(all->env_declare[i]) + 14), 1)))
            return(-1);
        g = 0;
        if(ft_strcmp_declare(all->env_declare[i], "declare -x ") != 0)
            buf = ft_str_union(buf, "declare -x ");
        len = 11;
        while(all->env_declare[i][g] != '\0')
        {
            buf[len] = all->env_declare[i][g];
            if(all->env_declare[i][g] == '=')
            {
                flag = 1;
                len++;
                buf[len] = '"';
            }
            len++;
            g++;
        }
        if(flag == 1)
            buf[len] = '"';
        buf[len + 1] = '\0';
        printf("%s\n", buf);
        free(buf);
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
    i = 0;
    if(cmd->arg[1] == NULL)
        ft_final_declare(all);
    return(0);
}