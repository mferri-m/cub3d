/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_math.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlamiel- <xlamiel-@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 00:00:01 by xlamiel-          #+#    #+#             */
/*   Updated: 2026/07/24 00:00:01 by xlamiel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_MATH_H
# define RENDER_MATH_H

# include "cub3d.h"
# include <math.h>

/* rendering/math/render_math_vector.c */
t_vector	render_math_vector_scale(t_vector vector, double scalar);
t_vector	render_math_vector_add(t_vector a, t_vector b);
t_vector	render_math_vector_rotate(t_vector vector, double angle);
#endif
