/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarry <skarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 12:53:14 by skarry            #+#    #+#             */
/*   Updated: 2020/10/20 12:16:29 by skarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../minishell.h"
# include "../libft/libft.h"

#define _DEF_	"\x1B[0m"
#define _RED_	"\x1B[31m"
#define _GRN_	"\x1B[32m"
#define _YEL_	"\x1B[33m"
#define _BLU_	"\x1B[34m"
#define _MAG_	"\x1B[35m"
#define _CYN_	"\x1B[36m"
#define _WHT_	"\x1B[37m"

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

typedef	struct			s_data
{
	char				**arg;
	char				**env;
	int					count;
}						t_data;

void				wait_str(char **line);
size_t				ft_array_size(char **ar);
t_commands			*cut_line(char *line, t_data all);
char				*get_cmd(size_t *point, size_t end_cmd, char *line);
void				check_end(char *line, t_commands *s_point);
char				**line_to_mas(char *line);
void				free_cmd(t_commands *cmd);

#endif