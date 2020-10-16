/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarry <skarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 16:31:44 by skarry            #+#    #+#             */
/*   Updated: 2020/10/16 17:10:24 by skarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

size_t		skip_space(char *s)
{
	size_t		i;

	i = 0;
	while (s[i] == ' ')
		i++;
	return (i);
}

size_t		find_end_cmmd(char *s)
{
	size_t		i;

	i = 0;
	while (s[i] != '|' && s[i] != ';' && s[i])
		i++;
	return (i);
}

int			check_quotes(char	*line, size_t pointer, size_t end_cmmd)
{
	int		flag;
	int		flag2;

	flag = 0;
	flag2 = 0;
	while (pointer < end_cmmd)
	{
		if (line[pointer] == '\'')
		{
			if (flag)
				flag--;
			else
				flag++;
		}
		if (line[pointer] == '\"')
		{
			if (flag2)
				flag2--;
			else
				flag2++;
		}
		pointer++;
	}
	if (flag || flag2)
		return (1);
	return (0);
}

void		cut_line(char *line)
{
	size_t		pointer;
	size_t		end_cmmd;

	end_cmmd = 0;
	while (line[end_cmmd])
	{
		pointer = skip_space(line);
		end_cmmd = pointer + find_end_cmmd(line + pointer);
		if (check_quotes(line, pointer, end_cmmd))
			printf("invalid line\n");
	}
	// cms = malloc(sizeof(t_commands));
	printf("%zu %zu\n", pointer, end_cmmd);
}
