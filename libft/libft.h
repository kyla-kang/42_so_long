/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyukang <kyukang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 22:48:03 by kyukang           #+#    #+#             */
/*   Updated: 2024/09/16 14:46:00 by kyukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>//for write
# include <stdlib.h>//for malloc, free
# include <stdarg.h>//for va_*
# include <unistd.h>//for write

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

int		ft_atoi(const char *str);
void	ft_bzero(void *s, int n);
void	*ft_calloc(size_t num, size_t size);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
char	*ft_itoa(int n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *s);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strncmp(const char *s1, const char *s2, unsigned int n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_tolower(int c);
int		ft_toupper(int c);

//get_next_line
char	*get_next_line(int fd);

//ft_printf
int		ft_printf(const char *str, ...);
int		print_char(char c);
int		print_str(char *str);
int		print_ptr(void *pointer);
int		print_dec(long long num);
int		print_hexa(unsigned long long num, int uppercase);
int		process_specifier(va_list *args, char spec);

#endif
