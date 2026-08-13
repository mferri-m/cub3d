/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_pc_collision_check.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlamiel- <xlamiel-@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 00:00:01 by xlamiel-          #+#    #+#             */
/*   Updated: 2026/07/24 00:00:01 by xlamiel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "render/player_ctrl/render_player_ctrl.h"

int	render_player_can_move(t_game *game, t_vector new_position)
{
	int	map_x;
	int	map_y;

	map_x = (int)new_position.x;
	map_y = (int)new_position.y;
	return (game->scene.map[map_y][map_x] != '1');
}
