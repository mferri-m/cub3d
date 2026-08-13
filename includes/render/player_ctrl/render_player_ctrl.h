/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_player_ctrl.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlamiel- <xlamiel-@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 00:00:01 by xlamiel-          #+#    #+#             */
/*   Updated: 2026/07/24 00:00:01 by xlamiel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_PLAYER_CTRL_H
# define RENDER_PLAYER_CTRL_H

# include "cub3d.h"

/* Keys codes */
# define KEY_ESC				65307
# define KEY_A					97
# define KEY_S					115
# define KEY_D					100
# define KEY_W					119
# define KEY_LEFT				65361
# define KEY_RIGHT				65363

# define PLAYER_MOVE_SPEED		0.05
# define PLAYER_ROTATE_SPEED	0.04

/* /src/rendering/player_ctrl/render_pc_move.c */
void	render_player_translate(t_game *game, t_vector offset);
void	ren_move_forward(t_game *game);
void	ren_move_backward(t_game *game);
void	ren_strafe_left(t_game *game);
void	ren_strafe_right(t_game *game);
/* /src/rendering/player_ctrl/render_pc_rotate.c */
void	ren_rotate_player(t_game *game,
			t_vector new_direction,
			t_vector new_plane);
void	ren_rotate_left(t_game *game);
void	ren_rotate_right(t_game *game);
/* /src/rendering/player_ctrl/render_pc_collision_check.c*/
int		render_player_can_move(t_game *game, t_vector new_position);
#endif
