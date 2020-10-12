/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screenshot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 18:51:47 by atomatoe          #+#    #+#             */
/*   Updated: 2020/10/08 15:28:28 by atomatoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static	int	write_in_header(unsigned char *bmp_fhead,
	unsigned char *bmp_head, t_data *img)
{
	int				fd;
	char			*fname;
	int				line_len;
	int				i;

	i = 0;
	fname = "screenshot.bmp";
	if ((fd = open(fname, O_RDWR | O_CREAT, 0755)) < 0)
		return (0);
	write(fd, bmp_fhead, 14);
	write(fd, bmp_head, 40);
	line_len = img->bits_per_pixel / 8 * img->map.map_width;
	while (i < img->map.map_height)
	{
		write(fd, img->addr + i * img->line_length, line_len);
		i++;
	}
	if (close(fd < 0))
	{
		ft_putstr_fd("close error", 0);
		return (0);
	}
	return (1);
}

static	int	make_header(unsigned char *bmp_fhead,
	unsigned char *bmp_head, t_data *img)
{
	int				file_size;

	file_size = 14 + 40 + img->map.map_width * img->map.map_height *
			img->bits_per_pixel / 8;
	bmp_fhead[0] = 'B';
	bmp_fhead[1] = 'M';
	bmp_fhead[2] = (unsigned char)(file_size);
	bmp_fhead[3] = (unsigned char)(file_size >> 8);
	bmp_fhead[4] = (unsigned char)(file_size >> 16);
	bmp_fhead[5] = (unsigned char)(file_size >> 24);
	bmp_fhead[10] = (unsigned char)(14 + 40);
	bmp_head[0] = (unsigned char)(40);
	bmp_head[4] = (unsigned char)(img->map.map_width);
	bmp_head[5] = (unsigned char)(img->map.map_width >> 8);
	bmp_head[6] = (unsigned char)(img->map.map_width >> 16);
	bmp_head[7] = (unsigned char)(img->map.map_width >> 24);
	bmp_head[8] = (unsigned char)(-img->map.map_height);
	bmp_head[9] = (unsigned char)(-img->map.map_height >> 8);
	bmp_head[10] = (unsigned char)(-img->map.map_height >> 16);
	bmp_head[11] = (unsigned char)(-img->map.map_height >> 24);
	bmp_head[12] = (unsigned char)(1);
	bmp_head[14] = (unsigned char)(img->bits_per_pixel);
	return (1);
}

static	int	ft_screensh(t_data *img)
{
	unsigned char	bmp_h[14];
	unsigned char	bmp_k[40];

	ft_bzero(bmp_h, 14);
	ft_bzero(bmp_k, 40);
	img->img = mlx_new_image(img->mlx, img->map.map_width, img->map.map_height);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
		&img->line_length, &img->endian);
	ft_draw_sky(img);
	ft_draw_init(img);
	make_header(bmp_h, bmp_k, img);
	if (!(write_in_header(bmp_h, bmp_k, img)))
		ft_write_error("screen error\n");
	close(0);
	return (0);
}

int			ft_screenshot(t_data *img, char *str)
{
	if (ft_strncmp(str, "--save", 10) != 0)
		return (ft_error(7));
	return (ft_screensh(img));
}
