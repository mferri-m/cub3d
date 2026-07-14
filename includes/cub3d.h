/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marferri <marferri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 00:00:00 by marferri          #+#    #+#             */
/*   Updated: 2026/07/14 00:00:00 by marferri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <unistd.h>

typedef enum e_direction
{
	NORTH,
	SOUTH,
	WEST,
	EAST
}	t_direction;

typedef struct s_color
{
	int	red;
	int	green;
	int	blue;
	int	value;
}	t_color;

typedef struct s_scene
{
	char	**map;
	int		width;
	int		height;
	char	*texture_paths[4];
	t_color	floor;
	t_color	ceiling;
}	t_scene;

typedef struct s_player
{
	double	x;
	double	y;
	double	direction_x;
	double	direction_y;
	double	plane_x;
	double	plane_y;
}	t_player;

typedef struct s_game
{
	t_scene		scene;
	t_player	player;
	void		*mlx;
	void		*window;
}	t_game;

void	game_init(t_game *game);
void	game_destroy(t_game *game);
int		cub_error(const char *message);
int		parse_scene(const char *filename, t_game *game);
int		render_game(t_game *game);

#endif
