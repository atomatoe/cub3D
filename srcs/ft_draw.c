/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 13:59:59 by atomatoe          #+#    #+#             */
/*   Updated: 2020/10/08 15:27:46 by atomatoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	ft_player_param(t_data *img, int x_pixel)
{
	img->rayc.camera_x = 2 * x_pixel / (double)(img->map.map_width) - 1;
	img->rayc.ray_dir_x = img->params.player_dir_x
		+ img->params.player_plane_x * img->rayc.camera_x;
	img->rayc.ray_dir_y = img->params.player_dir_y +
		img->params.player_plane_y * img->rayc.camera_x;
	img->rayc.mapx = (int)(img->params.player_pos_x);
	img->rayc.mapy = (int)(img->params.player_pos_y);
	img->rayc.hit = 0;
	if (!(img->rayc.ray_dir_y))
		img->rayc.delta_dist_x = 0;
	else
		img->rayc.delta_dist_x = (!(img->rayc.ray_dir_x))
			? 1 : fabs(1 / img->rayc.ray_dir_x);
	if (!(img->rayc.ray_dir_x))
		img->rayc.delta_dist_y = 0;
	else
		img->rayc.delta_dist_y = (!(img->rayc.ray_dir_y))
			? 1 : fabs(1 / img->rayc.ray_dir_y);
}

static void	ft_step(t_data *img, double y, double x)
{
	if (img->rayc.ray_dir_x < 0)
	{
		img->rayc.stepx = -1;
		img->rayc.side_dist_x = (x - img->rayc.mapx) * img->rayc.delta_dist_x;
	}
	else
	{
		img->rayc.stepx = 1;
		img->rayc.side_dist_x = (1.0 + img->rayc.mapx - x)
			* img->rayc.delta_dist_x;
	}
	if (img->rayc.ray_dir_y < 0)
	{
		img->rayc.stepy = -1;
		img->rayc.side_dist_y = (y - img->rayc.mapy)
			* img->rayc.delta_dist_y;
	}
	else
	{
		img->rayc.stepy = 1;
		img->rayc.side_dist_y = (1.0 + img->rayc.mapy - y)
			* img->rayc.delta_dist_y;
	}
}

static void	ft_dda(t_data *img)
{
	while (img->rayc.hit == 0)
	{
		if (img->rayc.side_dist_x < img->rayc.side_dist_y)
		{
			img->rayc.side_dist_x += img->rayc.delta_dist_x;
			img->rayc.mapx += img->rayc.stepx;
			img->rayc.side = (img->rayc.ray_dir_x < 0) ? 2 : 3;
		}
		else
		{
			img->rayc.side_dist_y += img->rayc.delta_dist_y;
			img->rayc.mapy += img->rayc.stepy;
			img->rayc.side = (img->rayc.ray_dir_y < 0) ? 0 : 1;
		}
		if (img->map.map[img->rayc.mapy][img->rayc.mapx] == '1')
			img->rayc.hit = 1;
	}
}

static void	ft_init_wall(t_data *img)
{
	if (img->rayc.side > 1)
		img->rayc.perp_wall_dist = (img->rayc.mapx - img->params.player_pos_x +
		(1 - img->rayc.stepx) / 2) / img->rayc.ray_dir_x;
	else
		img->rayc.perp_wall_dist = (img->rayc.mapy - img->params.player_pos_y +
		(1 - img->rayc.stepy) / 2) / img->rayc.ray_dir_y;
	img->rayc.lineheight = (int)(img->map.map_height
		/ img->rayc.perp_wall_dist);
	img->rayc.drawstart = -(img->rayc.lineheight)
		/ 2 + img->map.map_height / 2;
	if (img->rayc.drawstart < 0)
		img->rayc.drawstart = 0;
	img->rayc.drawend = img->rayc.lineheight / 2 + img->map.map_height / 2;
	if (img->rayc.drawend >= img->map.map_height)
		img->rayc.drawend = img->map.map_height;
}

void		ft_draw_init(t_data *img)
{
	int		x_pixel;

	x_pixel = -1;
	while (++x_pixel < img->map.map_width)
	{
		ft_player_param(img, x_pixel);
		ft_step(img, img->params.player_pos_y, img->params.player_pos_x);
		ft_dda(img);
		ft_init_wall(img);
		ft_draw2(img, x_pixel);
		img->rayc.buffer[x_pixel] = img->rayc.perp_wall_dist;
	}
	ft_sprite(img);
}
