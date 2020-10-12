/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 12:53:09 by atomatoe          #+#    #+#             */
/*   Updated: 2020/10/08 15:27:20 by atomatoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

void	*ft_calloc(size_t num, size_t size)
{
	void *p;

	p = (void *)malloc(num * size);
	if (!p)
		return (NULL);
	ft_memset(p, 0, num * size);
	return (p);
}
