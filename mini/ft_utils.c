#include "minishell.h"

char *ft_strzero(char *str)
{
    int i;

    i = 0;
    while(str[i] != '\0')
    {
        str[i] = '\0';
        i++;
    }
    return(str);
}

char **ft_strdup_msv(char **str)
{
	char **tmp;
	int count;

	count = 0;
	while(str[count])
		count++;
	if(!(tmp = (char **)malloc(sizeof(char*) * (count + 1))))
		return (NULL);
	count = 0;
	while(str[count])
	{
		tmp[count] = str[count];
		count++;
	}
	free(str);
	return(tmp);
}

int ft_strlen_msv(char **str)
{
	int i;

	i = 0;
	while(str[i])
		i++;
	return(i);
}

int ft_compare_str(char *s1, char *s2)
{
	int i;

	i = 0;
	while(s1[i] == s2[i])
	{
		i++;
		if(s1[i] == '\0' && s2[i] == '\0')
			return (1);
	}
	return (-1);
}

int ft_str_check(char *str, char **arg)
{
	int i;
	int count;
	char *tmp;

	if(!(tmp = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1))))
		return (-1);
	count = 0;
	while(str[count] != '=')
	{
		tmp[count] = str[count];
		count++;
	}
	i = ft_strlen_msv(arg);
	count = 0;
	while(i != 0)
	{
		if(ft_compare_str(tmp, arg[count]) == 1)
		{
			free(tmp);
			tmp = NULL;
			return(1);
		}
		i--;
		count++;
	}
	free(tmp);
	tmp = NULL;
	return (0);
}

char **free_msv(char **str)
{
    int i;

    i = 0;
    while (str[i])
    {
        free(str[i]);
		str[i] = NULL;
        i++;
    }
    free(str);
    str = NULL;
    return (str);
}
