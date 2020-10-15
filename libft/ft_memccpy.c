/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 12:59:50 by atomatoe          #+#    #+#             */
/*   Updated: 2020/08/08 18:56:05 by atomatoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t	i;
	char	*str;
	char	*final;

	if (dest == src)
		return (dest);
	i = 0;
	str = (char *)src;
	final = (char *)dest;
	while (i < n)
	{
		final[i] = str[i];
		i++;
		if (str[i - 1] == (char)c)
			return (&(final[i]));
	}
	return (NULL);
}
