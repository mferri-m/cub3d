/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_texture_load.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlamiel- <xlamiel-@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 00:00:01 by xlamiel-          #+#    #+#             */
/*   Updated: 2026/07/24 00:00:01 by xlamiel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "render/texture/render_texture.h"
#include "render/mlx/render_mlx.h"

int	render_texture_load(void *mlx, t_texture *texture, char *path)
{
	texture->img = mlx_xpm_file_to_image(
			mlx,
			path,
			&texture->width,
			&texture->height);
	if (texture->img == NULL)
		return (1);
	texture->addr = mlx_get_data_addr(
			texture->img,
			&texture->bpp,
			&texture->line_length,
			&texture->endian);
	if (texture->addr == NULL)
		return (1);
	return (0);
}

int	render_texture_init(t_game *game)
{
	int	i;

	i = NORTH;
	while (i <= EAST)
	{
		if (render_texture_load(
				game->mlx,
				&game->textures[i],
				game->scene.texture_paths[i]))
			return (1);
		i++;
	}
	return (0);
}
