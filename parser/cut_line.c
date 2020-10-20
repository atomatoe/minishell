/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarry <skarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 16:31:44 by skarry            #+#    #+#             */
/*   Updated: 2020/10/20 12:33:36 by skarry           ###   ########.fr       */
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

size_t		find_end_cmd(char *s)
{
	size_t		i;

	i = 0;
	while (s[i] != '|' && s[i] != ';' && s[i] != '<' && s[i] != '>' && s[i])
		i++;
	return (i);
}

int			check_quotes(char	*line, size_t point, size_t end_cmd)
{
	int		flag;
	int		flag2;

	flag = 0;
	flag2 = 0;
	while (point < end_cmd)
	{
		if (line[point] == '\'')
		{
			if (flag)
				flag--;
			else
				flag++;
		}
		if (line[point] == '\"')
		{
			if (flag2)
				flag2--;
			else
				flag2++;
		}
		point++;
	}
	if (flag || flag2)
		return (1);
	return (0);
}

void		write_lst(t_commands *s_point, size_t *point, size_t *end_cmd, char *line)
{
	char		*line2;

	line2 = NULL;
	s_point->arg = NULL;
	s_point->next = NULL;
	s_point->pipe = NULL;
	s_point->redir = NULL;
	*point += skip_space(line);
	*end_cmd = *point + find_end_cmd(line + *point);
	s_point->invalid = check_quotes(line, *point, *end_cmd);
	line2 = ft_strtosup(line + *point, (*end_cmd - *point));
	s_point->arg = line_to_mas(line2);
	// s_point->cmd = s_point->arg[0];
	free(line2);
	*point += skip_space(line + *point);
	// printf("cmd: [%s]\n", s_point->cmd);
	*point = 0;
	while (s_point->arg[*point])
	{
		printf("arg[%s]\n", s_point->arg[*point]);
		(*point)++;
	}
	s_point->type_redir = 0;
	if (line[*end_cmd] == '<')
		s_point->type_redir = 1;
	if (line[*end_cmd] == '>')
		s_point->type_redir = 2;
	if (line[*end_cmd] == '>' && line[*end_cmd + 1] == '>')
		s_point->type_redir = 3;
	check_end(line + *end_cmd, s_point);
	printf("type_redir: %d\n", s_point->type_redir);
	printf("invalid: %d\n\n", s_point->invalid);
	*point = *end_cmd + 1;
	if (s_point->type_redir == 3)
		(*point)++;
}

t_commands		*cut_line(char *line, t_data all)
{
	size_t		point;
	size_t		end_cmd;
	t_commands	*cmd;

	cmd = (t_commands *)malloc(sizeof(t_commands));
	cmd->arg = NULL;
	cmd->next = NULL;
	cmd->pipe = NULL;
	cmd->redir = NULL;
	point = 0;
	end_cmd = 0;
	while (line[end_cmd])
		write_lst(cmd, &point, &end_cmd, line);
	return (cmd);
}
