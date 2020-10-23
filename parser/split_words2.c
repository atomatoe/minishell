/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_words2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarry <skarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 15:47:44 by skarry            #+#    #+#             */
/*   Updated: 2020/10/23 14:49:38 by skarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*re_malloc(char c, char *w)
{
	char	*v;
	int		i;

	if (!w)
	{
		v = (char *)ft_calloc(2, 1);
		v[0] = c;
		v[1] = '\0';
		return (v);
	}
	v = (char *)ft_calloc(ft_strlen(w) + 2, 1);
	i = -1;
	while (w[++i])
		v[i] = w[i];
	v[i++] = c;
	free (w);
	return (v);
}

int		if_backslash(char **line, int *i, char **w, int *er)
{
	if (!((*line)[*i + 1]))
	{
		(*i)++;
		*er = 1;
		return (1);
	}
	*w = re_malloc((*line)[*i + 1], *w);
	*i += 2;
	return (0);
}

int		if_dollar(char *line, t_data *all, char **w, int *er)
{
	int		i;
	int		j;
	char	*var;
	int		num_var;

	i = 1;
	if (!(line[i]))
	{
		*er = 1;
		return (1);
	}
	while (line[i] == 95 || (line[i] > 64 && line[i] < 91) || (line[i] > 96 && line[i] < 123))
		i++;
	var = ft_strtosup(line + 1, i - 1);
	if ((num_var = give_variable(all->env, var)) > -1)
	{
		j = ft_strlen(var) + 1;
		while (all->env[num_var][j])
		{
			*w = re_malloc(all->env[num_var][j], *w);
			j++;
		}
	}
	free(var);
	return (i);
}

int		if_double_quotes(char *line, t_data *all, char **w, int *er)
{
	int		i;

	i = 1;
	while (line[i] && line[i] != '\"')
	{
		if (line[i] == '\\')
		{
			if (if_backslash(&line, &i, w, er))
				return (1);
		}
		else if (line[i] == '$')
			i += if_dollar(line + i, all, w, er);
		else
			*w = re_malloc(line[i++], *w);
	}
	if (line[i])
		i++;
	else
		*er = 1;
	return (i);
}
int		if_single_quotes(char **line, int i, char **w, int *er)
{
	while ((*line)[i++] && (*line)[i] != '\'')
		*w = re_malloc((*line)[i], *w);
	if ((*line)[i])
		i++;
	else
		*er = 1;
	return (i);
}

char	*get_word(char **line, int *er, t_data *all)
{
	char	*w;
	int		i;

	i = 0;
	w = NULL;
	i = skip_space((*line));
	while (((*line)[i] != ' ' && (*line)[i]) || (!w && (*line)[i]))
	{
		if (!w)
			i += skip_space((*line + i));
		if ((*line)[i] == '\\')
			if (if_backslash(line, &i, &w, er))
				break ;
		if ((*line)[i] == '$')
			i += if_dollar((*line) + i, all, &w, er);
		if ((*line)[i] == '\'')
			i = if_single_quotes(line, i, &w, er);
		if ((*line)[i] == '\"')
		{
			i += if_double_quotes((*line) + i, all, &w, er);
			if (*er == 1)
				break ;
		}
		while ((*line)[i] && (*line)[i] != ' ' && (*line)[i] != '\\'
				&& (*line)[i] != '\'' && (*line)[i] != '\"')
		{
			if ((*line)[i] == '$')
				i += if_dollar((*line) + i, all, &w, er);
			else
			{
				w = re_malloc((*line)[i], w);
				i++;
			}
		}
	}
	*line = *line + i;
	return (w);
}
