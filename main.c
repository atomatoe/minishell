/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarry <skarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 16:56:06 by atomatoe          #+#    #+#             */
/*   Updated: 2020/10/26 13:39:22 by skarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;

	char		*line;
	t_data		*all;
	t_commands	*cmd;

	all = (t_data *)malloc(sizeof(t_data));
	ft_init_struct(all);
	ft_creat_env(all, env);
	//signal(SIGINT, SIG_IGN);
	while (1)
	{
		wait_str(&line);
		cmd = create_lst(line, all);
		free (line);
		line = NULL;
		ft_start(cmd, all);
		// print_lst(cmd);
		free_cmd(cmd);
	}
	return (0);
}

/*
	Валидация аргументов в export и unset (1 символ буква либо _  (не isdigit))	
*/
