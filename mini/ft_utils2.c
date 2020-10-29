/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 17:54:39 by atomatoe          #+#    #+#             */
/*   Updated: 2020/10/29 19:03:56 by atomatoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**ft_str_replace(char **env, int i, int g)
{
	char	*str;

	str = ft_strdup(env[i]);
	free(env[i]);
	env[i] = NULL;
	env[i] = ft_strdup(env[g]);
	free(env[g]);
	env[g] = NULL;
	env[g] = ft_strdup(str);
	free(str);
	str = NULL;
	return (env);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}

int		ft_supercheck_arg(char **arg)
{
	int	i;
	int g;

	i = 1;
	if (arg[i] == NULL)
		return (0);
	while (arg[i])
	{
		if (arg[i][0] != '_' && (ft_isalpha(arg[i][0]) != 1))
			return (i);
		g = 1;
		while (arg[i][g] != '=' && arg[i][g] != '\0')
		{
			if (arg[i][g] != '_' && ft_isalpha(arg[i][g]) != 1
				&& ft_isdigit(arg[i][g]) != 1)
				return (i);
			g++;
		}
		while (arg[i][g] != '\0')
			if ((ft_supercheck_arg2(&g, arg, i) != -1))
				return (i);
		i++;
	}
	return (0);
}

void	ft_signal(int sig)
{
	int	pid;
	int	flag;

	g_status51 = 1;
	pid = waitpid(-1, &flag, WNOHANG);
	if (sig == SIGINT)
	{
		flag = 1;
		ft_putstr_fd("\b\b  \b\b", 1);
		if (pid)
		{
			ft_putstr_fd("\n", 1);
			ft_putstr_fd(_YEL_, 1);
			ft_putstr_fd(BOLD, 1);
			ft_putstr_fd("shell> ", 1);
			ft_putstr_fd(_DEF_, 1);
		}
	}
}

void	ft_signal_quit(int sig)
{
	int	pid;
	int	flag;

	(void)sig;
	pid = waitpid(-1, &flag, WNOHANG);
	if (!pid)
		ft_putendl_fd("Quit: 3", 1);
	else
		ft_putstr_fd("\b\b  \b\b", 1);
}
