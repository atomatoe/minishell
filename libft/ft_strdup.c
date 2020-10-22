/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarry <skarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 13:55:52 by skarry            #+#    #+#             */
/*   Updated: 2020/10/22 15:59:02 by skarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *str)
{
	char	*str2;
	int		i;
	int		j;

	j = ft_strlen(str);
	if (!(str2 = (char*)malloc(sizeof(char) * (ft_strlen(str) + 1))))
		return (NULL);
	i = 0;
	if (str)
	{
		while (i < j)
		{
			str2[i] = str[i];
			i++;
		}
	}
	str2[i] = '\0';
	return (str2);
}
