/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarry <skarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 17:13:10 by atomatoe          #+#    #+#             */
/*   Updated: 2020/10/22 12:47:06 by skarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int ft_start (t_commands *cmd, t_data *all)
{
    if (cmd->cmd)
    {
    if(ft_compare_str(cmd->cmd, "pwd") == 1)
        ft_give_pwd(cmd);
    else if(ft_compare_str(cmd->cmd, "env") == 1)
        ft_give_env(cmd, all);
    else if(ft_compare_str(cmd->cmd, "echo") == 1)
        ft_give_echo(cmd);
    // else if(ft_compare_str(cmd->cmd, "export") == 1)
    //     ft_give_export(cmd, all);
    // else if(ft_compare_str(cmd->cmd, "unset") == 1)
    //     ft_give_unset(cmd, all);
    else if(ft_compare_str(cmd->cmd, "cd") == 1)
        ft_give_cd(cmd, all);
    // else if(ft_compare_str(cmd->cmd, "ls -la") == 1)
    //     ft_give_command(cmd, all);  // добавить в поиск директории исполняемого файла флаг all->flag_command; если директория найдена флаг = 1;
    //                                 // условием запуска этой команды будет наличие флаг = 1;
    }
    return(0);
}
