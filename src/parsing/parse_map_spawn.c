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

/* Both helpers below assume c is already one of N/S/E/W — guaranteed by
 * validate_map_row's is_spawn_char() check before set_player_spawn is ever
 * called. Their trailing `else` means "must be W", not "anything else";
 * do not call these from a new site without that same guarantee. */
static void	set_direction_vector(char c, t_player *player)
{
	if (c == 'N')
	{
		player->direction_x = 0;
		player->direction_y = -1;
	}
	else if (c == 'S')
	{
		player->direction_x = 0;
		player->direction_y = 1;
	}
	else if (c == 'E')
	{
		player->direction_x = 1;
		player->direction_y = 0;
	}
	else
	{
		player->direction_x = -1;
		player->direction_y = 0;
	}
}

static void	set_plane_vector(char c, t_player *player)
{
	if (c == 'N')
	{
		player->plane_x = 0.66;
		player->plane_y = 0;
	}
	else if (c == 'S')
	{
		player->plane_x = -0.66;
		player->plane_y = 0;
	}
	else if (c == 'E')
	{
		player->plane_x = 0;
		player->plane_y = 0.66;
	}
	else
	{
		player->plane_x = 0;
		player->plane_y = -0.66;
	}
}

/* player->x/y are set to row/col + 0.5 (cell center); validate_map()
 * later recovers the spawn row/col with (int)player->y / (int)player->x
 * instead of threading two extra parameters through every call. */
void	set_player_spawn(t_player *player, int row, int col, char c)
{
	player->x = col + 0.5;
	player->y = row + 0.5;
	set_direction_vector(c, player);
	set_plane_vector(c, player);
}
