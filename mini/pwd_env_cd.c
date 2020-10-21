/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_env_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 17:31:50 by atomatoe          #+#    #+#             */
/*   Updated: 2020/10/21 16:18:12 by atomatoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void ft_give_pwd(t_commands *cmd)
{
	char tmp[1000];

     cmd->cmd = "pwd";
    if((ft_compare_str(cmd->cmd, "pwd")) == 1)
    {
        getcwd(tmp, 1000);
	    printf("%s\n", tmp);
    }
}

void ft_give_env(t_commands *cmd, t_data *all)
{
    cmd->cmd = "env";

    int i;

    i = 0;
    if((ft_compare_str(cmd->cmd, "env")) == 1)
    {
        while(all->env[i])
		    printf("%s\n", all->env[i++]);
    }
}

void ft_give_cd(t_commands *cmd, t_data *all)
{
    cmd->cmd = "cd";
    char *arg = "..";

    if((ft_compare_str(cmd->cmd, "cd")) == 1)
    {
        if((ft_compare_str(arg, "NULL")) == 1)
            chdir(ft_env_replace_home(all->env_home_dir));
        if((ft_compare_str(arg, "./libft/")) == 1)
            chdir("./libft/");
        if((ft_compare_str(arg, "..")) == 1)
        {
            ft_old_dir(all);
            chdir(all->env_skip_dir);
            ft_env_update(all, all->env_skip_dir, "PWD=", all->env_dir_i);
            ft_env_update(all, all->env_old_dir, "OLDPWD=", all->env_old_dir_i);
        }
    }
}
