/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarry <skarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 18:38:41 by skarry            #+#    #+#             */
/*   Updated: 2020/10/16 21:05:35 by skarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char		*get_cmd(size_t *point, size_t end_cmd, char *line)
{
	char	*res;
	int		i;
	size_t	repoint;

	i = 0;
	while (line[*point + i] != ' ' && (*point + i) < end_cmd)
		i++;
	res = (char *)malloc(i + 1);
	res[i] = '\0';
	repoint = i;
	while (--i >= 0)
	{
		res[i] = line[*point + i];
	}
	*point += repoint;
	return (res);
}

void		check_end(char *line, t_commands **s_point)
{
	t_commands	*s_point2;

	s_point2 = NULL;
	(*s_point)->next = NULL;
	(*s_point)->pipe = NULL;
	(*s_point)->redir = NULL;
	if (*line == '|')
	{
		s_point2 = (t_commands *)malloc(sizeof(t_commands));
		(*s_point)->pipe = s_point2;
		(*s_point) = s_point2;
	}
	if (*line == ';')
	{
		s_point2 = (t_commands *)malloc(sizeof(t_commands));
		(*s_point)->next = s_point2;
		(*s_point) = s_point2;
	}
	if (*line == '>' && *line == '<')
	{
		s_point2 = (t_commands *)malloc(sizeof(t_commands));
		(*s_point)->redir = s_point2;
		(*s_point) = s_point2;
	}
}
