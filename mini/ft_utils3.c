/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 18:37:30 by atomatoe          #+#    #+#             */
/*   Updated: 2020/10/29 19:21:58 by atomatoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		ft_supercheck_arg2(int *g, char **arg, int i)
{
	if (ft_isalpha(arg[i][*g]) != 1 && arg[i][*g]
		!= '_' && ft_isdigit(arg[i][*g]) != 1
		&& arg[i][*g] != '=' && arg[i][*g] != '/'
		&& arg[i][*g] != '.')
		return (i);
	(*g)++;
	return (-1);
}

int		ft_fin_check(char **arg)
{
	int i;
	int g;

	i = 1;
	while (arg[i])
	{
		g = 0;
		if (arg[i][0] != '_' && (ft_isalpha(arg[i][0]) != 1))
			return (1);
		while (arg[i][g] != '\0')
		{
			if (ft_isalpha(arg[i][g]) != 1 && arg[i][g]
				!= '_' && ft_isdigit(arg[i][g]) != 1)
				return (i);
			g++;
		}
		i++;
	}
	return (0);
}
