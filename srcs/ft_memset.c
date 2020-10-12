/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 13:02:57 by atomatoe          #+#    #+#             */
/*   Updated: 2020/10/08 15:28:10 by atomatoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

void	*ft_memset(void *src, int g, size_t l)
{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char *)src;
	i = 0;
	while (i < l)
	{
		str[i] = g;
		i++;
	}
	return (str);
}
