/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 17:31:50 by atomatoe          #+#    #+#             */
/*   Updated: 2020/10/16 17:57:27 by atomatoe         ###   ########.fr       */
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
    if((ft_compare_str(cmd->cmd, "env")) == 1)
    {
        printf("ENV TEST TEST TEST");
    }
}