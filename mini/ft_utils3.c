/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 16:27:49 by atomatoe          #+#    #+#             */
/*   Updated: 2020/10/25 16:49:48 by atomatoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void ft_error_uns_exp(t_commands *cmd)
{
    int i;

    i = 1;
    ft_putstr("minishell: ");
    ft_putstr(cmd->cmd);
    write(1, ": ", 2);
    while(cmd->arg[i])
    {
        write(1, "`", 1);
        ft_putstr(cmd->arg[i]);
        write(1, "': not a valid identifier\n", 26);
        i++;
    }
}

int ft_arg_alpha(t_commands *cmd)
{
    int i;
    int count;

    count = 1;
    while(cmd->arg[count])
    {
        i = 0;
        while(cmd->arg[count][i] != '\0')
        {
            if(ft_isalpha(cmd->arg[count][i]) == 0 && !ft_strchr(cmd->arg[count], '='))
                return(0);
            i++;
        }
        count++;
    }
    return(1);
}

int ft_valid_argument(t_commands *cmd)
{
    if(ft_compare_str(cmd->cmd, "unset") == 1 || ft_compare_str(cmd->cmd, "export") == 1)
    {
        if(ft_arg_alpha(cmd) == 0)
        {
            ft_error_uns_exp(cmd);
            return(1);
        }
    }
    return(0);
}
