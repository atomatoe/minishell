/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 15:54:11 by atomatoe          #+#    #+#             */
/*   Updated: 2020/08/08 18:56:30 by atomatoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *str;

	str = 0;
	while (*s)
	{
		if (*s == c)
			str = (char *)s;
		s++;
	}
	if (str)
		return (str);
	if (c == '\0')
		return ((char *)s);
	return (0);
}
