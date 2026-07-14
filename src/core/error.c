/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marferri <marferri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 00:00:00 by marferri          #+#    #+#             */
/*   Updated: 2026/07/14 00:00:00 by marferri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static size_t	text_length(const char *text)
{
	size_t	length;

	length = 0;
	while (text[length] != '\0')
		length++;
	return (length);
}

int	cub_error(const char *message)
{
	write(STDERR_FILENO, "Error\n", 6);
	write(STDERR_FILENO, message, text_length(message));
	write(STDERR_FILENO, "\n", 1);
	return (1);
}
