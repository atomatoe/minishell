/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 17:29:34 by atomatoe          #+#    #+#             */
/*   Updated: 2020/10/22 10:05:09 by atomatoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char *ft_strzero(char *str)
{
    int i;

    i = 0;
    while(str[i] != '\0')
    {
        str[i] = '\0';
        i++;
    }
    return(str);
}

char **ft_strdup_msv(char **str)
{
	char **tmp;
	int count;

	count = 0;
	while(str[count])
		count++;
	if(!(tmp = (char **)malloc(sizeof(char*) * (count + 1))))
		return (NULL);
	count = 0;
	while(str[count])
	{
		tmp[count] = str[count];
		count++;
	}
	free_msv(str);
	return(tmp);
}

int ft_strlen_msv(char **str)
{
	int i;

	i = 0;
	while(str[i])
		i++;
	return(i);
}

int ft_compare_str(char *s1, char *s2)
{
	int i;

	i = 0;
	while(s1[i] == s2[i])
	{
		i++;
		if(s1[i] == '\0' && s2[i] == '\0')
			return (1);
	}
	return (-1);
}

char **free_msv(char **str)
{
    int i;

    i = 0;
    while (str[i])
    {
        free(str[i]);
		str[i] = NULL;
        i++;
    }
    free(str);
    str = NULL;
    return (str);
}
