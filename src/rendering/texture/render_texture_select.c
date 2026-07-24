/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_texture_select.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlamiel- <xlamiel-@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 00:00:01 by xlamiel-          #+#    #+#             */
/*   Updated: 2026/07/24 00:00:01 by xlamiel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "render/texture/render_texture.h"

t_texture	*render_texture_select(t_game *game, t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->step_x > 0)
			return (&game->textures[WEST]);
		return (&game->textures[EAST]);
	}
	else
	{
		if (ray->step_y > 0)
			return (&game->textures[NORTH]);
		return (&game->textures[SOUTH]);
	}
}
