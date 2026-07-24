/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_math_vector.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlamiel- <xlamiel-@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 00:00:01 by xlamiel-          #+#    #+#             */
/*   Updated: 2026/07/24 00:00:01 by xlamiel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "render/math/render_math.h"

t_vector	render_math_vector_scale(t_vector vector, double scalar)
{
	t_vector	ret;

	ret.x = vector.x * scalar;
	ret.y = vector.y * scalar;
	return (ret);
}

t_vector	render_math_vector_add(t_vector a, t_vector b)
{
	t_vector	ret;

	ret = (t_vector){0};
	ret.x = a.x + b.x;
	ret.y = a.y + b.y;
	return (ret);
}

t_vector	render_math_vector_rotate(t_vector vector, double angle)
{
	t_vector	ret;

	ret.x = vector.x * cos(angle) - vector.y * sin(angle);
	ret.y = vector.x * sin(angle) + vector.y * cos(angle);
	return (ret);
}
