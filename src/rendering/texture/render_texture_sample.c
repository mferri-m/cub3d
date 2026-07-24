/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_texture_sample.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlamiel- <xlamiel-@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 00:00:01 by xlamiel-          #+#    #+#             */
/*   Updated: 2026/07/24 00:00:01 by xlamiel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "render/texture/render_texture.h"

int	render_texture_get_pixel(t_texture *texture, int x, int y)
{
	int	offset;

	if (x < 0 || x >= texture->width)
		return (0);
	if (y < 0 || y >= texture->height)
		return (0);
	offset = y * texture->line_length;
	offset += x * (texture->bpp / 8);
	return (*(int *)(texture->addr + offset));
}
