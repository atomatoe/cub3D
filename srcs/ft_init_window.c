/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 14:28:00 by atomatoe          #+#    #+#             */
/*   Updated: 2020/10/08 15:28:00 by atomatoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_check_player2(t_data *img)
{
	if (img->map.map[(int)img->params.player_pos_y]
		[(int)img->params.player_pos_x] == 'E')
	{
		img->params.player_dir_x = 1;
		img->params.player_dir_y = 0;
		img->params.player_plane_x = 0;
		img->params.player_plane_y = tan(M_PI * VISION / 360);
	}
	if (img->map.map[(int)img->params.player_pos_y]
		[(int)img->params.player_pos_x] == 'W')
	{
		img->params.player_dir_x = -1;
		img->params.player_dir_y = 0;
		img->params.player_plane_x = 0;
		img->params.player_plane_y = -tan(M_PI * VISION / 360);
	}
}

void	ft_check_player(t_data *img)
{
	if (img->map.map[(int)img->params.player_pos_y]
		[(int)img->params.player_pos_x] == 'N')
	{
		img->params.player_dir_x = 0;
		img->params.player_dir_y = -1;
		img->params.player_plane_x = tan(M_PI * VISION / 360);
		img->params.player_plane_y = 0;
	}
	if (img->map.map[(int)img->params.player_pos_y]
		[(int)img->params.player_pos_x] == 'S')
	{
		img->params.player_dir_x = 0;
		img->params.player_dir_y = 1;
		img->params.player_plane_x = -tan(M_PI * VISION / 360);
		img->params.player_plane_y = 0;
	}
}

void	ft_init_spr(t_data *img, int y, int x, int count)
{
	img->sprit[count].y_spr = y + 0.5;
	img->sprit[count].x_spr = x + 0.5;
}

void	ft_player_pos(t_data *img)
{
	int i;

	i = 0;
	img->params.y = 0;
	img->params.x = 0;
	while (img->params.y < img->parse.map_height)
	{
		while (img->params.x < (int)ft_strlen(img->map.map[img->params.y]))
		{
			if (img->map.map[img->params.y][img->params.x] == '2'
				&& i != img->paint.count_spr)
			{
				ft_init_spr(img, img->params.y, img->params.x, i);
				i++;
			}
			img->params.x++;
		}
		img->params.x = 0;
		img->params.y++;
	}
	img->params.y = 0;
}

void	ft_init_window(t_data *img)
{
	img->mlx = mlx_init();
	img->mlx_win = mlx_new_window(img->mlx,
		img->map.map_width, img->map.map_height, "cub3d");
	if (!(img->sprit = (t_sprite *)malloc((img->paint.count_spr + 1)
		* sizeof(t_sprite))))
		ft_write_error("kek omg!\n");
	ft_player_pos(img);
}
