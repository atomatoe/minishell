/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 16:56:06 by atomatoe          #+#    #+#             */
/*   Updated: 2020/10/17 16:27:22 by atomatoe         ###   ########.fr       */
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

int		main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;

	char	*line;
	t_commands	cmd;
	t_data all;

	ft_parse_env(&all, &*env);
	while (get_next_line(0, &line) > 0)
	{
		if(ft_compare_str(line, "pwd") == 1)
			ft_give_pwd(&cmd);
		if(ft_compare_str(line, "env") == 1)
			ft_give_env(&cmd, &all);
		if(ft_compare_str(line, "cd") == 1)
			ft_give_cd(&cmd, &all);
	}
	printf("ERROR\n");
	return (0);
}
