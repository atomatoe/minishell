/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarry <skarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 16:31:44 by skarry            #+#    #+#             */
/*   Updated: 2020/10/22 14:25:00 by skarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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

void		write_data(t_commands *s_point, size_t *point, size_t *end_cmd, char *line)
{
	char		*line2;

	line2 = NULL;
	s_point->cmd = NULL;
	s_point->arg = NULL;
	s_point->cmd_dir = NULL;
	s_point->next = NULL;
	s_point->pipe = NULL;
	s_point->redir = NULL;

	*point += skip_space(line + *point);
	*end_cmd = *point + find_end_cmd(line + *point);

	s_point->invalid = 0;
	s_point->dir_find = 0;
	line2 = ft_strtosup(line + *point, (*end_cmd - *point));
	s_point->arg = line_to_mas(line2, &s_point->invalid);
	free(line2);
	s_point->cmd = ft_strdup(s_point->arg[0]);
	if (!s_point->arg[0])
		s_point->invalid = 1;
	*point += skip_space(line + *point);
	s_point->type_redir = 0;
	if (line[*end_cmd] == '<')
		s_point->type_redir = 1;
	if (line[*end_cmd] == '>')
		s_point->type_redir = 2;
	if (line[*end_cmd] == '>' && line[*end_cmd + 1] == '>')
		s_point->type_redir = 3;
	*point = *end_cmd + 1;
	if (s_point->type_redir == 3)
		(*point)++;
}

t_commands		*create_lst(char *line, t_data *all)
{
	size_t		point;
	size_t		end_cmd;
	t_commands	*cmd;

	cmd = (t_commands *)malloc(sizeof(t_commands));
	cmd->cmd = NULL;
	cmd->arg = NULL;
	cmd->next = NULL;
	cmd->pipe = NULL;
	cmd->redir = NULL;
	point = 0;
	end_cmd = 0;
	if (*line)
	{
		write_data(cmd, &point, &end_cmd, line);
		add_lst(line, cmd, point, end_cmd);
		record_redir(cmd, all);
	}
	return (cmd);
}
