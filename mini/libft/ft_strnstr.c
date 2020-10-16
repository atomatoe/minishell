/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 16:38:00 by atomatoe          #+#    #+#             */
/*   Updated: 2020/08/08 18:56:30 by atomatoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t k)
{
	size_t	i;
	size_t	a;

	i = 0;
	if (*str2 == '\0')
		return ((char *)str1);
	while (str1[i] != '\0' && i < k)
	{
		a = 0;
		while (str2[a] != '\0' && str1[i + a] == str2[a] && str1[i + a] != '\0'
			&& i + a < k)
			a++;
		if (str2[a] == '\0')
			return ((char *)(str1 + i));
		i++;
	}
	return (NULL);
}
