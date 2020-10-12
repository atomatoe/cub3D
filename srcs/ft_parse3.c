/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 14:37:17 by atomatoe          #+#    #+#             */
/*   Updated: 2020/10/08 15:28:24 by atomatoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		parse_s(t_data *img, char *line)
{
	int	i;

	i = ft_strlen(line);
	if (ft_memcmp(line, "S", 1) == 0)
	{
		if (!(img->parse.texture_sprite = ft_strtrim(line, "S ")))
			return (-1);
		img->parse.s = 1;
	}
	else
		return (ft_error(4));
	if (line[i - 1] != 'm')
		return (-1);
	if (!(ft_argv(img->parse.texture_sprite, "xpm")))
		return (-1);
	return (0);
}

int		parse_f(t_data *img, char *line)
{
	int color;
	int num[3];
	int	j;

	img->parse.f = 1;
	j = 0;
	line++;
	line = is_space(line);
	while (j < 3)
	{
		num[j] = ft_check_number(line);
		if (num[j] > 255 || num[j] < 0)
			return (-1);
		line = next_number(line);
		line++;
		if (*line == ',')
			return (-1);
		j++;
	}
	line -= 1;
	if (*line != '\0')
		return (-1);
	color = num[0] << 16 | num[1] << 8 | num[2];
	img->paint.color_sky = color;
	return (color);
}

int		parse_c(t_data *img, char *line)
{
	int color;
	int num[3];
	int	j;

	img->parse.c = 1;
	j = 0;
	line++;
	line = is_space(line);
	while (j < 3)
	{
		num[j] = ft_check_number(line);
		if (num[j] > 255 || num[j] < 0)
			return (-1);
		line = next_number(line);
		line++;
		if (*line == ',')
			return (-1);
		j++;
	}
	line -= 1;
	if (*line != '\0')
		return (-1);
	color = num[0] << 16 | num[1] << 8 | num[2];
	img->paint.color_earth = color;
	return (color);
}

void	check_map_around(t_data *img, int x, int y)
{
	if (y - 1 < 0 || x - 1 < 0 || img->map.map[y - 1][x] == ' '
		|| img->map.map[y][x - 1] == ' ' || (img->map.map[y][x + 1] != '\0'
		&& img->map.map[y][x + 1] == ' ') || (y + 1 < img->parse.map_height
		&& img->map.map[y + 1][x] == ' ' && y >= img->parse.map_height))
		ft_write_error("Space in map, error\n");
}
