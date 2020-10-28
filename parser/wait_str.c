/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 12:52:55 by skarry            #+#    #+#             */
/*   Updated: 2020/10/28 18:57:11 by atomatoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void		wait_str(t_data *all, char **line)
{
	static int	x = 0;
	int			flag;

	flag = 0;
	while (!*line)
	{
		if (x == 0 && ++x && flag == 0)
		{
			ft_putstr_fd(_MAG_, 1);
			ft_putstr_fd(BOLD, 1);
			ft_putstr_fd("mini-> ", 1);
			ft_putstr_fd(_DEF_, 1);
		}
		else if (x == 1 && x-- && flag == 0)
		{
			ft_putstr_fd(_YEL_, 1);
			ft_putstr_fd(BOLD, 1);
			ft_putstr_fd("shell> ", 1);
			ft_putstr_fd(_DEF_, 1);
		}
		flag = 0;
		if (!get_next_line(line))
		{
			ft_putstr("  \b\b");
			flag = 1;
			write(1, "\0", 1);
			if (!**line)
			{
				write(1, "exit\n", 5);
				exit(ft_atoi(all->error));
			}
			free(*line);
			*line = NULL;
		}
	}
}
