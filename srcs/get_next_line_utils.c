/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 03:12:53 by atomatoe          #+#    #+#             */
/*   Updated: 2020/10/08 15:28:40 by atomatoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

size_t		ft_strlen(const char *b)
{
	int	a;

	a = 0;
	while (b[a] != '\0')
		a++;
	return (a);
}

size_t		ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (!src || !dst)
	{
		if (src)
			return (ft_strlen(src));
		return (0);
	}
	if (!size)
		return (ft_strlen(src));
	while (src[i] != '\0' && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;
	size_t	len2;

	i = 0;
	len = ft_strlen(dst);
	len2 = ft_strlen(src);
	if (size <= len)
		return (size + len2);
	while (dst[i] != '\0' && i < (size - 1))
		i++;
	while (*src && i < size - 1)
	{
		dst[i] = *src;
		i++;
		src++;
	}
	dst[i] = '\0';
	return (len + len2);
}

char		*ft_strjoin(char *s1, char *s2)
{
	char		*s3;
	size_t		size1;
	size_t		size2;

	if (!s1 || !s2)
	{
		free(s2);
		return (NULL);
	}
	if (!s1 || (ft_strlen(s1) == 0))
	{
		free(s1);
		return (ft_strdup(s2));
	}
	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	if (!(s3 = (char*)malloc(sizeof(char) * (size1 + size2 + 1))))
	{
		free(s2);
		return (NULL);
	}
	ft_strlcpy(s3, s1, (size1 + 1));
	ft_strlcat(s3, s2, (size1 + size2 + 1));
	free(s1);
	return (s3);
}

char		*ft_strdup(const char *str)
{
	int		i;
	char	*str2;

	i = 0;
	while (str[i] != '\0')
		i++;
	if (!(str2 = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		str2[i] = str[i];
		i++;
	}
	str2[i] = '\0';
	return (str2);
}
