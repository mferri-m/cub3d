/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_pc_move.c                                   :+:      :+:    :+:   */
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

void	render_player_translate(t_game *game, t_vector offset)
{
	t_vector	player_pos;
	t_vector	new_position;

	player_pos.x = game->player.x;
	player_pos.y = game->player.y;
	new_position = render_math_vector_add(player_pos, offset);
	if (render_player_can_move(game, new_position))
	{
		game->player.x = new_position.x;
		game->player.y = new_position.y;
		render_frame(game);
	}
}

void	ren_move_forward(t_game *game)
{
	t_vector	offset;

	offset = render_math_vector_scale(
			game->player.direction,
			PLAYER_MOVE_SPEED);
	render_player_translate(game, offset);
}

void	ren_move_backward(t_game *game)
{
	t_vector	offset;

	offset = render_math_vector_scale(
			game->player.direction,
			(-PLAYER_MOVE_SPEED));
	render_player_translate(game, offset);
}

void	ren_strafe_left(t_game *game)
{
	t_vector	offset;

	offset = render_math_vector_scale(game->player.plane, (-PLAYER_MOVE_SPEED));
	render_player_translate(game, offset);
}

void	ren_strafe_right(t_game *game)
{
	t_vector	offset;

	offset = render_math_vector_scale(game->player.plane, (PLAYER_MOVE_SPEED));
	render_player_translate(game, offset);
}
