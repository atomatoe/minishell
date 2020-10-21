/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 16:55:54 by atomatoe          #+#    #+#             */
/*   Updated: 2020/10/21 16:38:29 by atomatoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>

# include "../libft/libft.h"

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
	int	env_dir_i; // в какой строке env лежит текущая директория
	int	env_old_dir_i; // в какой строке env лежит oldpwd=
	int env_path_i; // в какой строке лежит PATH=
	int	last_env; // последняя строка env
	char *file_dir; // путь директории для исполняемых файлов ls итд
	char *env_old_dir; // old dir
	char *env_skip_dir; // задняя папка ./users/help/go   - help (задняя папка)
}				t_data;

int ft_creat_env(t_data *all, char **env);
int ft_compare_str(char *s1, char *s2);
void ft_give_pwd(t_commands *cmd);
void ft_give_env(t_commands *cmd, t_data *all);
void ft_give_cd(t_commands *cmd, t_data *all);
char *ft_env_replace_home(char *str);
void ft_parse_env(t_data *all);
int ft_old_dir(t_data *all);
int ft_env_update(t_data *all, char *str, char *arg, int count); // обновляет env
int ft_give_command(t_data *all, char *command, char **arg); // для вызова стандартных команд bash
int ft_give_export(t_commands *cmd, t_data *all); // для команды export 
char *ft_strzero(char *str); // аналог ft_bzero
int ft_give_unset(t_commands *cmd, t_data *all);
int ft_check_str(char *str, char *arg);
int ft_str_check(char *str, char **arg);
char **ft_strdup_msv(char **str); // strdup **char
int ft_strlen_msv(char **str); // strlen **char
char **free_msv(char **str);

#endif
