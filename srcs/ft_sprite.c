/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 14:38:32 by atomatoe          #+#    #+#             */
/*   Updated: 2020/10/08 15:28:30 by atomatoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static	void	ft_sprite_dist(t_data *img)
{
	int i;

	i = 0;
	while (i < img->paint.count_spr)
	{
		img->sprit[i].dist_spr = sqrt(pow(img->params.player_pos_x
			- img->sprit[i].x_spr, 2)
			+ pow(img->params.player_pos_y - img->sprit[i].y_spr, 2));
		i++;
	}
}

static	void	ft_spr_buffer(t_sprite *a, t_sprite *b)
{
	double x;
	double y;
	double dist;

	x = a->x_spr;
	y = a->y_spr;
	dist = a->dist_spr;
	a->x_spr = b->x_spr;
	a->y_spr = b->y_spr;
	a->dist_spr = b->dist_spr;
	b->x_spr = x;
	b->y_spr = y;
	b->dist_spr = dist;
}

static	void	ft_init_sprite(t_data *img)
{
	int i;
	int k;

	k = 1;
	while (k)
	{
		i = 0;
		k = 0;
		while (i < img->paint.count_spr)
		{
			if ((img->sprit[i].dist_spr < img->sprit[i + 1].dist_spr)
				&& (i + 1 < img->paint.count_spr))
			{
				ft_spr_buffer(&img->sprit[i], &img->sprit[i + 1]);
				k = 1;
			}
			i++;
		}
	}
}

void			ft_paint_spr(t_data *img, t_sprite *sprite)
{
	img->spr.sprite_x = sprite->x_spr - img->params.player_pos_x;
	img->spr.sprite_y = sprite->y_spr - img->params.player_pos_y;
	img->spr.invdet = 1.0 / (img->params.player_plane_x
		* img->params.player_dir_y
		- img->params.player_dir_x * img->params.player_plane_y);
	img->spr.transform_x = img->spr.invdet *
		(img->params.player_dir_y * img->spr.sprite_x
		- img->params.player_dir_x * img->spr.sprite_y);
	img->spr.transform_y = img->spr.invdet *
		(-img->params.player_plane_y * img->spr.sprite_x
		+ img->params.player_plane_x * img->spr.sprite_y);
	img->spr.sprite_screen_x = (int)((img->map.map_width / 2) *
		(1 + img->spr.transform_x / img->spr.transform_y));
	img->spr.sprite_h = abs((int)(((img->map.map_height
		/ (img->spr.transform_y)))));
	img->spr.sprite_w = abs((int)(((img->map.map_height
		/ (img->spr.transform_y)))));
	ft_sprite_get(img);
}

void			ft_sprite(t_data *img)
{
	int i;

	i = -1;
	ft_sprite_dist(img);
	ft_init_sprite(img);
	while (i++ < img->paint.count_spr)
	{
		ft_paint_spr(img, &img->sprit[i]);
	}
}
