/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_spawn.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marferri <marferri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 00:00:00 by marferri          #+#    #+#             */
/*   Updated: 2026/07/29 00:00:00 by marferri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static void	set_direction_vector(char c, t_player *player)
{
	if (c == 'N')
	{
		player->direction.x = 0;
		player->direction.y = -1;
	}
	else if (c == 'S')
	{
		player->direction.x = 0;
		player->direction.y = 1;
	}
	else if (c == 'E')
	{
		player->direction.x = 1;
		player->direction.y = 0;
	}
	else
	{
		player->direction.x = -1;
		player->direction.y = 0;
	}
}

static void	set_plane_vector(char c, t_player *player)
{
	if (c == 'N')
	{
		player->plane.x = 0.66;
		player->plane.y = 0;
	}
	else if (c == 'S')
	{
		player->plane.x = -0.66;
		player->plane.y = 0;
	}
	else if (c == 'E')
	{
		player->plane.x = 0;
		player->plane.y = 0.66;
	}
	else
	{
		player->plane.x = 0;
		player->plane.y = -0.66;
	}
}

void	set_player_spawn(t_player *player, int row, int col, char c)
{
	player->x = col + 0.5;
	player->y = row + 0.5;
	set_direction_vector(c, player);
	set_plane_vector(c, player);
}
