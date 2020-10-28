/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_give_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 17:45:59 by atomatoe          #+#    #+#             */
/*   Updated: 2020/10/28 18:48:29 by atomatoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void		ft_printf_declares(char **env, int i, int g)
{
	while (env[i][g] != '=')
	{
		write(1, &env[i][g], 1);
		g++;
	}
	write(1, &env[i][g], 1);
	g++;
	write(1, "\"", 1);
	while (env[i][g] != '\0')
	{
		write(1, &env[i][g], 1);
		g++;
	}
	write(1, "\"", 1);
}

static void		ft_printf_declare(char **env)
{
	int		i;
	int		g;

	i = 0;
	while (env[i])
	{
		g = 0;
		write(1, "declare -x ", 11);
		if (ft_strchr(env[i], '='))
			ft_printf_declares(env, i, g);
		else
			ft_putstr(env[i]);
		write(1, "\n", 1);
		i++;
	}
}

static void		ft_sort_declare(t_data *all)
{
	int		i;
	int		g;
	char	**buf;

	i = 0;
	buf = ft_strdup_msv(all->env);
	while (buf[i])
	{
		g = 0;
		while (buf[g])
		{
			if (ft_strcmp(buf[i], buf[g]) == -1)
				ft_str_replace(buf, i, g);
			g++;
		}
		i++;
	}
	ft_printf_declare(buf);
	free_msv(buf);
	buf = NULL;
}

static void		ft_give_exports(t_commands *cmd, t_data *all)
{
	char	**tmp;
	int		count;
	int		i;

	i = 0;
	count = 0;
	if (!(tmp = (char **)malloc(sizeof(char*) *
		(ft_strlen_msv(all->env) + ft_strlen_msv(cmd->arg) + 1))))
		ft_malloc_error();
	while (all->env[count] != NULL)
	{
		if (ft_str_check_uns(all->env[count], cmd->arg) != 1)
		{
			tmp[i] = ft_strdup(all->env[count]);
			i++;
		}
		count++;
	}
	free_msv(all->env);
	all->env = NULL;
	all->env = tmp;
	ft_give_exportss(cmd, all, i);
}

int				ft_give_export(t_commands *cmd, t_data *all)
{
	int		i;

	if ((i = ft_supercheck_arg(cmd->arg)) != 0)
	{
		write(1, "minishell: export: `", 20);
		ft_putstr(cmd->arg[i]);
		write(1, "': not a valid identifier\n", 26);
		free(all->error);
		all->error = ft_strdup("1");
		return (0);
	}
	if (cmd->arg[1] == NULL)
	{
		ft_sort_declare(all);
		return (0);
	}
	ft_give_exports(cmd, all);
	return (0);
}
