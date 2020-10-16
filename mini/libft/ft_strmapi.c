/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 15:51:41 by atomatoe          #+#    #+#             */
/*   Updated: 2020/08/08 18:56:28 by atomatoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		i;
	int		k;

	if (!f || !s)
		return (NULL);
	i = 0;
	k = (int)ft_strlen(s);
	if (!(str = (char *)malloc(sizeof(char) * (1 * k + 1))))
		return (NULL);
	k = 0;
	while (s[i] != '\0')
	{
		str[k] = f(i, s[i]);
		i++;
		k++;
	}
	str[k] = '\0';
	return (str);
}
