/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 16:56:06 by atomatoe          #+#    #+#             */
/*   Updated: 2020/10/15 18:08:57 by atomatoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_give_memory(char *line, t_data *all)
{
	int		i;
	int		count_word;

	i = 0;
	all->count = 0;
	while (line[i] != '\0')
	{
		count_word = 0;
		while(line[i] == ' ' && line[i] != '\0')
			i++;
		if(line[i] != ' ' && line[i] != '\0')
		{
			if(!(all->arg = (char **)realloc(all->arg, 1)))
				return (-1);
			while(line[i] != ' ' && line[i] != '\0') // как только встретил слово
			{
				i++;
				count_word++;
			}
			if(!(all->arg[all->count] = (char *)malloc(count_word + 1)))
					return (-1);
			all->count++;
		}
		i++;
	}
	return (0);
}

int	ft_parse(char *line, t_data *all)
{
	int i;
	int f;
	int count;

	count = 0;
	i = 0;
	while(line[i] != '\0')
	{
		f = 0;
		while(line[i] == ' ' && line[i] != '\0')
			i++;
		while(line[i] != ' ' && line[i] != '\0')
		{
			all->arg[count][f] = line[i];
			f++;
			i++;
		}
		count++;
	}
	return (0);
}

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
		ft_give_memory(line, &all);
		ft_parse(line, &all);
		//ft_valid_arg(line, &all);
		printf("count = %d\n", all.count);
		printf("command 1 = %s\n", all.arg[0]);
		printf("command 2 = %s\n", all.arg[1]);
		printf("command 3 = %s\n", all.arg[2]);
		printf("command 4 = %s\n", all.arg[3]);
		printf("command 5 = %s\n", all.arg[4]);
	}
	return (0);
}
