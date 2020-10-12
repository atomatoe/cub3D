/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_paint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 14:31:05 by atomatoe          #+#    #+#             */
/*   Updated: 2020/10/08 15:28:13 by atomatoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_draw_sky(t_data *img)
{
	int		i;
	int		k;
	int		g;

	i = img->map.map_height / 2;
	k = 0;
	while (k < i)
	{
		g = -1;
		while (++g < img->map.map_width)
			my_mlx_pixel_put(img, g, k, img->paint.color_sky);
		++k;
	}
	while (k < img->map.map_height)
	{
		g = -1;
		while (++g < img->map.map_width)
			my_mlx_pixel_put(img, g, k, img->paint.color_earth);
		++k;
	}
}

void	my_mlx_pixel_put(t_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	ft_paint(t_data *img, int y, int x, int color)
{
	int		pos_x;
	int		pos_y;
	int		pos_endx;
	int		pos_endy;

	pos_x = x * 32;
	pos_y = y * 32;
	pos_endx = (x + 1) * 32;
	pos_endy = (y + 1) * 32;
	while (pos_y < pos_endy)
	{
		while (pos_x < pos_endx)
			my_mlx_pixel_put(img, pos_x++, pos_y, color);
		pos_x -= 32;
		pos_y += 1;
	}
}
