/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 14:33:00 by atomatoe          #+#    #+#             */
/*   Updated: 2020/10/08 15:28:18 by atomatoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*is_space(char *str)
{
	while (*str == ' ' || *str == '\t' || *str == '\n'
		|| *str == '\r' || *str == '\f' || *str == '\v')
		str++;
	return (str);
}

char	*ft_check_numb(char *line)
{
	while (*line >= '0' && *line <= '9')
		line++;
	return (line);
}

char	*next_number(char *line)
{
	while (*line == ',' || *line == ' ')
		line++;
	while (ft_isdigit(*line))
		line++;
	return (line);
}

int		ft_check_number(char *line)
{
	int	res;
	int count;

	res = 0;
	count = 0;
	if (ft_isdigit(line[count]) == 1)
	{
		while (ft_isdigit(line[count]) == 1)
		{
			if (res < 10000)
				res = (res * 10) + (line[count] - 48);
			count++;
		}
	}
	else
		res = -1;
	return (res);
}

int		add_white_space(char **line, int max_height, int max_width)
{
	int		y;
	int		len;
	char	*new_str;

	y = 0;
	check_player_map(line, max_height);
	while (y < max_height)
	{
		len = ft_strlen(line[y]);
		if (len != max_width)
		{
			if ((new_str = malloc(sizeof(char *) * (max_width + 1))) == NULL)
				return (-1);
			ft_strlcpy(new_str, line[y], len + 1);
			while (len != max_width)
				new_str[len++] = ' ';
			new_str[len] = '\0';
			free(line[y]);
			line[y] = new_str;
		}
		y++;
	}
	return (1);
}
