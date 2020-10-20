/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarry <skarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 16:56:06 by atomatoe          #+#    #+#             */
/*   Updated: 2020/10/20 18:05:02 by skarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	char		*line;
	t_data		all;
	t_commands	*cmd;

	all.env = env;
	while (1)
	{
		wait_str(&line);
		cmd = create_lst(line, all);
		//command execution
		free (line);
		print_lst(cmd);
		free_cmd(cmd);
		line = NULL;
	}
	return (0);
}
