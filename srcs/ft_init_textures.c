/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 18:27:14 by atomatoe          #+#    #+#             */
/*   Updated: 2020/10/08 15:27:58 by atomatoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static	int	ft_init_textures2(t_data *img)
{
	if (!(img->file4.img = mlx_xpm_file_to_image(img->mlx,
		img->parse.texture_ea, &(img->file4.width),
			&(img->file4.height))))
		return (1);
	if (!(img->file4.addr = mlx_get_data_addr(img->file4.img,
		&img->file4.bits_per_pixel, &img->file4.line_length,
			&img->file4.endian)))
		return (1);
	if (!(img->file5.img = mlx_xpm_file_to_image(img->mlx,
		img->parse.texture_sprite, &(img->file5.width),
			&(img->file5.height))))
		return (1);
	if (!(img->file5.addr = mlx_get_data_addr(img->file5.img,
		&img->file5.bits_per_pixel, &img->file5.line_length,
			&img->file5.endian)))
		return (1);
	return (0);
}

int			ft_init_textures(t_data *img)
{
	if (!(img->file1.img = mlx_xpm_file_to_image(img->mlx,
		img->parse.texture_no, &(img->file1.width), &(img->file1.height))))
		return (1);
	if (!(img->file1.addr = mlx_get_data_addr(img->file1.img,
		&img->file1.bits_per_pixel, &img->file1.line_length,
			&img->file1.endian)))
		return (1);
	if (!(img->file2.img = mlx_xpm_file_to_image(img->mlx,
		img->parse.texture_so, &(img->file2.width),
			&(img->file2.height))))
		return (1);
	if (!(img->file2.addr = mlx_get_data_addr(img->file2.img,
		&img->file2.bits_per_pixel,
			&img->file2.line_length, &img->file2.endian)))
		return (1);
	if (!(img->file3.img = mlx_xpm_file_to_image(img->mlx,
		img->parse.texture_we, &(img->file3.width),
			&(img->file3.height))))
		return (1);
	if (!(img->file3.addr = mlx_get_data_addr(img->file3.img,
		&img->file3.bits_per_pixel,
			&img->file3.line_length, &img->file3.endian)))
		return (1);
	return (ft_init_textures2(img));
}
