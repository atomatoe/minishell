/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 15:29:10 by skarry            #+#    #+#             */
/*   Updated: 2020/10/26 13:47:42 by atomatoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char *add_char_to_str(char *str, char c, int *size)
{
	char *res;
	int i = 0;

	if (!(res = (char *)malloc(sizeof(char) * (*size) + 1)))
		return (NULL);
	while (str && i < (*size))
	{
		res[i] = str[i];
		i++;
	}
	free(str);
	str = NULL;
	res[*size] = c;
	*size += 1;
	return (res);
}

int get_next_line(char **line)
{
	char buffer[1];
	int bytes;
	int size;
	char *tmp;

	size = 0;
	tmp = NULL;
	while ((bytes = read(0, buffer, 1)) > 0)
	{
		if (buffer[0] == '\n')
		{
			if (!(tmp = add_char_to_str(tmp, '\0', &size)))
				return (-1);
			*line = tmp;
			return (1);
		}
		if (!(tmp = add_char_to_str(tmp, buffer[0], &size)))
			return (-1);
	}
	if (bytes == -1)
	{
		if (tmp)
			free(tmp);
		return (-1);
	}
	else if (bytes == 0)
	{
		if (!tmp)
		{
			*line = (char *)malloc(1);
			*line[0] = '\0';
			return (0);
		}
		else
		{
			tmp = add_char_to_str(tmp, '\0', &size);
			*line = tmp;
			return (0);
		}
	}
	return (-1);
}
