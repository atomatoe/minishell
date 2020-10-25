/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 17:54:39 by atomatoe          #+#    #+#             */
/*   Updated: 2020/10/25 18:39:35 by atomatoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int ft_strcmp(char *s1, char *s2)
{
    int i;

    i = 0;
    while(s1[i] != '\0' && s2[i] != '\0')
    {
        if(s1[i] > s2[i])
            return(1);
        if(s1[i] < s2[i])
            return(-1);
        i++;
    }
    return (0);
}

char **ft_str_replace(char **env, int i, int g)
{
    char *str;

    str = ft_strdup(env[i]);
    free(env[i]);
    env[i]= NULL;
    env[i] = ft_strdup(env[g]);
    free(env[g]);
    env[g] = NULL;
    env[g] = ft_strdup(str);
    free(str);
    str = NULL;
    return(env);
}

void ft_putstr(char *str)
{
    int i;

    i = 0;
    while(str[i])
        write(1, &str[i++], 1);
}
