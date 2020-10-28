/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarry <skarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 16:31:44 by skarry            #+#    #+#             */
/*   Updated: 2020/10/28 11:59:45 by skarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void		init_struct_cmd(t_commands *lst)
{
	lst->cmd = NULL;
	lst->arg = NULL;
	lst->next = NULL;
	lst->pipe = NULL;
	lst->redir = NULL;
	lst->cmd_dir = NULL;
}

size_t		skip_space(char *s)
{
	size_t		i;

	i = 0;
	while (s[i] == ' ')
		i++;
	return (i);
}

void		give_type_direct(char *line, t_commands *s_point, size_t end_cmd)
{
	if (line[end_cmd] == '<')
		s_point->type_redir = 1;
	if (line[end_cmd] == '>')
		s_point->type_redir = 2;
	if (line[end_cmd] == '>' && line[end_cmd + 1] == '>')
		s_point->type_redir = 3;
}

void		write_data(t_commands *s_point, size_t *point,
										char *line, t_data *all)
{
	char	*line2;
	size_t	end_cmd;

	line2 = NULL;
	init_struct_cmd(s_point);
	*point += skip_space(line + *point);
	end_cmd = *point + find_end_cmd(line + *point);
	s_point->invalid = 0;
	s_point->dir_find = 0;
	line2 = ft_strtosup(line + *point, (end_cmd - *point));
	s_point->arg = line_to_mas(line2, &s_point->invalid, all);
	free(line2);
	if (!s_point->arg[0])
		s_point->invalid = 1;
	else
		s_point->cmd = ft_strdup(s_point->arg[0]);
	*point += skip_space(line + *point);
	s_point->type_redir = 0;
	give_type_direct(line, s_point, end_cmd);
	*point = end_cmd + 1;
	if (s_point->type_redir == 3)
		(*point)++;
}

t_commands	*create_lst(char *line, t_data *all)
{
	size_t		point;
	t_commands	*cmd;

	cmd = (t_commands *)ft_calloc(sizeof(t_commands), 1);
	init_struct_cmd(cmd);
	point = 0;
	if (*line)
	{
		write_data(cmd, &point, line, all);
		add_lst(line, cmd, point, all);
		record_redir(cmd, all);
	}
	return (cmd);
}
