/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_give_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 17:32:30 by atomatoe          #+#    #+#             */
/*   Updated: 2020/10/23 13:34:43 by atomatoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int ft_give_command(t_commands *cmd, t_data *all)
{
    pid_t pid = fork();
    if(pid < 0)
   	    perror(NULL);
    else if(pid == 0)
	{
		execve(cmd->cmd_dir, cmd->arg, all->env);
		perror(NULL);
	}
    else
        wait(0);
    return (0);
}
