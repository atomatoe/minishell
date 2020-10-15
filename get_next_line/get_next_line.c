/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 14:38:59 by atomatoe          #+#    #+#             */
/*   Updated: 2020/10/11 17:11:09 by atomatoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_read_remainder(char **remainder, char **line)
{
	char *point;
	char *temp;

	if ((point = ft_strchr(*remainder, '\n')))
	{
		*point = '\0';
		if (!(*line = ft_strjoin(*line, *remainder)))
			return (-1);
		point++;
		temp = *remainder;
		*remainder = ft_strdup(point);
		free(temp);
		return ((*remainder) ? 1 : -1);
	}
	else
	{
		*line = ft_strjoin(*line, *remainder);
		free(*remainder);
		*remainder = NULL;
		return ((*line) ? 0 : -1);
	}
}

int		ft_read(int fd, char **remainder, char **line)
{
	char		*point;
	int			byte;
	char		*buf;

	if (!(buf = (char *)malloc(1 + 1)))
		return (-1);
	while ((byte = read(fd, buf, 1) > 0))
	{
		buf[byte] = '\0';
		if ((point = ft_strchr(buf, '\n')))
		{
			*point++ = '\0';
			if (!(*line = ft_strjoin(*line, buf))
				|| !(*remainder = ft_strdup(point)))
				return (-1);
			free(buf);
			return (1);
		}
		if (!(*line = ft_strjoin(*line, buf)))
			return (-1);
	}
	free(buf);
	return (byte);
}

int		get_next_line(int fd, char **line)
{
	static char *remainder = NULL;
	int			tmp;

	*line = ft_strdup("");
	if (fd < 0 || 1 <= 0 || !line)
		return (-1);
	if (remainder)
		if (ft_read_remainder(&remainder, line) == 1)
			return (1);
	if ((tmp = ft_read(fd, &remainder, line)) == 1 || tmp == -1)
	{
		if (tmp == -1)
			free(remainder);
		return (tmp);
	}
	free(remainder);
	return (0);
}
