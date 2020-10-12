/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 14:27:08 by atomatoe          #+#    #+#             */
/*   Updated: 2020/10/08 15:27:53 by atomatoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		ft_error(int code)
{
	if (code == 1)
		printf("Error number arg!\n");
	if (code == 2)
		printf("Error file format!\n");
	if (code == 3)
		printf("Error argument!\n");
	if (code == 4)
		printf("Error texture!\n");
	if (code == 5)
		printf("Error map close!\n");
	if (code == 6)
		printf("Error malloc!\n");
	if (code == 7)
		printf("Error --save!\n");
	return (-1);
}

void	ft_write_error(char *str)
{
	ft_putstr_fd("ERROR\n", 1);
	ft_putstr_fd(str, 1);
	exit(-1);
}
