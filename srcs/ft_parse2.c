/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 14:36:44 by atomatoe          #+#    #+#             */
/*   Updated: 2020/10/08 15:28:22 by atomatoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	parse_r(t_data *img, char *line)
{
	if (ft_memcmp(line, "R", 1) == 0)
	{
		img->parse.r = 1;
		line++;
		if (*line == '+')
			return (-1);
		line = is_space(line);
		img->map.map_width = ft_check_number(line);
		line = ft_check_numb(line);
		line = is_space(line);
		img->map.map_height = ft_check_number(line);
		line = ft_check_numb(line);
		if (img->map.map_width <= 0 || img->map.map_height <= 0)
			return (-1);
		if (img->map.map_width > MAX_WIDTH)
			img->map.map_width = MAX_WIDTH;
		if (img->map.map_height > MAX_HEIGHT)
			img->map.map_height = MAX_HEIGHT;
		return (*line == '\0' ? 0 : -1);
	}
	return (ft_error(3));
}

int	parse_no(t_data *img, char *line)
{
	int		i;

	i = ft_strlen(line);
	if (ft_memcmp(line, "NO", 2) == 0)
	{
		if (!(img->parse.texture_no = ft_strtrim(line, "NO ")))
			return (-1);
		img->parse.no = 1;
	}
	else
		return (ft_error(4));
	if (line[i - 1] != 'm')
		return (-1);
	if (!(ft_argv(img->parse.texture_no, "xpm")))
		return (-1);
	return (0);
}

int	parse_so(t_data *img, char *line)
{
	int		i;

	i = ft_strlen(line);
	if (ft_memcmp(line, "SO", 2) == 0)
	{
		if (!(img->parse.texture_so = ft_strtrim(line, "SO ")))
			return (-1);
		img->parse.so = 1;
	}
	else
		return (ft_error(4));
	if (line[i - 1] != 'm')
		return (-1);
	if (!(ft_argv(img->parse.texture_so, "xpm")))
		return (-1);
	return (0);
}

int	parse_we(t_data *img, char *line)
{
	int		i;

	i = ft_strlen(line);
	if (ft_memcmp(line, "WE", 2) == 0)
	{
		if (!(img->parse.texture_we = ft_strtrim(line, "WE ")))
			return (-1);
		img->parse.we = 1;
	}
	else
		return (ft_error(4));
	if (line[i - 1] != 'm')
		return (-1);
	if (!(ft_argv(img->parse.texture_no, "xpm")))
		return (-1);
	return (0);
}

int	parse_ea(t_data *img, char *line)
{
	int		i;

	i = ft_strlen(line);
	if (ft_memcmp(line, "EA", 2) == 0)
	{
		if (!(img->parse.texture_ea = ft_strtrim(line, "EA ")))
			return (-1);
		img->parse.ea = 1;
	}
	else
		return (ft_error(4));
	if (line[i - 1] != 'm')
		return (-1);
	if (!(ft_argv(img->parse.texture_no, "xpm")))
		return (-1);
	return (0);
}
