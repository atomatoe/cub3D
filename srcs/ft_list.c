/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 18:41:12 by atomatoe          #+#    #+#             */
/*   Updated: 2020/10/08 15:28:08 by atomatoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_list	*ft_new_list(void *content)
{
	t_list *new;

	if (!(new = malloc(sizeof(t_list))))
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

void	ft_list_add_back(t_list **list, t_list *two)
{
	t_list *array;

	array = NULL;
	if (two)
	{
		array = *list;
		if (!array)
			*list = two;
		else
		{
			while (array->next)
				array = array->next;
			array->next = two;
		}
	}
}

void	ft_left(t_data *img)
{
	double old_dir_x;
	double old_plane_x;

	old_dir_x = img->params.player_dir_x;
	old_plane_x = img->params.player_plane_x;
	img->params.player_dir_x = img->params.player_dir_x * cos(-0.05) -
		img->params.player_dir_y * sin(-0.05);
	img->params.player_dir_y = old_dir_x * sin(-0.05)
		+ img->params.player_dir_y * cos(-0.05);
	img->params.player_plane_x = img->params.player_plane_x * cos(-0.05)
		- img->params.player_plane_y * sin(-0.05);
	img->params.player_plane_y = old_plane_x * sin(-0.05)
		+ img->params.player_plane_y * cos(-0.05);
}

void	ft_right(t_data *img)
{
	double old_dir_x;
	double old_plane_x;

	old_dir_x = img->params.player_dir_x;
	old_plane_x = img->params.player_plane_x;
	img->params.player_dir_x = img->params.player_dir_x * cos(0.05) -
		img->params.player_dir_y * sin(0.05);
	img->params.player_dir_y = old_dir_x * sin(0.05)
		+ img->params.player_dir_y * cos(0.05);
	img->params.player_plane_x = img->params.player_plane_x * cos(0.05)
		- img->params.player_plane_y * sin(0.05);
	img->params.player_plane_y = old_plane_x * sin(0.05)
		+ img->params.player_plane_y * cos(0.05);
}
