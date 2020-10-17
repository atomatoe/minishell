/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 16:55:54 by atomatoe          #+#    #+#             */
/*   Updated: 2020/10/17 16:29:52 by atomatoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>

# include "./libft/libft.h"
# include "./get_next_line/get_next_line.h"

typedef	struct			s_commands
{
	char				*cmd; // ls
	char				**arg; // ls -la
	int					type_redir; // 0 = NULL     1 = <    2 = >      3 = >>
	char				*redir; // строка куда идет редирект (файл например) (fd)
	int					invalid; // 0 - валидная команда    1 - невалидная команда
	struct s_commands	*pipe;   // ссылка на команду пайпа
	struct s_commands	*next;
}						t_commands;

typedef	struct	s_data
{
    char **arg;
    int count;
    char **env;
	char *env_home_dir; // для cd без аргументов
	char *env_dir; // текущяя директория (pwd)
	int	count_dir;
	char *env_skip_dir;  // для cd ..  
	char *env_skip_dir_full; // skip dir вместе с PWD=
}				t_data;

int ft_compare_str(char *s1, char *s2);
void ft_give_pwd(t_commands *cmd);
void ft_give_env(t_commands *cmd, t_data *all);
void ft_give_cd(t_commands *cmd, t_data *all);
char *ft_env_replace(char *str);
void ft_parse_env(t_data *all, char **env);
int ft_skip_dir(t_data *all, char *str);

#endif
