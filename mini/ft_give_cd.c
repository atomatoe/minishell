/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_give_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 18:41:07 by atomatoe          #+#    #+#             */
/*   Updated: 2020/10/21 19:00:36 by atomatoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// static char *ft_env_replace_home(t_data *all)
// {
//     printf("%s\n", all->env[all->env_home_dir]);
//     return("NULL");
// }

int ft_give_cd(t_commands *cmd, t_data *all)
{
    // char *tmp;

    // if(!(tmp = (char *)malloc(sizeof(char) * ft_strlen(all->env[all->env_home_dir]) + 1)))
	// 	return (-1);
    ft_strlen(all->env[0]);
    if(cmd->arg[1])
        chdir(cmd->arg[1]);
    // else
    // {
    //     //tmp = ft_env_replace_home(all);
    //     chdir(tmp);
    // }
    return (0);
}
