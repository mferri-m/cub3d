/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marferri <marferri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 00:00:00 by marferri          #+#    #+#             */
/*   Updated: 2026/07/14 00:00:00 by marferri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "render/frame/render_window.h"
#include "render/frame/render_image.h"
#include "render/hooks/render_hooks.h"
#include "render/hooks/render_events.h"
#include "render/texture/render_texture.h"
#include "render/frame/render_frame.h"
#include "render/mlx/render_mlx.h"
#include "render/destroy/render_destroy.h"

int	ren_init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		return (cub_error("mlx_init failed"));
	return (0);
}

int	ren_create_window(t_game *game)
{
	game->window.ptr = mlx_new_window(
			game->mlx,
			game->window.width,
			game->window.height,
			game->window.title);
	if (game->window.ptr == NULL)
		return (cub_error("mlx_new_window failed"));
	return (0);
}

int	ren_register_hooks(t_game *game)
{
	mlx_hook(
		game->window.ptr,
		EVENT_DESTROY,
		MASK_DESTROY,
		ren_close_window,
		game);
	mlx_hook(
		game->window.ptr,
		EVENT_KEY_PRESS,
		(1L << 0),
		ren_key_press,
		game);
	return (0);
}

int	ren_create_image(t_game *game)
{
	game->image.img = mlx_new_image(
			game->mlx,
			game->window.width,
			game->window.height);
	if (game->image.img == NULL)
		return (cub_error("Error create image"));
	game->image.addr = mlx_get_data_addr(
			game->image.img,
			&game->image.bpp,
			&game->image.line_length,
			&game->image.endian);
	if (game->image.addr == NULL)
		return (cub_error("Error get addr image"));
	return (0);
}

int	render_game(t_game *game)
{
	if (ren_init_mlx(game))
		return (1);
	if (render_texture_init(game))
	{
		render_destroy_textures(game);
		render_destroy_mlx(game);
		return (1);
	}
	if (ren_create_window(game))
		return (1);
	if (ren_create_image(game))
		return (1);
	if (ren_register_hooks(game))
		return (1);
	render_frame(game);
	mlx_loop(game->mlx);
	return (0);
}
