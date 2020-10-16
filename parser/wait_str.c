/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarry <skarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 12:52:55 by skarry            #+#    #+#             */
/*   Updated: 2020/10/16 13:26:32 by skarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void		wait_str()
{
	t_data	all;
	char	*line;
	int		i;

	ft_putstr_fd("?> ", 1);
	while (get_next_line(0, &line) > 0)
	{
		all.arg = ft_split(line, ' ');
		all.count = ft_array_size(all.arg);
		//ft_valid_arg(line, &all);
		printf("nom of str = %d\n", all.count);
		i = -1;
		while (all.arg[++i])
			printf("command %d = %s\n", i,  all.arg[i]);
		ft_putstr_fd("?> ", 1);
	}
}
