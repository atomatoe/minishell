/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   record_redir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 19:16:21 by skarry            #+#    #+#             */
/*   Updated: 2020/10/21 16:47:35 by atomatoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void		record_mas_to_mas(char ***m1, char **m2, int start)
{
	int		i;
	int		j;

	i = 0;
	while (m2[i])
	{
		(*m1)[start] = (char *)malloc(ft_strlen(m2[i]) + 1);
		j = 0;
		while (m2[i][j])
		{
			(*m1)[start][j] = m2[i][j];
			j++;
		}
		(*m1)[start][j] = '\0';
		start++;
		i++;
	}
}

void		slip_2_mas(char ***dst, char ***src)
{
	char	**a;
	char	**b;
	size_t	size;

	if (!(*src) || ft_array_size(*src) == 1)
		return ;
	size = ft_array_size(*dst) + ft_array_size(*src);
	a = (char **)malloc(sizeof(char *) * size);
	a[size - 1] = NULL;
	record_mas_to_mas(&a, (*dst), 0);
	record_mas_to_mas(&a, (*src) + 1, ft_array_size(*dst));
	free_str(dst);
	b = (char **)malloc(sizeof(char *) * 2);
	b[1] = NULL;
	b[0] = ft_strdup((*src)[0]);
	size = 0;
	while ((*src)[size])
	{
		free((*src)[size]);
		(*src)[size] = NULL;
		size++;
	}
	free((*src));
	(*src) = b;
	(*dst) = a;
}

void		record_arg(t_commands *pipe, t_commands *redir)
{
	if (redir->redir)
		record_arg(pipe->redir, redir->redir);
	slip_2_mas(&pipe->arg, &redir->arg);
}

void		record_redir(t_commands *cmd)
{
	t_commands	*pipe;
	t_commands	*next;
	t_commands	*redir;

	next = cmd;
	while (next)
	{
		pipe = next;
		while (pipe)
		{
			redir = pipe->redir;
			if (redir)
				record_arg(pipe, redir);
			pipe = pipe->pipe;
		}
		next = next->next;
	}
}
