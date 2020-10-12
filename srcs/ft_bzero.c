/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 12:52:32 by atomatoe          #+#    #+#             */
/*   Updated: 2020/10/08 15:27:21 by atomatoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

void	ft_bzero(void *src, size_t l)
{
	size_t	i;
	char	*str;

	i = 0;
	str = src;
	while (i < l)
	{
		str[i] = '\0';
		i++;
	}
}
