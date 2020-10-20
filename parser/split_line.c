/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarry <skarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 15:47:44 by skarry            #+#    #+#             */
/*   Updated: 2020/10/20 12:40:11 by skarry           ###   ########.fr       */
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

char	*get_word(char **line)
{
	char	*w;
	int		i;

	i = 0;
	w = NULL;
	while ((*line)[i] == ' ')
		i++;
	while (((*line)[i] != ' ' && (*line)[i]) || (!w && (*line)[i]))
	{
		if ((*line)[i] == '\\')
		{
			if (!((*line)[i + 1]))
			{
				i++;
				break ;
			}
			w = re_malloc((*line)[i + 1], w);
			i += 2;
		}
		if ((*line)[i] == '\'')
		{
			while ((*line)[i++] && (*line)[i] != '\'')
				w = re_malloc((*line)[i], w);
			if ((*line)[i])
				i++;
		}
		if ((*line)[i] == '\"')
		{
			i++;
			while ((*line)[i] && (*line)[i] != '\"')
			{
				if ((*line)[i] == '\\')
				{
					w = re_malloc((*line)[i + 1], w);
					i += 2;
				}
				else
					w = re_malloc((*line)[i++], w);
			}
			if ((*line)[i])
				i++;
		}
		while ((*line)[i] && (*line)[i] != ' ' && (*line)[i] != '\\' && (*line)[i] != '\'' && (*line)[i] != '\"')
		{
			w = re_malloc((*line)[i], w);
			i++;
		}
	}
	*line = *line + i;
	return (w);
}

t_list	*line_to_lst(char *line)
{
	t_list	*i_map;
	t_list	*point_list;
	char	*w;

	point_list = NULL;
	while ((w = get_word(&line)))
	{
		i_map = ft_lstnew(w);
		ft_lstadd_back(&point_list, i_map);
	}
	return (point_list);
}

char		**line_to_mas(char *line)
{
	char	**map;
	t_list	*point_list;
	int		size;
	int		i;
	void	*next;

	point_list = line_to_lst(line);
	size = ft_lstsize(point_list);
	if (!(map = (char**)malloc(sizeof(char*) * (size + 1))))
		return (0);
	map[size] = NULL;
	i = 0;
	while (size != i)
	{
		map[i] = point_list->content;
		i++;
		next = point_list->next;
		free(point_list);
		point_list = next;
	}
	return (map);
}
