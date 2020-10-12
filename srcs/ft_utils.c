/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 18:58:04 by atomatoe          #+#    #+#             */
/*   Updated: 2020/10/08 15:28:36 by atomatoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t			i;
	unsigned char	*str3;
	unsigned char	*str4;

	str3 = (unsigned char *)str1;
	str4 = (unsigned char *)str2;
	i = 0;
	while (i < n)
	{
		if (str3[i] != str4[i])
			return (str3[i] - str4[i]);
		i++;
	}
	return (0);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s)
		while (s[i] != '\0')
		{
			write(fd, &s[i], 1);
			i++;
		}
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len_s;
	char	*result_str;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	len_s = ft_strlen(s1);
	while (len_s && ft_strchr(set, s1[len_s]))
	{
		len_s--;
	}
	result_str = ft_substr((char*)s1, 0, len_s + 1);
	return (result_str);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	f;
	char	*str;

	if (!s)
		return (NULL);
	j = 0;
	i = 0;
	f = ft_strlen(&(s[start]));
	if (len > f)
		len = f;
	if (!(str = (char *)malloc(sizeof(char) * (1 + len))))
		return (NULL);
	while (s[i])
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = '\0';
	return (str);
}
