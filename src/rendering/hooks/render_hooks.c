/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlamiel- <xlamiel-@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 00:00:01 by xlamiel-          #+#    #+#             */
/*   Updated: 2026/07/24 00:00:01 by xlamiel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "render/hooks/render_hooks.h"
#include "render/hooks/render_keys.h"
#include "render/hooks/render_events.h"
#include "render/player_ctrl/render_player_ctrl.h"
#include "render/destroy/render_destroy.h"
#include "render/mlx/render_mlx.h"

int	ren_close_window(t_game *game)
{
	render_destroy_game(game);
	exit(0);
	return (0);
}

int	ren_key_press(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		return (render_destroy_game(game));
	if (keycode == KEY_W)
		ren_move_forward(game);
	else if (keycode == KEY_S)
		ren_move_backward(game);
	else if (keycode == KEY_A)
		ren_strafe_left(game);
	else if (keycode == KEY_D)
		ren_strafe_right(game);
	else if (keycode == KEY_LEFT)
		ren_rotate_left(game);
	else if (keycode == KEY_RIGHT)
		ren_rotate_right(game);
	return (0);
}
