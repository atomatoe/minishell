/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 19:52:23 by atomatoe          #+#    #+#             */
/*   Updated: 2020/08/08 18:56:35 by atomatoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <ctype.h>

int		ft_putstr(char *s, size_t len);
void	ft_putchar(int c);
void	ft_bzero (void *src, size_t l);
void	*ft_memccpy(void *dest, const void *src, int c, size_t n);
void	*ft_memchr (const void *str, int s, size_t n);
void	*ft_memcpy (void *dest, const void *src, size_t g);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset (void *src, int g, size_t l);
size_t	ft_strlcat (char *dst, const char *src, size_t size);
size_t	ft_strlcpy (char *dst, const char *src, size_t size);
size_t	ft_strlen (const char *b);
int		ft_memcmp (const void *str1, const void *str2, size_t n);
int		ft_atoi (const char *nptr);
int		ft_isalnum (int a);
int		ft_isalpha (int a);
int		ft_isascii (int a);
int		ft_isdigit (int a);
int		ft_isprint (int a);
char	*ft_tolower(char *str);
int		ft_toupper (int a);
int		ft_strncmp (const char *s1, const char *s2, size_t i);
char	*ft_strchr(const char *s, int c);
char	*ft_strnstr (const char *str1, const char *str2, size_t k);
char	*ft_strrchr(const char *s, int c);
char	*ft_strdup (const char *str);
void	*ft_calloc (size_t num, size_t size);
char	*ft_itoa(int nb);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(const char *s, unsigned int start, size_t len);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);

#endif
