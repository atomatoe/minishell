/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_env_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 17:31:50 by atomatoe          #+#    #+#             */
/*   Updated: 2020/10/17 17:22:42 by atomatoe         ###   ########.fr       */
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
            chdir(ft_env_replace(all->env_home_dir));
        if((ft_compare_str(arg, "./libft/")) == 1)
            chdir("./libft/");
        if((ft_compare_str(arg, "..")) == 1)
        {
            ft_skip_dir(all, all->env_dir);
            all->env_dir = all->env_skip_dir_full;
            chdir(all->env_skip_dir);
        }
    }
}
