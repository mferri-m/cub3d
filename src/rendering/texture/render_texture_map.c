/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_texture_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlamiel- <xlamiel-@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 00:00:01 by xlamiel-          #+#    #+#             */
/*   Updated: 2026/07/24 00:00:01 by xlamiel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "render/texture/render_texture.h"
#include <math.h>

void	render_texture_tex_x(t_ray *ray, t_texture *texture)
{
	ray->tex_x = (int)(ray->wall_x * texture->width);
	if (ray->side == 0 && ray->ray_dir.x > 0)
		ray->tex_x = texture->width - ray->tex_x - 1;
	if (ray->side == 1 && ray->ray_dir.y < 0)
		ray->tex_x = texture->width - ray->tex_x - 1;
}

void	render_texture_wall_x(t_game *game, t_ray *ray)
{
	if (ray->side == 0)
		ray->wall_x = game->player.y + ray->perp_wall_dist * ray->ray_dir.y;
	else
		ray->wall_x = game->player.x + ray->perp_wall_dist * ray->ray_dir.x;
	ray->wall_x -= floor(ray->wall_x);
}

int	render_texture_tex_y(t_ray *ray, int screen_y, t_texture *texture)
{
	int	relative_y;

	relative_y = screen_y - ray->draw_start_real;
	return ((relative_y * texture->height) / ray->line_height);
}
