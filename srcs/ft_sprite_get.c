/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite_get.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 14:38:50 by atomatoe          #+#    #+#             */
/*   Updated: 2020/10/08 15:28:32 by atomatoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int				ft_color_sprite(t_data *img, int y, int x)
{
	int color;

	color = 0;
	if (!(img->file5.width) || !img->file5.height)
		return (0);
	y = abs(y);
	x = abs(x);
	if (y > img->file5.height || x > img->file5.width || y < 0 || x < 0)
		return (0);
	color = (*(int*)(img->file5.addr + ((x + (y * img->file5.width))
		* (img->file5.bits_per_pixel / 8))));
	return (color);
}

static	void	ft_print_sprite(t_data *img, int start)
{
	int i;
	int	k;
	int color;

	i = img->spr.draw_start_y;
	color = 0;
	while (i < img->spr.draw_end_y)
	{
		k = i * 256 - img->map.map_height * 128 + img->spr.sprite_h * 128;
		img->spr.tex_y = ((k * img->file5.height) / img->spr.sprite_h) / 256;
		color = ft_color_sprite(img, img->spr.tex_y, img->spr.tex_x);
		if ((color & 0x00FFFFFF) != 0)
			my_mlx_pixel_put(img, start, i, color);
		i++;
	}
}

static	void	ft_paint_sprites(t_data *img)
{
	int start;

	start = img->spr.draw_start_x;
	while (start < img->spr.draw_end_x)
	{
		img->spr.tex_x = (int)(256 * (start - (-img->spr.sprite_w / 2 +
			img->spr.sprite_screen_x)) * img->file5.width
				/ img->spr.sprite_w) / 256;
		if (img->spr.transform_y > 0 && start >= 0 &&
			start < img->map.map_width
			&& img->spr.transform_y < img->rayc.buffer[start])
			ft_print_sprite(img, start);
		start++;
	}
}

void			ft_sprite_get(t_data *img)
{
	img->spr.draw_start_y = -img->spr.sprite_h / 2 + img->map.map_height / 2;
	if (img->spr.draw_start_y < 0)
		img->spr.draw_start_y = 0;
	img->spr.draw_end_y = img->spr.sprite_h / 2 + img->map.map_height / 2;
	if (img->spr.draw_end_y >= img->map.map_height)
		img->spr.draw_end_y = img->map.map_height;
	img->spr.draw_start_x = -img->spr.sprite_w / 2 + img->spr.sprite_screen_x;
	if (img->spr.draw_start_x < 0)
		img->spr.draw_start_x = 0;
	img->spr.draw_end_x = img->spr.sprite_w / 2 + img->spr.sprite_screen_x;
	if (img->spr.draw_end_x >= img->map.map_width)
		img->spr.draw_end_x = img->map.map_width;
	ft_paint_sprites(img);
}
