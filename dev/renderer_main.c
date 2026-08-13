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
#include "render/render_game.h"
#include "render/colors/render_colors.h"
#include "render/frame/render_window.h"
#include "render/frame/render_image.h"
#include "render/frame/render_frame.h"
#include "render/hooks/render_hooks.h"
#include "render/hooks/render_events.h"
#include "render/texture/render_texture.h"
#include "render/mlx/render_mlx.h"

/*
	game->scene.floor.value = 0x6B4F2A;
	game->scene.ceiling.value = 0x87CEEB;
	game->scene.floor.value = COLOR_GRAY;
	game->scene.ceiling.value = COLOR_CYAN;

*/

void	init_player_orientation(t_game *game, char orientation)
{
	if (orientation == 'N')
	{
		game->player.direction.y = -1;
		game->player.plane.x = 0.66;
	}
	else if (orientation == 'S')
	{
		game->player.direction.y = 1;
		game->player.plane.x = -0.66;
	}
	else if (orientation == 'E')
	{
		game->player.direction.x = 1;
		game->player.plane.y = 0.66;
	}
	else if (orientation == 'W')
	{
		game->player.direction.x = -1;
		game->player.plane.y = -0.66;
	}
}

static void	load_debug_scene(t_game *game)
{
	static char	*debug_map[] = {
		"11111111",
		"10000001",
		"10000001",
		"10000011",
		"10000001",
		"10000001",
		"11111111",
		NULL
	};

	game->scene.texture_paths[NORTH] = "./textures/north.xpm";
	game->scene.texture_paths[SOUTH] = "./textures/south.xpm";
	game->scene.texture_paths[WEST] = "./textures/west.xpm";
	game->scene.texture_paths[EAST] = "./textures/east.xpm";
	game->scene.map = debug_map;
	game->scene.width = 6;
	game->scene.height = 4;
	game->player.x = 2.5;
	game->player.y = 2.5;
	init_player_orientation(game, 'W');
	game->scene.floor.value = 0x6B4F2A;
	game->scene.ceiling.value = 0x87CEEB;
}

int	main(void)
{
	t_game	game;

	game_init(&game);
	load_debug_scene(&game);
	return (render_game(&game));
}
