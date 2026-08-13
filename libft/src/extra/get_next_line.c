/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marferri <marferri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 00:00:00 by marferri          #+#    #+#             */
/*   Updated: 2026/07/29 00:00:00 by marferri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

static char	*gnl_free(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
	return (NULL);
}

static char	*gnl_join_free(char *stash, char *buffer)
{
	char	*joined;

	if (stash == NULL)
		stash = ft_strdup("");
	if (stash == NULL)
		return (NULL);
	joined = ft_strjoin(stash, buffer);
	free(stash);
	return (joined);
}

static char	*gnl_read_file(int fd, char *stash)
{
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	bytes_read;

	bytes_read = 1;
	while (bytes_read > 0 && ft_strchr(stash, '\n') == NULL)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(stash);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		if (bytes_read > 0)
			stash = gnl_join_free(stash, buffer);
		if (stash == NULL)
			return (NULL);
	}
	return (stash);
}

static char	*gnl_get_line(char *stash)
{
	char	*line;
	size_t	len;

	if (stash == NULL || stash[0] == '\0')
		return (NULL);
	len = 0;
	while (stash[len] != '\0' && stash[len] != '\n')
		len++;
	if (stash[len] == '\n')
		len++;
	line = malloc(sizeof(char) * (len + 1));
	if (line == NULL)
		return (NULL);
	ft_strlcpy(line, stash, len + 1);
	return (line);
}

static char	*gnl_update_stash(char *stash)
{
	char	*newline;
	char	*next;

	newline = ft_strchr(stash, '\n');
	if (newline == NULL)
	{
		free(stash);
		return (NULL);
	}
	next = ft_strdup(newline + 1);
	free(stash);
	if (next == NULL || next[0] == '\0')
	{
		free(next);
		return (NULL);
	}
	return (next);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (gnl_free(&stash));
	if (stash == NULL)
		stash = ft_strdup("");
	if (stash == NULL)
		return (NULL);
	stash = gnl_read_file(fd, stash);
	if (stash == NULL)
		return (NULL);
	line = gnl_get_line(stash);
	if (line == NULL)
		return (gnl_free(&stash));
	stash = gnl_update_stash(stash);
	return (line);
}
