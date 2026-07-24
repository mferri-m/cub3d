/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_projection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlamiel- <xlamiel-@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 00:00:01 by xlamiel-          #+#    #+#             */
/*   Updated: 2026/07/24 00:00:01 by xlamiel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "render/projection/render_projection.h"

void	render_projection_perp_wall_dist(t_ray *ray)
{
	if (ray->side == 0)
		ray->perp_wall_dist = ray->side_dist_x - ray->delta_dist_x;
	else
		ray->perp_wall_dist = ray->side_dist_y - ray->delta_dist_y;
}

void	render_projection_line_height(t_game *game, t_ray *ray)
{
	ray->line_height = game->window.height / ray->perp_wall_dist;
}

void	render_projection_draw_limits(t_game *game, t_ray *ray)
{
	ray->draw_start_real = (int)((game->window.height
				- ray->line_height) / 2.0);
	ray->draw_end_real = (int)((game->window.height
				+ ray->line_height) / 2.0);
	ray->draw_start = ray->draw_start_real;
	ray->draw_end = ray->draw_end_real;
}

void	render_projection_clip_limits(t_game *game, t_ray *ray)
{
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	if (ray->draw_end >= game->window.height)
		ray->draw_end = game->window.height - 1;
}
