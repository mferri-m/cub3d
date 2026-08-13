/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_chars.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marferri <marferri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 00:00:00 by marferri          #+#    #+#             */
/*   Updated: 2026/07/29 00:00:00 by marferri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	is_spawn_char(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

static int	is_valid_map_char(char c)
{
	return (c == '0' || c == '1' || c == ' ' || is_spawn_char(c));
}

static int	validate_map_row(char *row, int row_idx,
		t_player *player, int *spawn_count)
{
	int		col;
	char	c;

	col = 0;
	while (row[col] != '\0')
	{
		c = row[col];
		if (!is_valid_map_char(c))
			return (cub_error("invalid character in map"));
		if (is_spawn_char(c))
		{
			set_player_spawn(player, row_idx, col, c);
			(*spawn_count)++;
		}
		col++;
	}
	return (0);
}

int	validate_map_chars(t_scene *scene, t_player *player)
{
	int	row;
	int	spawn_count;
	int	status;

	spawn_count = 0;
	row = 0;
	status = 0;
	while (row < scene->height && status == 0)
	{
		status = validate_map_row(scene->map[row], row, player, &spawn_count);
		row++;
	}
	if (status == 0 && spawn_count != 1)
		status = cub_error("map must have exactly one spawn point");
	return (status);
}
