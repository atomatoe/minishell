/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarry <skarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 12:52:55 by skarry            #+#    #+#             */
/*   Updated: 2020/10/16 16:28:42 by skarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void		wait_str(char **line)
{
	t_data	all;
	int		i;

	ft_putstr_fd("?> ", 1);
	get_next_line(0, line);
	all.arg = ft_split(*line, ' ');
	all.count = ft_array_size(all.arg);
	printf("nom of str = %d\n", all.count);
	i = -1;
	while (all.arg[++i])
		printf("command %d = %s\n", i,  all.arg[i]);
}
