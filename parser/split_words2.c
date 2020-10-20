/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_line_to_words.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarry <skarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 15:47:44 by skarry            #+#    #+#             */
/*   Updated: 2020/10/20 17:53:10 by skarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	*re_malloc(char c, char *w)
{
	char	*v;
	int		i;

	if (!w)
	{
		v = (char *)malloc(2);
		v[0] = c;
		v[1] = '\0';
		return (v);
	}
	v = (char *)malloc(ft_strlen(w) + 2);
	i = -1;
	while (w[++i])
		v[i] = w[i];
	v[i++] = c;
	v[i] = '\0';
	free (w);
	return (v);
}

int		if_backslash(char **line, int *i, char **w)
{
	if (!((*line)[*i + 1]))
	{
		i++;
		return (1);
	}
	*w = re_malloc((*line)[*i + 1], *w);
	*i += 2;
	return (0);
}

int		if_double_quotes(char **line, int i, char **w)
{
	i++;
	while ((*line)[i] && (*line)[i] != '\"')
	{
		if ((*line)[i] == '\\')
		{
			*w = re_malloc((*line)[i + 1], *w);
			i += 2;
		}
		else
			*w = re_malloc((*line)[i++], *w);
	}
	if ((*line)[i])
		i++;
	return (i);
}
int		if_single_quotes(char **line, int i, char **w)
{
	while ((*line)[i++] && (*line)[i] != '\'')
		*w = re_malloc((*line)[i], *w);
	if ((*line)[i])
		i++;
	return (i);
}

char	*get_word(char **line)
{
	char	*w;
	int		i;

	i = 0;
	w = NULL;
	i = skip_space((*line));
	while (((*line)[i] != ' ' && (*line)[i]) || (!w && (*line)[i]))
	{
		if ((*line)[i] == '\\')
			if (if_backslash(line, &i, &w))
				break ;
		if ((*line)[i] == '\'')
			i = if_double_quotes(line, i, &w);
		if ((*line)[i] == '\"')
			i = if_double_quotes(line, i, &w);
		while ((*line)[i] && (*line)[i] != ' ' && (*line)[i] != '\\'
				&& (*line)[i] != '\'' && (*line)[i] != '\"')
		{
			w = re_malloc((*line)[i], w);
			i++;
		}
	}
	*line = *line + i;
	return (w);
}
