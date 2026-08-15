/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_grid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marferri <marferri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 00:00:00 by marferri          #+#    #+#             */
/*   Updated: 2026/07/29 00:00:00 by marferri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	is_border_char(char c)
{
	return (c == '1' || c == ' ');
}

int	compute_map_width(t_scene *scene)
{
	int	row;
	int	len;
	int	width;

	width = 0;
	row = 0;
	while (row < scene->height)
	{
		len = (int)ft_strlen(scene->map[row]);
		if (len > width)
			width = len;
		row++;
	}
	return (width);
}

char	get_map_char(t_scene *scene, int width, int row, int col)
{
	int	len;

	if (row < 0 || row >= scene->height || col < 0 || col >= width)
		return ('\0');
	len = (int)ft_strlen(scene->map[row]);
	if (col >= len)
		return (' ');
	return (scene->map[row][col]);
}

int	validate_map_border(t_scene *scene)
{
	int	col;
	int	row;

	col = 0;
	while (col < scene->width)
	{
		if (!is_border_char(get_map_char(scene, scene->width, 0, col))
			|| !is_border_char(get_map_char(scene, scene->width,
					scene->height - 1, col)))
			return (cub_error("map is not closed"));
		col++;
	}
	row = 0;
	while (row < scene->height)
	{
		if (!is_border_char(get_map_char(scene, scene->width, row, 0))
			|| !is_border_char(get_map_char(scene, scene->width, row,
					scene->width - 1)))
			return (cub_error("map is not closed"));
		row++;
	}
	return (0);
}
