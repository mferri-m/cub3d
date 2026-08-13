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

/* Window */
# define WINDOW_WIDTH	800
# define WINDOW_HEIGHT	600
# define WINDOW_TITLE	"cub3D"

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

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_vector
{
	double	x;
	double	y;
}	t_vector;

typedef struct s_rect
{
	t_point	pos;
	int		width;
	int		height;
}	t_rect;

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
	double		x;
	double		y;
	t_vector	direction;
	t_vector	plane;
}	t_player;

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_image;

typedef struct s_window
{
	void	*ptr;
	int		width;
	int		height;
	char	*title;
}	t_window;

typedef struct s_texture
{
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		bpp;
	int		line_length;
	int		endian;
}	t_texture;

typedef struct s_game
{
	t_scene		scene;
	t_player	player;
	void		*mlx;
	t_window	window;
	t_image		image;
	t_texture	textures[4];
}	t_game;

typedef struct s_ray
{
	/* Camera */
	double		camera_x;
	t_vector	ray_dir;
	/* DDA */
	int			map_x;
	int			map_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	int			step_x;
	int			step_y;
	int			side;
	/* Projection */
	double		perp_wall_dist;
	double		line_height;
	int			draw_start;
	int			draw_end;
	int			draw_start_real;
	int			draw_end_real;
	/* Texture */
	double		wall_x;
	int			tex_x;
	/* ray */
	int			screen_column;
}	t_ray;

void	game_init(t_game *game);
void	game_destroy(t_game *game);
int		cub_error(const char *message);
int		parse_scene(const char *filename, t_game *game);

#endif
