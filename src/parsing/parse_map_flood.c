/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_flood.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marferri <marferri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 00:00:00 by marferri          #+#    #+#             */
/*   Updated: 2026/07/29 00:00:00 by marferri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	enqueue_cell(t_bfs_queue *queue, int index)
{
	int		*value;
	t_list	*node;

	value = malloc(sizeof(int));
	if (value == NULL)
		return (cub_error("malloc failed"));
	*value = index;
	node = ft_lstnew(value);
	if (node == NULL)
		return (free(value), cub_error("malloc failed"));
	if (queue->tail == NULL)
		queue->head = node;
	else
		queue->tail->next = node;
	queue->tail = node;
	return (0);
}

static int	visit_neighbor(t_map_ctx *ctx, t_bfs_queue *queue, int row, int col)
{
	char	c;
	int		index;

	c = get_map_char(ctx->scene, ctx->width, row, col);
	if (c == '\0' || c == ' ')
		return (cub_error("map is not closed"));
	if (c == '1')
		return (0);
	index = row * ctx->width + col;
	if (ctx->visited[index])
		return (0);
	ctx->visited[index] = 1;
	return (enqueue_cell(queue, index));
}

static int	flood_from(t_map_ctx *ctx, t_bfs_queue *queue, int start)
{
	const int	dr[4] = {-1, 1, 0, 0};
	const int	dc[4] = {0, 0, -1, 1};
	t_list		*node;
	int			status;
	int			i;

	ctx->visited[start] = 1;
	status = enqueue_cell(queue, start);
	while (status == 0 && queue->head != NULL)
	{
		node = queue->head;
		queue->head = node->next;
		if (queue->head == NULL)
			queue->tail = NULL;
		i = -1;
		while (status == 0 && ++i < 4)
			status = visit_neighbor(ctx, queue,
					*(int *)node->content / ctx->width + dr[i],
					*(int *)node->content % ctx->width + dc[i]);
		free(node->content);
		free(node);
	}
	return (status);
}

int	is_map_closed(t_scene *scene, int width, int spawn_row, int spawn_col)
{
	t_map_ctx	ctx;
	t_bfs_queue	queue;
	int			status;

	ctx.scene = scene;
	ctx.width = width;
	ctx.visited = ft_calloc(scene->height * width, sizeof(int));
	if (ctx.visited == NULL)
		return (cub_error("malloc failed"));
	queue.head = NULL;
	queue.tail = NULL;
	status = flood_from(&ctx, &queue, spawn_row * width + spawn_col);
	free_map_lines(queue.head);
	free(ctx.visited);
	return (status);
}
