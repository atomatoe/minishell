/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 17:13:10 by atomatoe          #+#    #+#             */
/*   Updated: 2020/10/21 19:00:42 by atomatoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int ft_start (t_commands *cmd, t_data *all)
{
    if(ft_compare_str(cmd->cmd, "pwd") == 1)
        ft_give_pwd(cmd);
    else if(ft_compare_str(cmd->cmd, "env") == 1)
        ft_give_env(cmd, all);
    else if(ft_compare_str(cmd->cmd, "export") == 1)
        ft_give_export(cmd, all);
    else if(ft_compare_str(cmd->cmd, "unset") == 1)
        ft_give_unset(cmd, all);
    else if(ft_compare_str(cmd->cmd, "cd") == 1)
        ft_give_cd(cmd, all);
    // else if(ft_compare_str(cmd->cmd, "ls -la") == 1)
    //     ft_give_unset(cmd, all);  
    return(0);
}
