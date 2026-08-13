/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlamiel- <xlamiel-@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 00:00:01 by xlamiel-          #+#    #+#             */
/*   Updated: 2026/07/24 00:00:01 by xlamiel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "render/destroy/render_destroy.h"
#include "render/mlx/render_mlx.h"

void	render_destroy_textures(t_game *game)
{
	int	i;

	i = NORTH;
	while (i <= EAST)
	{
		if (game->textures[i].img)
			mlx_destroy_image(game->mlx, game->textures[i].img);
		i++;
	}
}

void	render_destroy_image(t_game *game)
{
	if (game->image.img)
	{
		mlx_destroy_image(game->mlx, game->image.img);
		game->image.img = NULL;
		game->image.addr = NULL;
	}
}

void	render_destroy_window(t_game *game)
{
	if (game->window.ptr)
	{
		mlx_destroy_window(game->mlx, game->window.ptr);
		game->window.ptr = NULL;
	}
}

void	render_destroy_mlx(t_game *game)
{
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		game->mlx = NULL;
	}
}

int	render_destroy_game(t_game *game)
{
	render_destroy_textures(game);
	render_destroy_image(game);
	render_destroy_window(game);
	render_destroy_mlx(game);
	exit(0);
	return (0);
}
