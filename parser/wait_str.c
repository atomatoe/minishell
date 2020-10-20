/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarry <skarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 12:52:55 by skarry            #+#    #+#             */
/*   Updated: 2020/10/18 13:33:30 by skarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void		wait_str(char **line)
{
	static int	x = 0;

	if (x == 0 && ++x)
		ft_putstr_fd("mini> ", 1);
	else if (x == 1 && x--)
		ft_putstr_fd("shell> ", 1);
	get_next_line(0, line);
}
