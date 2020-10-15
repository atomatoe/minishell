/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 13:02:40 by atomatoe          #+#    #+#             */
/*   Updated: 2020/08/08 18:56:09 by atomatoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char *s;
	unsigned char *s2;

	s = (unsigned char *)src;
	s2 = (unsigned char *)dest;
	if (s == s2)
		return (s2);
	if (s < s2)
	{
		s = (unsigned char *)src + n - 1;
		s2 = dest + n - 1;
		while (n--)
		{
			*s2-- = *s--;
		}
	}
	else
		while (n--)
		{
			*s2++ = *s++;
		}
	return (dest);
}
