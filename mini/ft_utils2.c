/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 17:54:39 by atomatoe          #+#    #+#             */
/*   Updated: 2020/10/27 13:05:42 by atomatoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] > s2[i])
			return (1);
		if (s1[i] < s2[i])
			return (-1);
		i++;
	}
	return (0);
}

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

	i = 1;
	if (arg[i] == NULL)
		return (0);
	while (arg[i])
	{
		if (arg[i][0] != '_' && (ft_isalpha(arg[i][0]) != 1))
			return (i);
		i++;
	}
	return (0);
}

void	ft_signal(int sig)
{
	int	pid;
	int	flag;

	pid = waitpid(-1, &flag, WNOHANG);
	if (sig == SIGINT)
	{
		flag = 1;
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
}
