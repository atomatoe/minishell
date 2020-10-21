/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_give_pwd_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 17:19:07 by atomatoe          #+#    #+#             */
/*   Updated: 2020/10/21 19:00:40 by atomatoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void ft_give_env(t_commands *cmd, t_data *all)
{
    ft_strlen(cmd->cmd);
    ft_strlen(all->env[0]);
    int i;

    i = 0;
    while(all->env[i])
		printf("%s\n", all->env[i++]);
}

void ft_give_pwd(t_commands *cmd)
{
	ft_strlen(cmd->cmd);
    char tmp[1000];
    getcwd(tmp, 1000);
	printf("%s\n", tmp);
}
