/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_for_mini.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarry <skarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 21:45:12 by skarry            #+#    #+#             */
/*   Updated: 2020/10/17 13:06:17 by skarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void		*free_str(char **str)
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

static int		count_sym(char const *s, char c)
{
	int i;
	int flag;

	i = 0;
	flag = 0;
	while ((*s != c && *s != '\"' && *s && !flag) || (!i && *s))
	{
		while (*s == c && *s)
			s++;
		if (*s == '\"' && *(s++))
		{
			while (*s != '\"')
			{
				i++;
				s++;
			}
			i--;
			if (i >= 0)
				flag++;
		}
		s++;
		i++;
	}
	return (i);
}

static int		count_words(char const *s, char c)
{
	int		cut;
	int		flag;
	int		flag1;

	cut = 0;
	flag = 0;
	flag1 = 0;
	while (*s)
	{
		if (*s != c)
		{
			if (*s == '\"')
			{
				s++;
				flag++;
			}
			if (*s && *s != c && *s != '\"')
				cut++;
			while ((*s && *s != c && !flag) || (*s && flag))
			{
				if (*s == '\"')
				{
					flag--;
					s++;
					break ;
				}
				else
					s++;
			}
		}
		while (*s == c)
			s++;
	}
	if (flag)
		return (0);
	return (cut);
}

char			**split_for_mini(char const *s, char c)
{
	char	**str;
	int		flag;
	int		flag2;
	int		i;
	int		j;

	flag = count_words(s, c);
	if (!s || !(str = (char**)malloc(sizeof(char*) * (flag + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (flag)
	{
		if (flag--)
		{
			if (!(str[j] = (char*)malloc(sizeof(char) * (count_sym(s, c) + 1))))
				return (free_str(str));
			flag2 = 0;
			while ((*s != c && *s != '\"' && *s && !flag2) || (!i && *s))
			{
				while (*s == c && *s)
					s++;
				if (*s == '\"' && *(s++))
				{
					while (*s != '\"')
					{
						str[j][i++] = *s++;
					}
					s++;
					if (i > 0)
						flag2++;
					continue ;
				}
				str[j][i++] = *s++;
			}
			str[j++][i] = '\0';
			i = 0;
		}
	}
	str[j] = NULL;
	return (str);
}
