/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_projection.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlamiel- <xlamiel-@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 00:00:01 by xlamiel-          #+#    #+#             */
/*   Updated: 2026/07/24 00:00:01 by xlamiel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_PROJECTION_H
# define RENDER_PROJECTION_H

# include "cub3d.h"

/* rendering/projection/render_projection.c */
void	render_projection_perp_wall_dist(t_ray *ray);
void	render_projection_line_height(t_game *game, t_ray *ray);
void	render_projection_draw_limits(t_game *game, t_ray *ray);
void	render_projection_clip_limits(t_game *game, t_ray *ray);
#endif
