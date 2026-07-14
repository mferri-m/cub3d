/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marferri <marferri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 00:00:00 by marferri          #+#    #+#             */
/*   Updated: 2026/07/14 00:00:00 by marferri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_game	game;
	int		status;

	if (argc != 2)
		return (cub_error("usage: ./cub3D <map.cub>"));
	game_init(&game);
	status = parse_scene(argv[1], &game);
	if (status == 0)
		status = render_game(&game);
	game_destroy(&game);
	return (status);
}
