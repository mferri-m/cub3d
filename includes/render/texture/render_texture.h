/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_texture.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlamiel- <xlamiel-@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 00:00:01 by xlamiel-          #+#    #+#             */
/*   Updated: 2026/07/24 00:00:01 by xlamiel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_TEXTURE_H
# define RENDER_TEXTURE_H

# include "cub3d.h"
# include <stdio.h>
# include <math.h>

# define TEXTURE_SIZE   64

/* /src/rendering/texture/render_texture.c */
void		render_texture_column(t_game *game, t_ray *ray);
/* /src/rendering/texture/render_texture_color.c */
int			render_texture_darken(int color);
/* /src/rendering/texture/render_texture_draw.c */
void		render_texture_draw(t_game *game, t_ray *ray);
/* /src/rendering/texture/render_texture_load.c */
int			render_texture_load(void *mlx, t_texture *texture, char *path);
int			render_texture_init(t_game *game);
/* /src/rendering/texture/render_texture_map.c */
void		render_texture_wall_x(t_game *game, t_ray *ray);
void		render_texture_tex_x(t_ray *ray, t_texture *texture);
int			render_texture_tex_y(t_ray *ray, int screen_y, t_texture *texture);
/* /src/rendering/texture/render_texture_sample.c */
int			render_texture_get_pixel(t_texture *texture, int x, int y);
/* /src/rendering/texture/render_texture_select.c */
t_texture	*render_texture_select(t_game *game, t_ray *ray);
/* /src/rendering/texture/render_texture_utils.c */

#endif
