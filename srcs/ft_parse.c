/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 14:31:19 by atomatoe          #+#    #+#             */
/*   Updated: 2020/10/08 15:28:16 by atomatoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		check_map(t_data *img)
{
	char	**new_map;
	int		i;
	int		res;

	i = 0;
	if (!(new_map = (char **)malloc(sizeof(char *) * img->parse.map_height)))
		ft_write_error("Error Malloc\n");
	while (i < img->parse.map_height)
	{
		if (!(new_map[i] = ft_strdup(img->map.map[i])))
			ft_write_error("strdup error \n");
		++i;
	}
	init_plr(img);
	res = check_map_rec(new_map, img->parse.map_height,
		(int)img->params.player_pos_x, (int)img->params.player_pos_y);
	check_trash_map(img);
	if (img->parse.player_flag == 0)
		ft_write_error("No player on map!\n");
	i = -1;
	while (++i < img->parse.map_height)
		free(new_map[i]);
	free(new_map);
	return (res);
}

int		map_manager(int fd, char *line, t_data *img)
{
	char	**map;
	int		height;
	int		max_width;

	height = 0;
	if ((map = (char **)malloc(sizeof(char *) * 300)) == NULL)
		return (ft_error(6));
	max_width = ft_strlen(line);
	map[height++] = line;
	while ((get_next_line(fd, &map[height]) > 0))
	{
		if (ft_strlen(map[height++]) > (size_t)max_width)
			max_width = ft_strlen(map[height - 1]);
	}
	if (add_white_space(map, height, max_width) < 0)
		return (ft_error(6));
	img->map.map = map;
	img->parse.map_height = height;
	img->parse.map_width = max_width;
	if ((check_map(img) == -1))
		ft_write_error("Close map!\n");
	if (map[height][0] != '\0')
		return (-1);
	return (1);
}

int		ft_check_params(t_data *img, char *line, int fd)
{
	if (ft_memcmp(line, "R", 1) == 0)
		return (parse_r(img, line));
	else if (ft_memcmp(line, "NO", 2) == 0)
		return (parse_no(img, line));
	else if (ft_memcmp(line, "SO", 2) == 0)
		return (parse_so(img, line));
	else if (ft_memcmp(line, "WE", 2) == 0)
		return (parse_we(img, line));
	else if (ft_memcmp(line, "EA", 2) == 0)
		return (parse_ea(img, line));
	else if (ft_memcmp(line, "S", 1) == 0)
		return (parse_s(img, line));
	else if (ft_memcmp(line, "F", 1) == 0)
		return (parse_f(img, line));
	else if (ft_memcmp(line, "C", 1) == 0)
		return (parse_c(img, line));
	else if ((ft_memcmp(line, " ", 1) == 0) || (ft_memcmp(line, "1", 1) == 0))
		return (map_manager(fd, line, img));
	return (-1);
}

int		ft_parse(t_data *img, char *file)
{
	char		*line;
	const int	fd = open(file, O_RDONLY);
	int			n;
	int			num_of_args;

	num_of_args = 0;
	while ((get_next_line(fd, &line) > 0))
	{
		if (*line)
		{
			num_of_args++;
			n = ft_check_params(img, line, fd);
			if (n < 0)
				return (ft_error(3));
			if (n == 1)
				break ;
		}
		free(line);
	}
	if ((check_params(img)) <= 0)
		ft_write_error("No someone flag!");
	if (num_of_args != 9)
		ft_write_error("Have < 9 params! Error");
	close(fd);
	return (0);
}
