/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_draw_shapes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlamiel- <xlamiel-@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 00:00:01 by xlamiel-          #+#    #+#             */
/*   Updated: 2026/07/24 00:00:01 by xlamiel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "render/draw/render_draw.h"
#include "render/colors/render_colors.h"

void	ren_draw_vertical_line(t_game *game,
								t_point start,
								t_point end,
								int color)
{
	int	y;

	y = start.y;
	while (y <= end.y)
	{
		ren_put_pixel(game, start.x, y, color);
		y++;
	}
}

void	ren_draw_horizontal_line(t_game *game,
									t_point start,
									t_point end,
									int color)
{
	int	x;

	x = start.x;
	while (x <= end.x)
	{
		ren_put_pixel(game, x, start.y, color);
		x++;
	}
}

void	ren_draw_rectangle(t_game *game, t_rect rect, int color)
{
	int		x;
	t_point	start;
	t_point	end;

	start.y = rect.pos.y;
	end.y = rect.pos.y + rect.height - 1;
	x = rect.pos.x;
	while (x < rect.pos.x + rect.width)
	{
		start.x = x;
		end.x = x;
		ren_draw_vertical_line(game, start, end, color);
		x++;
	}
}
