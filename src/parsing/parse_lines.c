/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marferri <marferri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 00:00:00 by marferri          #+#    #+#             */
/*   Updated: 2026/07/29 00:00:00 by marferri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include <errno.h>

static char	*next_scene_line(int fd)
{
	errno = 0;
	return (get_next_line(fd));
}

static int	collect_map_line(t_list **map_lines, const char *line)
{
	char	*copy;
	t_list	*node;
	size_t	len;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		len--;
	copy = ft_strndup(line, len);
	if (copy == NULL)
		return (cub_error("malloc failed"));
	node = ft_lstnew(copy);
	if (node == NULL)
		return (free(copy), cub_error("malloc failed"));
	ft_lstadd_back(map_lines, node);
	return (0);
}

static int	process_config_line(const char *line, t_line_type type,
		t_scene *scene, int *seen)
{
	char	*content;
	int		ok;

	if (seen[type])
		return (cub_error("duplicate scene element"));
	content = get_line_content(line, type);
	if (content == NULL)
		return (cub_error("malloc failed"));
	if (type <= LINE_EA)
		ok = parse_texture_line(content, &scene->texture_paths[type]);
	else if (type == LINE_F)
		ok = parse_color_line(content, &scene->floor);
	else
		ok = parse_color_line(content, &scene->ceiling);
	free(content);
	if (!ok)
		return (cub_error("invalid scene element value"));
	seen[type] = 1;
	return (0);
}

static int	read_lines_loop(int fd, t_scene *scene, int *seen,
		t_list **map_lines)
{
	char		*line;
	t_line_type	type;
	int			status;

	status = 0;
	line = next_scene_line(fd);
	while (line != NULL)
	{
		type = get_line_type(line);
		if (*map_lines != NULL && type == LINE_EMPTY)
			status = cub_error("empty line after map");
		else if (*map_lines != NULL || type == LINE_MAP)
			status = collect_map_line(map_lines, line);
		else if (type == LINE_INVALID)
			status = cub_error("invalid line in scene file");
		else if (type != LINE_EMPTY)
			status = process_config_line(line, type, scene, seen);
		free(line);
		if (status != 0)
			break ;
		line = next_scene_line(fd);
	}
	return (status);
}

int	read_scene_lines(int fd, t_scene *scene)
{
	t_list	*map_lines;
	int		seen[LINE_MAP];
	int		status;

	map_lines = NULL;
	ft_memset(seen, 0, sizeof(seen));
	status = read_lines_loop(fd, scene, seen, &map_lines);
	if (status == 0 && errno != 0)
		status = cub_error("cannot read scene file");
	if (status == 0)
		status = check_scene_complete(seen, map_lines);
	if (status == 0)
		status = list_to_map(map_lines, scene);
	if (status != 0)
		get_next_line(-1);
	if (status != 0)
		free_map_lines(map_lines);
	return (status);
}
