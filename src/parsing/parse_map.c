/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marferri <marferri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 00:00:00 by marferri          #+#    #+#             */
/*   Updated: 2026/07/29 00:00:00 by marferri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	validate_map(t_scene *scene, t_player *player)
{
	int	status;

	scene->width = compute_map_width(scene);
	status = validate_map_chars(scene, player);
	if (status == 0)
		status = validate_map_border(scene);
	if (status == 0)
		status = is_map_closed(scene, scene->width,
				(int)player->y, (int)player->x);
	return (status);
}
