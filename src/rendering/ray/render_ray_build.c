/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_ray_build.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlamiel- <xlamiel-@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 00:00:01 by xlamiel-          #+#    #+#             */
/*   Updated: 2026/07/24 00:00:01 by xlamiel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "render/ray/render_ray.h"
#include "render/math/render_math.h"

double	render_ray_column_center(const t_game *game, int column)
{
	double	ret;
	double	column_center;

	column_center = (double)column + 0.5;
	ret = (column_center * 2.0) / (double)game->window.width;
	return (ret);
}

double	render_ray_rule_center(double old_reference)
{
	double	ret;

	ret = old_reference - 1.0;
	return (ret);
}

t_vector	render_ray_direction(t_player *player, double camera_x)
{
	t_vector	offset;
	t_vector	ray_dir;

	offset = render_math_vector_scale(player->plane, camera_x);
	ray_dir = render_math_vector_add(player->direction, offset);
	return (ray_dir);
}
