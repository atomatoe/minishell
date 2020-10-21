/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 16:56:06 by atomatoe          #+#    #+#             */
/*   Updated: 2020/10/21 16:26:10 by atomatoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"



int		main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;

	char	*line;
	t_commands	cmd;
	t_data all;
	ft_creat_env(&all, env);
	ft_parse_env(&all);

	char *command = "ls";
	char **argument;

	if (!(argument = (char **)malloc(sizeof(char) * 3)))
		    return (0);
	if (!(argument[0] = (char *)malloc(sizeof(char) * 3)))
		    return (0);
	// if (!(argument[1] = (char *)malloc(sizeof(char) * 3)))
	// 	    return (0);
	argument[0] = "ls";
	// argument[1] = "-la";
	line = NULL;
	while (get_next_line(0, &line) > 0)
	{
		if(ft_compare_str(line, "pwd") == 1)
			ft_give_pwd(&cmd);
		if(ft_compare_str(line, "env") == 1)
			ft_give_env(&cmd, &all);
		if(ft_compare_str(line, "cd") == 1)
			ft_give_cd(&cmd, &all);
		if(ft_compare_str(line, "export") == 1)
			ft_give_export(&cmd, &all);
		if(ft_compare_str(line, "unset") == 1)
			ft_give_unset(&cmd, &all);
		if(ft_compare_str(line, "exit") == 1)
			exit(0);
		if(ft_compare_str(line, command) == 1)
			ft_give_command(&all, command, argument);
	}
	free(line);
	printf("ERROR\n");
	return (0);
}
