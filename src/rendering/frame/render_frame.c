/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
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

void	render_projection(t_game *game, t_ray *ray)
{
	render_projection_perp_wall_dist(ray);
	render_projection_line_height(game, ray);
	render_projection_draw_limits(game, ray);
	render_projection_clip_limits(game, ray);
}

void	render_draw_column(t_game *game, t_ray *ray)
{
	render_texture_column(game, ray);
}

void	render_frame(t_game *game)
{
	t_ray	ray;

	ren_draw_background(game);
	ray.screen_column = 0;
	while (ray.screen_column < game->window.width)
	{
		render_ray(game, &ray);
		render_projection(game, &ray);
		render_draw_column(game, &ray);
		ray.screen_column++;
	}
	mlx_put_image_to_window(
		game->mlx,
		game->window.ptr,
		game->image.img,
		0,
		0);
}
