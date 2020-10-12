/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 13:57:39 by atomatoe          #+#    #+#             */
/*   Updated: 2020/10/08 15:28:05 by atomatoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static	void	ft_key_w(t_data *img)
{
	if (ft_init_step(img, (int)img->params.player_pos_y,
		(int)(img->params.player_pos_x + img->params.player_dir_x
			* (SPEED + 0.01))))
		img->params.player_pos_x += img->params.player_dir_x * SPEED;
	if (ft_init_step(img, img->params.player_pos_y + img->params.player_dir_y *
		(SPEED + 0.01), (int)img->params.player_pos_x))
		img->params.player_pos_y += img->params.player_dir_y * SPEED;
}

static	void	ft_key_s(t_data *img)
{
	if (ft_init_step(img, (int)img->params.player_pos_y,
		(int)(img->params.player_pos_x - img->params.player_dir_x
			* (SPEED + 0.01))))
		img->params.player_pos_x -= img->params.player_dir_x * SPEED;
	if (ft_init_step(img, (int)(img->params.player_pos_y -
		img->params.player_dir_y * (SPEED + 0.01)),
			(int)img->params.player_pos_x))
		img->params.player_pos_y -= img->params.player_dir_y * SPEED;
}

static	void	ft_key_a(t_data *img)
{
	if (ft_init_step(img, (int)img->params.player_pos_y,
		(int)(img->params.player_pos_x - img->params.player_plane_x *
			(SPEED + 0.01))))
		img->params.player_pos_x -= img->params.player_plane_x * SPEED;
	if (ft_init_step(img, (int)(img->params.player_pos_y -
		img->params.player_plane_y * (SPEED + 0.01)),
			(int)img->params.player_pos_x))
		img->params.player_pos_y -= img->params.player_plane_y * SPEED;
}

static	void	ft_key_d(t_data *img)
{
	if (ft_init_step(img, (int)img->params.player_pos_y,
		(int)(img->params.player_pos_x + img->params.player_plane_x *
			(SPEED + 0.01))))
		img->params.player_pos_x += img->params.player_plane_x * SPEED;
	if (ft_init_step(img, (int)(img->params.player_pos_y +
		img->params.player_plane_y * (SPEED + 0.01)),
			(int)img->params.player_pos_x))
		img->params.player_pos_y += img->params.player_plane_y * SPEED;
}

int				ft_keycheck(t_data *img)
{
	mlx_destroy_image(img->mlx, img->img);
	if (img->key.w)
		ft_key_w(img);
	if (img->key.s)
		ft_key_s(img);
	if (img->key.a)
		ft_key_a(img);
	if (img->key.d)
		ft_key_d(img);
	if (img->key.left)
		ft_left(img);
	if (img->key.right)
		ft_right(img);
	ft_draw(img);
	return (0);
}
