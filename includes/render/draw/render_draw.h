/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_draw.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlamiel- <xlamiel-@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 00:00:01 by xlamiel-          #+#    #+#             */
/*   Updated: 2026/07/24 00:00:01 by xlamiel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_DRAW_H
# define RENDER_DRAW_H

# include "cub3d.h"
# include "render/colors/render_colors.h"

/* rendering/render_draw */
void	ren_put_pixel(t_game *game, int x, int y, int color);
void	ren_clear_image(t_game *game, int color);
void	ren_draw_vertical_line(
			t_game *game,
			t_point start,
			t_point end,
			int color);
void	ren_draw_horizontal_line(
			t_game *game,
			t_point start,
			t_point end,
			int color);
void	ren_draw_rectangle(
			t_game *game,
			t_rect rect,
			int color);
void	ren_draw_background(t_game *game);
#endif
