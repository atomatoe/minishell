/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 12:52:55 by skarry            #+#    #+#             */
/*   Updated: 2020/10/27 13:31:51 by atomatoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void		wait_str(t_data *all, char **line)
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
	if(!get_next_line(line))
	{
		write(1, "exit\n", 5);
		exit(ft_atoi(all->error));
	}
}
