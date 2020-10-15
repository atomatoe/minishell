/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 19:03:40 by atomatoe          #+#    #+#             */
/*   Updated: 2020/08/08 18:56:24 by atomatoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*mem_clear(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

static int	num_letter(char const *s2, char c, int i)
{
	int		len;

	len = 0;
	while (s2[i] != c && s2[i] != '\0')
	{
		len++;
		i++;
	}
	return (len);
}

static int	num_word(char const *s, char c)
{
	int		i;
	int		g;

	i = 0;
	g = 0;
	if (s[0] != c)
		g++;
	while (s[i] != '\0')
	{
		while (s[i] == c)
		{
			i++;
			if (s[i] != c && s[i] != '\0')
				g++;
		}
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (g);
}

char		**ft_split(char const *s, char c)
{
	int		i;
	int		f;
	char	**str;

	i = 0;
	f = 0;
	if (!s)
		return (NULL);
	if (!(str = (char **)malloc(sizeof(char *) * num_word(s, c) + 1)))
		return (NULL);
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		if (!(str[f] = (char *)malloc(sizeof(char) * num_letter(s, c, i) + 1)))
			return (mem_clear(str));
		ft_strlcpy(str[f], &s[i], num_letter(s, c, i) + 1);
		i = i + num_letter(s, c, i);
		f++;
	}
	str[f] = NULL;
	return (str);
}
