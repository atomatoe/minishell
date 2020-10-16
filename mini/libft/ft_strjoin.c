/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 16:12:41 by atomatoe          #+#    #+#             */
/*   Updated: 2020/08/08 18:56:26 by atomatoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strjoin(char const *s1, char const *s2)
{
	char		*s3;
	size_t		size1;
	size_t		size2;

	if (!s2 || !s1)
		return (NULL);
	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	if (!(s3 = (char*)malloc(sizeof(char) * (size1 + size2 + 1))))
		return (NULL);
	ft_strlcpy(s3, s1, (size1 + 1));
	ft_strlcat(s3, s2, (size1 + size2 + 1));
	return (s3);
}
