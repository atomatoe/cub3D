/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 14:27:16 by atomatoe          #+#    #+#             */
/*   Updated: 2020/10/08 15:27:56 by atomatoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	ft_init_rayc(t_data *img)
{
	img->rayc.camera_x = 0;
	img->rayc.ray_dir_x = 0;
	img->rayc.ray_dir_y = 0;
	img->rayc.delta_dist_x = 0;
	img->rayc.delta_dist_y = 0;
	img->rayc.side_dist_x = 0;
	img->rayc.side_dist_y = 0;
	img->rayc.perp_wall_dist = 0;
	img->rayc.mapx = 0;
	img->rayc.mapy = 0;
	img->rayc.stepx = 0;
	img->rayc.stepy = 0;
	img->rayc.hit = 0;
	img->rayc.side = 0;
	img->rayc.lineheight = 0;
	img->rayc.drawstart = 0;
	img->rayc.drawend = 0;
	img->rayc.buffer = 0;
	img->params.x = 0;
	img->params.y = 0;
	img->params.player_flag = 0;
	img->params.player_pos_x = 0;
	img->params.player_pos_y = 0;
	img->params.player_dir_x = 0;
}

static void	ft_init_key(t_data *img)
{
	img->key.w = 0;
	img->key.s = 0;
	img->key.a = 0;
	img->key.d = 0;
	img->key.right = 0;
	img->key.left = 0;
	img->key.esc = 0;
	img->file4.addr = NULL;
	img->file4.img = NULL;
	img->file4.bits_per_pixel = 0;
	img->file4.width = 0;
	img->file4.height = 0;
	img->file4.line_length = 0;
	img->file4.endian = 0;
	img->file5.addr = NULL;
	img->file5.img = NULL;
	img->file5.bits_per_pixel = 0;
	img->file5.width = 0;
	img->file5.height = 0;
	img->file5.line_length = 0;
	img->file5.endian = 0;
}

static void	ft_init_textur(t_data *img)
{
	img->file1.addr = NULL;
	img->file1.img = NULL;
	img->file1.bits_per_pixel = 0;
	img->file1.width = 0;
	img->file1.height = 0;
	img->file1.line_length = 0;
	img->file1.endian = 0;
	img->file2.addr = NULL;
	img->file2.img = NULL;
	img->file2.bits_per_pixel = 0;
	img->file2.width = 0;
	img->file2.height = 0;
	img->file2.line_length = 0;
	img->file2.endian = 0;
	img->file3.addr = NULL;
	img->file3.img = NULL;
	img->file3.bits_per_pixel = 0;
	img->file3.width = 0;
	img->file3.height = 0;
	img->file3.line_length = 0;
	img->file3.endian = 0;
}

static void	ft_init_paint_spr(t_data *img)
{
	img->paint.wallx = 0;
	img->paint.stepx = 0;
	img->paint.tex_pos = 0;
	img->paint.tex_widht = 0;
	img->paint.tex_height = 0;
	img->paint.tex_x = 0;
	img->paint.tex_y = 0;
	img->paint.paint_y = 0;
	img->paint.color = 0;
	img->spr.sprite_x = 0;
	img->spr.sprite_y = 0;
	img->spr.invdet = 0;
	img->spr.transform_x = 0;
	img->spr.transform_y = 0;
	img->spr.sprite_screen_x = 0;
	img->spr.sprite_h = 0;
	img->spr.draw_start_y = 0;
	img->spr.draw_end_y = 0;
	img->spr.sprite_w = 0;
	img->spr.draw_start_x = 0;
	img->spr.draw_end_x = 0;
	img->spr.tex_x = 0;
	img->spr.tex_y = 0;
}

void		ft_init_struct(t_data *img)
{
	img->img = NULL;
	img->addr = NULL;
	img->bits_per_pixel = 0;
	img->line_length = 0;
	img->endian = 0;
	img->height = 0;
	img->width = 0;
	img->mlx = NULL;
	img->mlx_win = NULL;
	img->params.player_dir_y = 0;
	img->params.player_plane_x = 0;
	img->params.player_plane_y = 0;
	ft_init_paint_spr(img);
	ft_init_rayc(img);
	ft_init_key(img);
	ft_init_textur(img);
}
