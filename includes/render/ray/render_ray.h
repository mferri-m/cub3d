/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_ray.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlamiel- <xlamiel-@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 00:00:01 by xlamiel-          #+#    #+#             */
/*   Updated: 2026/07/24 00:00:01 by xlamiel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_RAY_H
# define RENDER_RAY_H

# include "cub3d.h"

/* rendering/ray/render_ray_build.c */
double		render_ray_column_center(const t_game *game, int column);
double		render_ray_rule_center(double old_reference);
t_vector	render_ray_direction(t_player *player, double camera_x);

/* rendering/ray/render_ray_setup.c */
void		render_ray_init_map(t_ray *ray, const t_player *player);
void		render_ray_delta_dist(t_ray *ray);
void		render_ray_step(t_ray *ray);
void		render_ray_side_dist(t_ray *ray, const t_player *player);

/* rendering/ray/render_ray_dda.c */
int			render_ray_hit_wall(const t_game *game, const t_ray *ray);
void		render_ray_step_x(t_ray *ray);
void		render_ray_step_y(t_ray *ray);
void		render_ray_run_dda(t_game *game, t_ray *ray);

/* rendering/ray/render_ray_test.c */
void		render_ray_test(t_game *game);
#endif
