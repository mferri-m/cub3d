/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_finalize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marferri <marferri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 00:00:00 by marferri          #+#    #+#             */
/*   Updated: 2026/07/29 00:00:00 by marferri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	check_scene_complete(int *seen, t_list *map_lines)
{
	int	i;

	i = 0;
	while (i < LINE_MAP)
	{
		if (!seen[i])
			return (cub_error("missing scene element"));
		i++;
	}
	if (map_lines == NULL)
		return (cub_error("missing map in scene file"));
	return (0);
}

void	free_map_lines(t_list *map_lines)
{
	t_list	*next;

	while (map_lines != NULL)
	{
		next = map_lines->next;
		free(map_lines->content);
		free(map_lines);
		map_lines = next;
	}
}

int	list_to_map(t_list *map_lines, t_scene *scene)
{
	t_list	*node;
	t_list	*next;
	int		i;

	scene->height = ft_lstsize(map_lines);
	scene->map = malloc(sizeof(char *) * (scene->height + 1));
	if (scene->map == NULL)
		return (cub_error("malloc failed"));
	node = map_lines;
	i = 0;
	while (node != NULL)
	{
		scene->map[i++] = (char *)node->content;
		next = node->next;
		free(node);
		node = next;
	}
	scene->map[i] = NULL;
	return (0);
}
