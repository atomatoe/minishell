/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 16:56:06 by atomatoe          #+#    #+#             */
/*   Updated: 2020/10/16 17:57:36 by atomatoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_compare_str(char *s1, char *s2)
{
	int i;

	i = 0;
	while(s1[i] == s2[i])
	{
		i++;
		if(s1[i] == '\0' && s2[i] == '\0')
			return (1);
	}
	return (-1);
}

int		main(void)
{
	char	*line;
	t_commands	cmd;
	t_data all;
	int i = 0;

	while (get_next_line(0, &line) > 0)
	{
		if(ft_compare_str(line, "pwd") == 1)
			ft_give_pwd(&cmd);
		if(ft_compare_str(line, "env") == 1)
			ft_give_env(&cmd, &all);
	}
	printf("ERROR\n");
	return (0);
}
