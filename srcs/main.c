/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 14:39:50 by atomatoe          #+#    #+#             */
/*   Updated: 2020/10/08 15:28:42 by atomatoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		ft_isdigit(int a)
{
	if (a >= '0' && a <= '9')
		return (1);
	return (0);
}

int		ft_argv(char *file, char *str)
{
	int len;

	len = 0;
	if ((len = ft_strlen(file)) > 4 &&
		file[len - 1] == str[2] && file[len - 2] == str[1] &&
		file[len - 3] == str[0] && file[len - 4] == '.')
		return (1);
	return (0);
}

void	ft_init_parse(t_data *img)
{
	img->parse.map_height = 0;
	img->parse.map_width = 0;
	img->parse.player_flag = 0;
	img->parse.r = 0;
	img->parse.no = 0;
	img->parse.texture_no = NULL;
	img->parse.so = 0;
	img->parse.texture_so = NULL;
	img->parse.we = 0;
	img->parse.texture_we = NULL;
	img->parse.ea = 0;
	img->parse.texture_ea = NULL;
	img->parse.s = 0;
	img->parse.texture_sprite = NULL;
	img->parse.f = 0;
	img->parse.c = 0;
	img->params.x = 0;
	img->params.y = 0;
	img->paint.count_spr = 0;
}

int		main(int argc, char **argv)
{
	t_data img;

	if (argc == 1 || argc >= 4)
		return (ft_error(1));
	if (!(ft_argv(argv[1], "cub")))
		return (ft_error(2));
	ft_init_struct(&img);
	ft_init_parse(&img);
	if (ft_parse(&img, argv[1]))
		return (0);
	ft_init_window(&img);
	if (ft_init_textures(&img))
	{
		ft_write_error("textures failed!\n");
		return (0);
	}
	img.rayc.buffer = malloc(sizeof(double) * (img.map.map_width));
	if (argc == 3)
		return (ft_screenshot(&img, argv[2]));
	ft_key_start(&img);
	ft_draw(&img);
	mlx_loop(img.mlx);
}
