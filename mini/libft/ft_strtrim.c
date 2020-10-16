/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 15:54:34 by atomatoe          #+#    #+#             */
/*   Updated: 2020/08/08 18:56:32 by atomatoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len_s;
	char	*result_str;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	len_s = ft_strlen(s1);
	while (len_s && ft_strchr(set, s1[len_s]))
	{
		len_s--;
	}
	result_str = ft_substr((char*)s1, 0, len_s + 1);
	return (result_str);
}
