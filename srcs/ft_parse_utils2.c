/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 18:49:16 by atomatoe          #+#    #+#             */
/*   Updated: 2020/10/08 15:28:20 by atomatoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		check_params(t_data *img)
{
	if (img->parse.no == 1 && img->parse.we == 1 && img->parse.so == 1
		&& img->parse.ea == 1 && img->parse.s == 1 &&
		img->parse.r == 1 && img->parse.f == 1 && img->parse.c == 1)
		return (1);
	return (0);
}

int		init_plr(t_data *img)
{
	while (img->params.y < img->parse.map_height)
	{
		img->params.x = 0;
		while (img->params.x < img->parse.map_width)
		{
			if (img->map.map[img->params.y][img->parse.map_width - 1] == '0')
				ft_write_error("Space in map, error\n");
			if (img->map.map[img->params.y][img->params.x] == '2')
				img->paint.count_spr++;
			if (ft_strchr("NEWS", img->map.map[img->params.y][img->params.x]))
			{
				img->params.player_pos_x = img->params.x + 0.5;
				img->params.player_pos_y = img->params.y + 0.5;
				ft_check_player(img);
				ft_check_player2(img);
				check_map_around(img, img->params.x, img->params.y);
			}
			if (img->map.map[(int)img->params.y][(int)img->params.x] == '2'
				|| img->map.map[(int)img->params.y][(int)img->params.x] == '0')
				check_map_around(img, img->params.x, img->params.y);
			img->params.x++;
		}
		img->params.y++;
	}
	return (0);
}

void	check_trash_map(t_data *img)
{
	int		x;
	int		y;

	y = 0;
	while (y < img->parse.map_height)
	{
		x = 0;
		while (x < img->parse.map_width)
		{
			if ((img->map.map[y][x] == ' ' || img->map.map[y][x] == '0' ||
				img->map.map[y][x] == '1' || img->map.map[y][x] == '2') ||
				((img->map.map[y][x] == 'N' || img->map.map[y][x] == 'W' ||
				img->map.map[y][x] == 'S' || img->map.map[y][x] == 'E') &&
				img->parse.player_flag != 1))
			{
				if (img->map.map[y][x] == 'N' || img->map.map[y][x] == 'W' ||
					img->map.map[y][x] == 'S' || img->map.map[y][x] == 'E')
					img->parse.player_flag = 1;
				x++;
			}
			else
				ft_write_error("Error map!\n");
		}
		y++;
	}
}

void	check_player_map(char **line, int max_height)
{
	int		i;
	int		x;

	x = 0;
	i = 0;
	while (i < max_height)
	{
		if (ft_strlen(line[i]) == 0 && i < max_height)
			ft_write_error("No mode map");
		i++;
	}
	if (line[max_height][0] == '\0')
	{
		while (line[max_height - 1][x])
		{
			if (line[max_height - 1][x] == '0' || line[max_height - 1][x] == 'S'
			|| line[max_height - 1][x] == '2' || line[max_height - 1][x] == 'N'
			|| line[max_height - 1][x] == 'W' || line[max_height - 1][x] == 'E')
				ft_write_error("no zero in last line!");
			x++;
		}
	}
}

int		check_map_rec(char **map, int max_height, int x, int y)
{
	if (map[y][x] == ' ' || y < 0 || x < 0 || map[y][x] == '\0'
		|| y >= max_height)
		return (-1);
	if (map[y][x] == '1' || map[y][x] == '.')
		return (1);
	map[y][x] = '.';
	return (check_map_rec(map, max_height, x - 1, y) &&
			check_map_rec(map, max_height, x + 1, y) &&
			check_map_rec(map, max_height, x, y - 1) &&
			check_map_rec(map, max_height, x, y + 1));
}
