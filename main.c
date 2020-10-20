/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarry <skarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 16:56:06 by atomatoe          #+#    #+#             */
/*   Updated: 2020/10/20 12:18:52 by skarry           ###   ########.fr       */
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
		cmd = cut_line(line, all);
		//command execution
		free (line);
		free_cmd(cmd);
		line = NULL;
	}
	return (0);
}
