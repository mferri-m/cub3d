/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_destroy.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlamiel- <xlamiel-@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 00:00:01 by xlamiel-          #+#    #+#             */
/*   Updated: 2026/07/24 00:00:01 by xlamiel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_DESTROY_H
# define RENDER_DESTROY_H

# include "cub3d.h"
# include "mlx.h"

/* rendering/destroy/render_destroy.c */
int		render_destroy_game(t_game *game);
void	render_destroy_textures(t_game *game);
void	render_destroy_image(t_game *game);
void	render_destroy_window(t_game *game);
void	render_destroy_mlx(t_game *game);
#endif
