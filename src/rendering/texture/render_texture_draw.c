/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_texture_draw.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlamiel- <xlamiel-@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 00:00:01 by xlamiel-          #+#    #+#             */
/*   Updated: 2026/07/24 00:00:01 by xlamiel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "render/texture/render_texture.h"
#include "render/draw/render_draw.h"

void	render_texture_draw(t_game *game, t_ray *ray)
{
	t_texture	*texture;
	int			color;
	int			tex_y;
	int			y;

	texture = render_texture_select(game, ray);
	render_texture_tex_x(ray, texture);
	y = ray->draw_start;
	while (y <= ray->draw_end)
	{
		tex_y = render_texture_tex_y(ray, y, texture);
		color = render_texture_get_pixel(texture, ray->tex_x, tex_y);
		if (ray->side == 1)
			color = render_texture_darken(color);
		ren_put_pixel(game, ray->screen_column, y, color);
		y++;
	}
}
