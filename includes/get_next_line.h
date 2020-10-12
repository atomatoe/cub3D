/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 03:12:53 by atomatoe          #+#    #+#             */
/*   Updated: 2020/10/08 14:42:35 by atomatoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

char		*ft_strdup(const char *str);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strchr(const char *s, int c);
char		*ft_strcpy(char *dst, const char *src);
char		*check(char *bufs, char **line);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlen(const char *b);
int			get_next_line(int fd, char **line);
int			ft_read(int fd, char **remainder, char **line);
int			ft_read_remainder(char **remainder, char **line);
void		*ft_calloc(size_t num, size_t size);
void		*ft_memset(void *src, int g, size_t l);
void		ft_putendl_fd(char *s, int fd);
int			ft_strncmp(const char *s1, const char *s2, size_t i);
void		ft_bzero(void *src, size_t l);

#endif
