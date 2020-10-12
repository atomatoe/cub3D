/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 14:28:26 by atomatoe          #+#    #+#             */
/*   Updated: 2020/10/08 15:33:35 by atomatoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		ft_init_step(t_data *img, int y, int x)
{
	if (img->map.map[y][x] == ' ' || img->map.map[y][x] == '0'
		|| img->map.map[y][x] == 'N'
	|| img->map.map[y][x] == 'S' || img->map.map[y][x] == 'W'
		|| img->map.map[y][x] == 'E')
		return (1);
	return (0);
}

int		ft_keystart(int keycode, t_data *img)
{
	if (keycode == 53)
	{
		mlx_destroy_window(img->mlx, img->mlx_win);
		exit(0);
	}
	if (keycode == 13)
		img->key.w = 1;
	if (keycode == 1)
		img->key.s = 1;
	if (keycode == 0)
		img->key.a = 1;
	if (keycode == 2)
		img->key.d = 1;
	if (keycode == 123)
		img->key.left = 1;
	if (keycode == 124)
		img->key.right = 1;
	return (0);
}

int		ft_keystop(int keycode, t_data *img)
{
	if (keycode == 13)
		img->key.w = 0;
	if (keycode == 1)
		img->key.s = 0;
	if (keycode == 0)
		img->key.a = 0;
	if (keycode == 2)
		img->key.d = 0;
	if (keycode == 123)
		img->key.left = 0;
	if (keycode == 124)
		img->key.right = 0;
	if (keycode == 53)
		img->key.esc = 0;
	return (0);
}

int		ft_keyexit(void)
{
	exit(0);
	return (0);
}

void	ft_key_start(t_data *img)
{
	img->key.a = 0;
	img->key.d = 0;
	img->key.esc = 0;
	img->key.left = 0;
	img->key.right = 0;
	img->key.s = 0;
	img->key.w = 0;
	mlx_hook(img->mlx_win, 2, (1L << 0), ft_keystart, img);
	mlx_hook(img->mlx_win, 3, (1L << 1), ft_keystop, img);
	mlx_hook(img->mlx_win, 17, (1L << 17), ft_keyexit, img);
	mlx_loop_hook(img->mlx, ft_keycheck, img);
}
