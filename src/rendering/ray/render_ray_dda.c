/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_ray_dda.c                                   :+:      :+:    :+:   */
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

int	render_ray_hit_wall(const t_game *game, const t_ray *ray)
{
	if (game->scene.map[ray->map_y][ray->map_x] == '1')
		return (1);
	else
		return (0);
}

void	render_ray_step_x(t_ray *ray)
{
	ray->side_dist_x += ray->delta_dist_x;
	ray->map_x += ray->step_x;
}

void	render_ray_step_y(t_ray *ray)
{
	ray->side_dist_y += ray->delta_dist_y;
	ray->map_y += ray->step_y;
}

void	render_ray_run_dda(t_game *game, t_ray *ray)
{
	while (!render_ray_hit_wall(game, ray))
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			render_ray_step_x(ray);
			ray->side = 0;
		}
		else
		{
			render_ray_step_y(ray);
			ray->side = 1;
		}
	}
}
