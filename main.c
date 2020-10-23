/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarry <skarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 16:56:06 by atomatoe          #+#    #+#             */
/*   Updated: 2020/10/23 16:07:53 by skarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void ft_init_struct(t_data *all)
{
    all->arg = NULL;
	all->env = NULL;
    all->count = 0;
	all->env_home_dir = 0;
	all->env_dir = NULL;
	all->env_dir_i = 0;
	all->env_old_dir_i = 0;
	all->env_path_i = 0;
	all->last_env = 0;
	all->file_dir = NULL;
	all->env_old_dir = NULL;
	all->env_skip_dir = NULL;
}

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
	while (1)
	{
		wait_str(&line);
		cmd = create_lst(line, all);
		free (line);
		line = NULL;
		ft_start(cmd, all);
		print_lst(cmd);
		free_cmd(cmd);
	}
	return (0);
}

/*
Баги Ани:
	1. echo "" "" "" "" "" "" "" > test "" "" "" >> test2 | cat -e
	2. echo test "test" "" "
	3. |||;\\:>>><<<<<>>><<<>;;;;;||||
	4. sdffsadas; sdafbsa; fsdasadfbd;
	5. gfdsafgdbs > gfbnbxzdsfb > gfdsafb >
*/
