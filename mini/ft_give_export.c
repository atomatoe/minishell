/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_give_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 17:45:59 by atomatoe          #+#    #+#             */
/*   Updated: 2020/10/27 13:34:25 by atomatoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void		ft_printf_declare(char **env)
{
	int	i;
	int	g;

	i = 0;
	while (env[i])
	{
		g = 0;
		write(1, "declare -x ", 11);
		if (ft_strchr(env[i], '='))
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

int				ft_give_export(t_commands *cmd, t_data *all)
{
	int		i;
	int		g;
	int		count;
	char	**tmp;

	count = 0;
	g = 1;
	if ((i = ft_supercheck_arg(cmd->arg)) != 0)
	{
		write(1, "minishell: export: `", 20);
		ft_putstr(cmd->arg[i]);
		write(1, "': not a valid identifier\n", 26);
		free(all->error);
		all->error = ft_strdup("1");
		return (0);
	}
	i = 0;
	if (cmd->arg[1] == NULL)
	{
		ft_sort_declare(all);
		return (0);
	}
	if (!(tmp = (char **)malloc(sizeof(char*) *
		(ft_strlen_msv(all->env) + ft_strlen_msv(cmd->arg) + 1))))
		return (-1);
	while (all->env[i] != NULL)
	{
		if (ft_str_check_uns(all->env[count], cmd->arg) != 1)
		{
			tmp[i] = ft_strdup(all->env[count]);
			i++;
		}
		count++;
	}
	while (cmd->arg[g])
	{
		tmp[i] = ft_strdup(cmd->arg[g]);
		i++;
		g++;
	}
	tmp[i] = NULL;
	free_msv(all->env);
	all->env = NULL;
	all->env = tmp;
	return (0);
}
