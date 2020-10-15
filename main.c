/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarry <skarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 16:56:06 by atomatoe          #+#    #+#             */
/*   Updated: 2020/10/15 21:37:28 by skarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// int ft_valid_arg(char *line, t_data *all)
// {
// 	all->count_word;
// }

int		main(void)
{
	char	*line;
	t_data	all;

	while (get_next_line(0, &line) > 0)
	{
		all.arg = ft_split(line, ' ');
		all.count = ft_array_size(all.arg);
		//ft_valid_arg(line, &all);
		printf("nom of str = %d\n", all.count);
		printf("command 1 = %s\n", all.arg[0]);
		printf("command 2 = %s\n", all.arg[1]);
		printf("command 3 = %s\n", all.arg[2]);
		printf("command 4 = %s\n", all.arg[3]);
		printf("command 5 = %s\n", all.arg[4]);
	}
	return (0);
}
