/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 19:49:50 by atomatoe          #+#    #+#             */
/*   Updated: 2020/10/08 15:28:34 by atomatoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

int	ft_strncmp(const char *s1, const char *s2, size_t i)
{
	size_t	n;

	n = 0;
	while (n != i && s1[n] != '\0' && s2[n] != '\0')
	{
		if (s1[n] != s2[n])
		{
			return ((unsigned char)s1[n] - (unsigned char)s2[n]);
		}
		n++;
	}
	if (s1[n] != s2[n] && n != i)
		return ((unsigned char)s1[n] - (unsigned char)s2[n]);
	return (0);
}
