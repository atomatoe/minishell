/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarry <skarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 12:52:55 by skarry            #+#    #+#             */
/*   Updated: 2020/10/20 19:10:42 by skarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void		wait_str(char **line)
{
	static int	x = 0;

	if (x == 0 && ++x)
	{
		ft_putstr_fd(_MAG_, 1);
		ft_putstr_fd(BOLD, 1);
		ft_putstr_fd("mini-> ", 1);
		ft_putstr_fd(_DEF_, 1);
	}
	else if (x == 1 && x--)
	{
		ft_putstr_fd(_YEL_, 1);
		ft_putstr_fd(BOLD, 1);
		ft_putstr_fd("shell> ", 1);
		ft_putstr_fd(_DEF_, 1);
	}
	get_next_line(0, line);
}
