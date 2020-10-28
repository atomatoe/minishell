/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_words3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarry <skarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 12:20:43 by skarry            #+#    #+#             */
/*   Updated: 2020/10/28 20:02:11 by skarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int			if_basesim(char *line, int i, t_data *all, char **w)
{
	while (line[i] && line[i] != ' ' && line[i] != '\\'
		&& line[i] != '\'' && line[i] != '\"')
	{
		if (line[i] == '$')
			i += if_dollar(line + i, all, w);
		else
		{
			*w = re_malloc(line[i], *w);
			i++;
		}
	}
	return (i);
}

int			ft_find_equally(char *str, char *str2)
{
	int i;

	i = 0;
	while (str[i] == str2[i])
	{
		i++;
		if (str[i] == '=' || str[i] == '\0')
			return (0);
	}
	return (1);
}
