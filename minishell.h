/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarry <skarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 16:55:54 by atomatoe          #+#    #+#             */
/*   Updated: 2020/10/16 12:59:21 by skarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

typedef	struct	s_data
{
	char **arg;
	int count;
}				t_data;

# include "libft/libft.h"
# include "parser/parser.h"

#endif
