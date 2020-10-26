/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_give_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 18:41:07 by atomatoe          #+#    #+#             */
/*   Updated: 2020/10/26 17:02:38 by atomatoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void ft_env_update(t_data *all, char *old_pwd)
{
	char tmp[1000];

	free(all->env[all->env_old_dir_i]);
    all->env[all->env_old_dir_i] = ft_strjoin("OLDPWD=", old_pwd);
	getcwd(tmp, 1000);
	free(all->env[all->env_dir_i]);
	all->env[all->env_dir_i] = ft_strjoin("PWD=", tmp);
}

static char *ft_env_replace_home(t_data *all)
{
    char *tmp;
    int i;
    int j;

    j = 0;
    i = 5;
    if(!(tmp = (char *)malloc(sizeof(char) * (ft_strlen(all->env[all->env_home_dir]) + 1))))
		return (NULL);
    while(all->env[all->env_home_dir][i] != '\0')
    {
        tmp[j] = all->env[all->env_home_dir][i];
        j++;
        i++;
    }
    tmp[j] = '\0';
    return(tmp);
}

int ft_give_cd(t_commands *cmd, t_data *all)
{
    char *tmp;
    char res[1000];

    getcwd(res, 1000);
    if(cmd->arg[1])
        chdir(cmd->arg[1]);
    else
    {
        tmp = ft_env_replace_home(all);
        chdir(tmp);
        free(tmp);
    }
	ft_env_update(all, res);
    return (0);
}
