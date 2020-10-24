/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 17:54:39 by atomatoe          #+#    #+#             */
/*   Updated: 2020/10/24 19:24:59 by atomatoe         ###   ########.fr       */
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

char *ft_str_union(char *s1, char *s2)
{
    int i;

    i = 0;
    while(s2[i] != '\0')
    {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
    return(s1);
}

// int ft_strcmp_declare(char *s1, char *s2)
// {
//     int i;

//     i = 0;
//     while(s2[i] != '\0')
//     {
//         if(s1[i] != s2[i])
//             return(-1);
//         i++;
//     }
//     return (0);
// }
