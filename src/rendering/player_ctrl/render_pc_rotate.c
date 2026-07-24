/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_pc_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlamiel- <xlamiel-@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 00:00:01 by xlamiel-          #+#    #+#             */
/*   Updated: 2026/07/24 00:00:01 by xlamiel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "render/player_ctrl/render_player_ctrl.h"
#include "render/math/render_math.h"
#include "render/frame/render_frame.h"

void	ren_player_rotate(t_game *game,
							t_vector new_direction,
							t_vector new_plane)
{
	game->player.direction = new_direction;
	game->player.plane = new_plane;
	render_frame(game);
}

void	ren_rotate_left(t_game *game)
{
	t_vector	new_direction;
	t_vector	new_plane;

	new_direction = render_math_vector_rotate(
			game->player.direction,
			-PLAYER_ROTATE_SPEED);
	new_plane = render_math_vector_rotate(
			game->player.plane,
			-PLAYER_ROTATE_SPEED);
	ren_player_rotate(game, new_direction, new_plane);
}

void	ren_rotate_right(t_game *game)
{
	t_vector	new_direction;
	t_vector	new_plane;

	new_direction = render_math_vector_rotate(
			game->player.direction,
			PLAYER_ROTATE_SPEED);
	new_plane = render_math_vector_rotate(
			game->player.plane,
			PLAYER_ROTATE_SPEED);
	ren_player_rotate(game, new_direction, new_plane);
}
