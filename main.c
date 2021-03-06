/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarry <skarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 16:56:06 by atomatoe          #+#    #+#             */
/*   Updated: 2020/10/30 12:33:12 by skarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		main(int argc, char **argv, char **env)
{
	char		*line;
	t_data		*all;
	t_commands	*cmd;

	(void)argc;
	(void)argv;
	all = (t_data *)malloc(sizeof(t_data));
	ft_init_struct(all);
	ft_creat_env(all, env);
	signal(SIGINT, ft_signal);
	signal(SIGQUIT, ft_signal_quit);
	while (1)
	{
		wait_str(all, &line);
		cmd = create_lst(line, all);
		free(line);
		line = NULL;
		ft_start(cmd, all);
		free_cmd(cmd);
	}
	return (0);
}
