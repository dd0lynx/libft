/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddowty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 22:11:47 by ddowty            #+#    #+#             */
/*   Updated: 2018/05/16 00:34:02 by ddowty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <inttypes.h>
# include "get_next_line.h"

int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);

void		ft_bzero(void *p, size_t size);
void		*ft_memalloc(size_t size);
void		*ft_memccpy(void *dst, const void *src, int c, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		ft_memdel(void **ap);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		*ft_memset(void *b, int c, size_t len);

void		ft_putchar(char c);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr(char const *s);
void		ft_putstr_fd(char const *s, int fd);
void		ft_putendl(char const *s);
void		ft_putendl_fd(char const *s, int fd);
void		ft_putnbr(int nb);
void		ft_putnbr_fd(int nb, int fd);
void		ft_putwchar(wchar_t chr);
void		ft_putwstr(wchar_t *chr);

char		*ft_strcat(char *dst, const char *src);
char		*ft_strchr(const char *s, int c);
void		ft_strclr(char *s);
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_strcpy(char *dst, const char *src);
void		ft_strdel(char **as);
char		*ft_strdup(const char *src);
int			ft_strequ(char const *s1, char const *s2);
void		ft_striter(char *s, void (*f)(char *));
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
size_t		ft_strlen(const char *str);
char		*ft_strmap(char const *s, char (*f)(char));
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char		*ft_strncat(char *dst, const char *src, size_t n);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strncpy(char *dst, const char *src, size_t len);
int			ft_strnequ(char const *s1, char const *s2, size_t n);
void		*ft_strnew(size_t size);
char		*ft_strnstr(const char *big, const char *little, size_t len);
char		*ft_strrchr(const char *s, int c);
char		**ft_strsplit(char const *str, char c);
char		*ft_strstr(const char *big, const char *little);
char		*ft_strsub(char const *s, unsigned int start, size_t len);
char		*ft_strtrim(char const *s);

int			ft_atoi(char const *s);
int			ft_tolower(int c);
int			ft_toupper(int c);

#endif
