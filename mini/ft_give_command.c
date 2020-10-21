/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_give_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 17:32:30 by atomatoe          #+#    #+#             */
/*   Updated: 2020/10/21 16:18:18 by atomatoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int ft_give_directory(t_data *all, char *command)
{
    int i;
    int count;
    char *adress;

    count = 0;
    i = 4;
    if(!(adress = (char *)malloc(sizeof(char) * ft_strlen(all->env[all->env_path_i]) + ft_strlen(command) + 1)))
        return(-1);
    while(all->env[all->env_path_i][++i] != '\0')
    {
        if(all->env[all->env_path_i][i] == ':')
        {
            i++; // пропускает ':'
            adress[count] = '/';
            adress = ft_strjoin(adress, command);
            if(access(adress, 0) == 0)
            {
                all->file_dir = adress;
                free(adress);
                adress = NULL;
                return(1);
            }
            else
            {
                adress = ft_strzero(adress);
                count = 0;
            }
        }
        adress[count] = all->env[all->env_path_i][i];
        count++;
    }
    free(adress);
    return(0);
}

int ft_give_command(t_data *all, char *command, char **arg)
{
	if(ft_give_directory(all, command) == 0)    // 1 -  исполняемый файл найден, 0 - не найден
    {
        printf("Command not found!\n");
        return(0);
    }
    //printf("adress final = '%s'\n", all->file_dir);
    pid_t pid = fork();
    if(pid < 0)
   	    perror(NULL);
    else if(pid == 0)
	{
		execve(all->file_dir, arg, all->env);
		perror(NULL);
	}
    else
        wait(0);
    return (0);
}
