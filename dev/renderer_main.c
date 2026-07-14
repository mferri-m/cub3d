/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marferri <marferri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 00:00:00 by marferri          #+#    #+#             */
/*   Updated: 2026/07/14 00:00:00 by marferri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	load_debug_scene(t_game *game)
{
	static char	*debug_map[] = {
		"111111",
		"100001",
		"100001",
		"111111",
		NULL
	};

	game->scene.map = debug_map;
	game->scene.width = 6;
	game->scene.height = 4;
	game->player.x = 2.5;
	game->player.y = 2.5;
	game->player.direction_x = -1.0;
	game->player.plane_y = 0.66;
}

int	main(void)
{
	t_game	game;

	game_init(&game);
	load_debug_scene(&game);
	return (render_game(&game));
}
