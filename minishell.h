/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarry <skarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 16:55:54 by atomatoe          #+#    #+#             */
/*   Updated: 2020/10/16 17:55:28 by skarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include "parser/parser.h"
# include "mini/mini.h"

typedef	struct	s_data
{
	char **arg;
	int count;
}				t_data;

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


#endif
