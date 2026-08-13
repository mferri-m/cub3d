/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marferri <marferri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 00:00:00 by marferri          #+#    #+#             */
/*   Updated: 2026/07/29 00:00:00 by marferri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "cub3d.h"
# include "libft.h"

# define RGB_MAX_VALUE 255

typedef enum e_line_type
{
	LINE_NO,
	LINE_SO,
	LINE_WE,
	LINE_EA,
	LINE_F,
	LINE_C,
	LINE_MAP,
	LINE_EMPTY,
	LINE_INVALID
}	t_line_type;

t_line_type	get_line_type(const char *line);
char		*get_line_content(const char *line, t_line_type type);
int			parse_texture_line(const char *content, char **dest);
int			parse_color_line(const char *content, t_color *color);
int			read_scene_lines(int fd, t_scene *scene);
int			check_scene_complete(int *seen, t_list *map_lines);
void		free_map_lines(t_list *map_lines);
int			list_to_map(t_list *map_lines, t_scene *scene);

int			compute_map_width(t_scene *scene);
char		get_map_char(t_scene *scene, int width, int row, int col);
int			validate_map_border(t_scene *scene);
int			validate_map_chars(t_scene *scene, t_player *player);
void		set_player_spawn(t_player *player, int row, int col, char c);

typedef struct s_map_ctx
{
	t_scene	*scene;
	int		width;
	int		*visited;
}	t_map_ctx;

typedef struct s_bfs_queue
{
	t_list	*head;
	t_list	*tail;
}	t_bfs_queue;

int			is_map_closed(t_scene *scene, int width,
				int spawn_row, int spawn_col);
int			validate_map(t_scene *scene, t_player *player);

#endif
