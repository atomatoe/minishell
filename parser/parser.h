/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarry <skarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 12:53:14 by skarry            #+#    #+#             */
/*   Updated: 2020/10/17 11:16:01 by skarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../minishell.h"
# include "../libft/libft.h"

typedef	struct			s_commands
{
	char				*cmd;
	char				**arg;
	int					type_redir;
	int					invalid;
	struct s_commands	*redir;
	struct s_commands	*pipe;
	struct s_commands	*next;
}						t_commands;

void				wait_str(char **line);
size_t				ft_array_size(char **ar);
void				cut_line(char *line, t_commands *cmd);
char				*get_cmd(size_t *point, size_t end_cmd, char *line);
void				check_end(char *line, t_commands **s_point);
char				**split_for_mini(char const *s, char c);

#endif