/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 20:13:18 by skarry            #+#    #+#             */
/*   Updated: 2020/10/25 13:04:58 by atomatoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <string.h>

# define _DEF_	"\x1B[0m"
# define _RED_	"\x1B[31m"
# define _GRN_	"\x1B[32m"
# define _YEL_	"\x1B[33m"
# define _BLU_	"\x1B[34m"
# define _MAG_	"\x1B[35m"
# define _CYN_	"\x1B[36m"
# define _WHT_	"\x1B[37m"
# define BOLD	"\033[1m"

typedef	struct			s_commands
{
	char				*cmd;
	char				*cmd_dir;
	char				**arg;
	int					dir_find;
	int					type_redir;
	int					invalid;
	struct s_commands	*redir;
	struct s_commands	*pipe;
	struct s_commands	*next;
}						t_commands;

typedef	struct	s_data
{
	int		fd1;
	int		fd0;
    char **arg;
    int count;
    char **env;
	char **env_declare;
	int env_home_dir; // index home=/users/atomatoe
	int	env_dir_i; // в какой строке env лежит текущая директория
	int	env_old_dir_i; // в какой строке env лежит oldpwd=
	int env_path_i; // в какой строке лежит PATH=
	int	last_env; // последняя строка env
	char *file_dir; // путь директории для исполняемых файлов ls итд
	char *env_old_dir; // old dir
	char *env_skip_dir; // задняя папка ./users/help/go   - help (задняя папка)
}				t_data;


void				wait_str(char **line);
t_commands			*create_lst(char *line, t_data *all);
void				add_lst(char *line, t_commands *s_point, size_t pointd, t_data *all);
char				**line_to_mas(char *line, int *er, t_data *all);
size_t				skip_space(char *s);
void				free_cmd(t_commands *cmd);
char				*get_word(char **line, int *er, t_data *all);
void				write_data(t_commands *s_point, size_t *point, char *line, t_data *all);
void				print_lst(t_commands *cmd);
void				record_redir(t_commands *cmd, t_data *all);
int					ft_creat_env(t_data *all, char **env);
void				ft_parse_env(t_data *all);
int					give_directory(t_commands *lst, t_data *all);
void				init_struct_cmd(t_commands *lst);
int					give_variable(char **env, char *var);
char				*re_malloc(char c, char *w);
//////// utils:
char 				*ft_strzero(char *str);
char				**ft_strdup_msv(char **str);
int					ft_strlen_msv(char **str);
int					ft_compare_str(char *s1, char *s2);
char				**free_msv(char **str);
////////
int					ft_start (t_commands *cmd, t_data *all);
void				ft_give_pwd(t_commands *cmd);
void				ft_give_env(t_commands *cmd, t_data *all);
int					ft_give_export(t_commands *cmd, t_data *all);
int					ft_give_unset(t_commands *cmd, t_data *all);
int					ft_give_command(t_commands *cmd, t_data *all);
int					ft_give_cd(t_commands *cmd, t_data *all);
int					ft_give_echo(t_commands *cmd);
int					ft_str_check(char *str, char **arg);
int					ft_give_redir(t_commands *cmd, t_data *all);
void				ft_init_struct(t_data *all);
///////
int ft_declare_x(t_commands *cmd, t_data *all);
int ft_str_check_declare(char **arg);
int ft_creat_declare(t_data *all);
char **ft_str_replace(char **env, int i, int g);
int ft_strcmp(char *s1, char *s2);
char *ft_str_union(char *s1, char *s2);
void	do_cmd(t_commands *cmd, t_data *all);
int ft_strcmp_declare(char *s1, char *s2);

#endif
