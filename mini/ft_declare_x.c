/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_declare_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 12:45:59 by atomatoe          #+#    #+#             */
/*   Updated: 2020/10/24 13:32:42 by atomatoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int ft_creat_declare(t_data *all)
{
    int i;
    char **tmp;

	i = 0;
	if(!(tmp = (char **)malloc(sizeof(char*) * (ft_strlen_msv(all->env) + 1))))
		return (-1);
	while(all->env[i])
	{
		tmp[i] = ft_strdup(all->env[i]);
		i++;
	}
	tmp[i] = NULL;
	all->env_declare = tmp;
	return(0);
}

int ft_str_check_declare(char **arg)
{
    int i;
    int g;

    i = 0;
    while(arg[i])
    {
        g = 0;
        while(arg[i][g] != '\0')
        {
            if(arg[i][g] == '=')
                return(1);
            g++;
        }
        i++;
    }
    return(0);
}

int ft_declare_x(t_commands *cmd, t_data *all)
{
    int i;

    i = 0;
    ft_strlen(cmd->cmd);
    ft_strlen(all->env[0]);
    // while(all->env_declare[i])
    //     printf("%s\n", all->env_declare[i++]);
    return(0);
}