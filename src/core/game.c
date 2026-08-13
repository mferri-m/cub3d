/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marferri <marferri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 00:00:00 by marferri          #+#    #+#             */
/*   Updated: 2026/07/14 00:00:00 by marferri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	game_init(t_game *game)
{
	int	index;

	*game = (t_game){0};
	index = 0;
	while (index < 4)
	{
		game->scene.texture_paths[index] = NULL;
		index++;
	}
	game->window.width = WINDOW_WIDTH;
	game->window.height = WINDOW_HEIGHT;
	game->window.title = WINDOW_TITLE;
}

static void	free_map(char **map)
{
	int	row;

	if (map == NULL)
		return ;
	row = 0;
	while (map[row] != NULL)
	{
		free(map[row]);
		row++;
	}
	free(map);
}

void	game_destroy(t_game *game)
{
	int	index;

	free_map(game->scene.map);
	index = 0;
	while (index < 4)
	{
		free(game->scene.texture_paths[index]);
		index++;
	}
}
