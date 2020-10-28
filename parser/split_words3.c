/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_words3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarry <skarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 12:20:43 by skarry            #+#    #+#             */
/*   Updated: 2020/10/28 12:34:37 by skarry           ###   ########.fr       */
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
