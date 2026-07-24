/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_draw.c                                      :+:      :+:    :+:   */
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

void	ren_put_pixel(t_game *game, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= game->window.width
		|| y < 0 || y >= game->window.height)
		return ;
	dst = game->image.addr
		+ (y * game->image.line_length)
		+ (x * (game->image.bpp / 8));
	*(unsigned int *)dst = color;
}

void	ren_clear_image(t_game *game, int color)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->window.width)
	{
		y = 0;
		while (y < game->window.height)
		{
			ren_put_pixel(game, x, y, color);
			y++;
		}
		x++;
	}
}

void	ren_draw_background(t_game *game)
{
	int		middle;
	t_rect	ceiling_rect;
	t_rect	floor_rect;

	middle = game->window.height / 2;
	ceiling_rect.pos.x = 0;
	ceiling_rect.width = game->window.width;
	ceiling_rect.pos.y = 0;
	ceiling_rect.height = middle;
	floor_rect.pos.x = 0;
	floor_rect.width = game->window.width;
	floor_rect.pos.y = middle;
	floor_rect.height = game->window.height - middle;
	ren_draw_rectangle(game, ceiling_rect, game->scene.ceiling.value);
	ren_draw_rectangle(game, floor_rect, game->scene.floor.value);
}
