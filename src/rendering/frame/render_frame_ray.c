/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame_ray.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlamiel- <xlamiel-@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 00:00:01 by xlamiel-          #+#    #+#             */
/*   Updated: 2026/07/24 00:00:01 by xlamiel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "render/frame/render_frame.h"
#include "render/frame/render_frame_ray.h"
#include "render/ray/render_ray.h"
#include "render/projection/render_projection.h"
#include "render/texture/render_texture.h"
#include "render/draw/render_draw.h"
#include "render/mlx/render_mlx.h"

void	render_ray_build(t_game *game, t_ray *ray)
{
	double	column_center;

	column_center = render_ray_column_center(game, ray->screen_column);
	ray->camera_x = render_ray_rule_center(column_center);
	ray->ray_dir = render_ray_direction(&(game->player), ray->camera_x);
}

void	render_ray_setup(t_game *game, t_ray *ray)
{
	render_ray_init_map(ray, &(game->player));
	render_ray_delta_dist(ray);
	render_ray_step(ray);
	render_ray_side_dist(ray, &(game->player));
}

void	render_ray_dda(t_game *game, t_ray *ray)
{
	render_ray_run_dda(game, ray);
}

void	render_ray(t_game *game, t_ray *ray)
{
	render_ray_build(game, ray);
	render_ray_setup(game, ray);
	render_ray_dda(game, ray);
}
