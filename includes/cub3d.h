/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 16:56:07 by atomatoe          #+#    #+#             */
/*   Updated: 2020/10/08 15:35:09 by atomatoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "get_next_line.h"
# include "../mlx/mlx.h"

# define VISION	66
# define SPEED	0.1
# define MAX_HEIGHT 2160/2
# define MAX_WIDTH 3840/2

typedef	struct	s_paint
{
	double			wallx;
	double			stepx;
	double			tex_pos;
	int				tex_widht;
	int				tex_height;
	int				tex_x;
	int				tex_y;
	int				paint_y;
	int				color;
	int				count_spr;
	int				color_sky;
	int				color_earth;
}				t_paint;

typedef	struct	s_rayc
{
	double			camera_x;
	double			ray_dir_x;
	double			ray_dir_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			side_dist_x;
	double			side_dist_y;
	double			perp_wall_dist;
	int				mapx;
	int				mapy;
	int				stepx;
	int				stepy;
	int				hit;
	int				side;
	int				lineheight;
	int				drawstart;
	int				drawend;
	double			*buffer;
}				t_rayc;

typedef	struct	s_sprite
{
	double			x_spr;
	double			y_spr;
	double			dist_spr;
	int				i;

}				t_sprite;

typedef	struct	s_spr
{
	double			sprite_x;
	double			sprite_y;
	double			invdet;
	double			transform_x;
	double			transform_y;
	int				sprite_screen_x;
	int				sprite_h;
	int				draw_start_y;
	int				draw_end_y;
	int				sprite_w;
	int				draw_start_x;
	int				draw_end_x;
	int				tex_x;
	int				tex_y;
}				t_spr;

typedef	struct	s_param
{
	int				x;
	int				y;
	int				player_flag;
	double			player_pos_x;
	double			player_pos_y;
	double			player_dir_x;
	double			player_dir_y;
	double			player_plane_x;
	double			player_plane_y;
}				t_param;

typedef	struct	s_map
{
	char			**map;
	int				len_map;
	int				map_height;
	int				map_width;
}				t_map;

typedef	struct	s_key
{
	int				w;
	int				s;
	int				a;
	int				d;
	int				right;
	int				left;
	int				esc;
}				t_key;

typedef	struct	s_text
{
	char			*file;
	char			*addr;
	void			*img;
	int				bits_per_pixel;
	int				width;
	int				height;
	int				line_length;
	int				endian;
}				t_text;

typedef	struct	s_list
{
	char			*content;
	struct s_list	*next;
}				t_list;

typedef	struct	s_parse
{
	int				map_height;
	int				map_width;
	int				player_flag;
	int				r;
	int				no;
	char			*texture_no;
	int				so;
	char			*texture_so;
	int				we;
	char			*texture_we;
	int				ea;
	char			*texture_ea;
	int				s;
	char			*texture_sprite;
	int				f;
	int				c;

}				t_parse;

typedef struct	s_data
{
	void			*mlx;
	void			*mlx_win;
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				height;
	int				width;
	t_text			file1;
	t_text			file2;
	t_text			file3;
	t_text			file4;
	t_text			file5;
	t_param			params;
	t_map			map;
	t_rayc			rayc;
	t_paint			paint;
	t_key			key;
	t_sprite		*sprit;
	t_spr			spr;
	t_parse			parse;
}				t_data;

t_list			*ft_new_list(void *content);
void			ft_list_add_back(t_list **list, t_list *two);
void			ft_draw (t_data *img);
void			ft_draw_init (t_data *img);
void			ft_draw2(t_data *img, int x_pixel);
void			ft_init_struct(t_data *img);
void			ft_init_window(t_data *img);
int				ft_keystart(int keycode, t_data *img);
int				ft_keystop(int keycode, t_data *img);
int				ft_keycheck(t_data *img);
int				ft_color_sprite(t_data *img, int y, int x);
void			ft_paint(t_data *img, int y, int x, int color);
void			my_mlx_pixel_put(t_data *img, int x, int y, int color);
void			ft_open_map(t_data *img);
void			ft_player_pos(t_data *img);
void			ft_key_start(t_data *img);
int				ft_init_textures(t_data *img);
void			ft_sprite(t_data *img);
void			ft_sprite_get(t_data *img);
void			ft_draw_sky(t_data *img);
int				ft_keyexit(void);
void			ft_check_player(t_data *img);
void			ft_check_player2(t_data *img);
int				ft_memcmp(const void *str1, const void *str2, size_t n);
char			*ft_strtrim(char const *s1, char const *set);
void			ft_putstr_fd(char *s, int fd);
void			ft_putchar_fd(char c, int fd);
int				ft_argv (char *file, char *str);
int				parse_s(t_data *img, char *line);
int				parse_f(t_data *img, char *line);
int				parse_c(t_data *img, char *line);
int				parse_r(t_data *img, char *line);
int				parse_no(t_data *img, char *line);
int				parse_so(t_data *img, char *line);
int				parse_we(t_data *img, char *line);
int				parse_ea(t_data *img, char *line);
int				check_map(t_data *img);
int				map_manager(int fd, char *line, t_data *img);
int				ft_check_params(t_data *img, char *line, int fd);
int				ft_parse(t_data *img, char *file);
int				add_white_space(char **line, int max_height, int max_width);
int				ft_check_number(char *line);
char			*next_number(char *line);
char			*ft_check_numb(char *line);
char			*is_space(char *str);
int				ft_error(int code);
void			ft_write_error(char *str);
int				ft_isdigit(int a);
char			*ft_substr(const char *s, unsigned int start, size_t len);
void			check_trash_map(t_data *img);
void			check_player_map(char **line, int max_height);
void			check_map_around(t_data *img, int x, int y);
int				check_params(t_data *img);
int				init_plr(t_data *img);
int				check_map_rec(char **map, int max_height, int x, int y);
int				ft_screenshot(t_data *img, char *str);
int				ft_init_step(t_data *img, int y, int x);
void			ft_left(t_data *img);
void			ft_right(t_data *img);

#endif
