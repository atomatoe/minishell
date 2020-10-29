/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 18:37:30 by atomatoe          #+#    #+#             */
/*   Updated: 2020/10/29 18:48:22 by atomatoe         ###   ########.fr       */
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
