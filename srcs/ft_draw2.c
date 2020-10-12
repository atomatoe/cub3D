/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 14:26:24 by atomatoe          #+#    #+#             */
/*   Updated: 2020/10/08 15:27:51 by atomatoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	ft_params(t_data *img, int width, int height)
{
	img->paint.tex_widht = width;
	img->paint.tex_height = height;
	img->paint.paint_y = img->rayc.drawstart;
	img->paint.wallx -= floor(img->paint.wallx);
	img->paint.tex_x = (int)(img->paint.wallx * (double)width);
	if (img->rayc.side == 2 || img->rayc.side == 1)
		img->paint.tex_x = width - img->paint.tex_x - 1;
	img->paint.stepx = 1.0 * height / img->rayc.lineheight;
	img->paint.tex_pos = (img->rayc.drawstart -
		img->map.map_height / 2 + img->rayc.lineheight / 2) * img->paint.stepx;
}

static void	ft_side(t_data *img)
{
	if (img->rayc.side == 0)
		ft_params(img, img->file1.width, img->file1.height);
	if (img->rayc.side == 1)
		ft_params(img, img->file2.width, img->file2.height);
	if (img->rayc.side == 2)
		ft_params(img, img->file3.width, img->file3.height);
	if (img->rayc.side == 3)
		ft_params(img, img->file4.width, img->file4.height);
	if (img->rayc.side == 2 || img->rayc.side == 3)
		img->paint.wallx = img->params.player_pos_y
			+ img->rayc.perp_wall_dist * img->rayc.ray_dir_y;
	else
		img->paint.wallx = img->params.player_pos_x
			+ img->rayc.perp_wall_dist * img->rayc.ray_dir_x;
}

void		ft_paint_textures(t_data *img, int y, int x)
{
	x = abs(x);
	y = abs(y);
	if (img->rayc.side == 0)
		img->paint.color = (*(int*)(img->file1.addr + ((x +
			(y * img->file1.width)) * (img->file1.bits_per_pixel / 8))));
	if (img->rayc.side == 1)
		img->paint.color = (*(int*)(img->file2.addr + ((x +
			(y * img->file2.width)) * (img->file2.bits_per_pixel / 8))));
	if (img->rayc.side == 2)
		img->paint.color = (*(int*)(img->file3.addr + ((x +
			(y * img->file3.width)) * (img->file3.bits_per_pixel / 8))));
	if (img->rayc.side == 3)
		img->paint.color = (*(int*)(img->file4.addr + ((x +
			(y * img->file4.width)) * (img->file4.bits_per_pixel / 8))));
}

void		ft_draw2(t_data *img, int x_pixel)
{
	ft_side(img);
	while (img->paint.paint_y < img->rayc.drawend)
	{
		img->paint.tex_y = (int)(img->paint.tex_pos)
			& (img->paint.tex_height - 1);
		ft_paint_textures(img, img->paint.tex_y, img->paint.tex_x);
		my_mlx_pixel_put(img, x_pixel, img->paint.paint_y, img->paint.color);
		img->paint.tex_pos += img->paint.stepx;
		(img->paint.paint_y)++;
	}
}

void		ft_draw(t_data *img)
{
	img->img = mlx_new_image(img->mlx, img->map.map_width,
		img->map.map_height);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
		&img->line_length, &img->endian);
	ft_draw_sky(img);
	ft_draw_init(img);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
}
