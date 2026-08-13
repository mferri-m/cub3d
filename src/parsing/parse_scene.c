/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marferri <marferri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 00:00:00 by marferri          #+#    #+#             */
/*   Updated: 2026/07/14 00:00:00 by marferri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parsing.h"
#include <fcntl.h>

static int	has_cub_extension(const char *filename);

int	parse_scene(const char *filename, t_game *game)
{
	int	fd;
	int	status;

	if (filename == NULL)
		return (cub_error("missing scene file"));
	if (!has_cub_extension(filename))
		return (cub_error("invalid scene file extension"));
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (cub_error("cannot open scene file"));
	status = read_scene_lines(fd, &game->scene);
	close(fd);
	if (status == 0)
		status = validate_map(&game->scene, &game->player);
	return (status);
}

static int	has_cub_extension(const char *filename)
{
	size_t	len;

	len = ft_strlen(filename);
	if (len < 4)
		return (0);
	return (ft_strncmp(filename + len - 4, ".cub", 4) == 0);
}
