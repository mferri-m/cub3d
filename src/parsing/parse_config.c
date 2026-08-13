/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marferri <marferri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 00:00:00 by marferri          #+#    #+#             */
/*   Updated: 2026/07/29 00:00:00 by marferri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	is_valid_uint(const char *s)
{
	int	i;

	if (s == NULL || s[0] == '\0')
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		if (!ft_isdigit((unsigned char)s[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	parse_color_value(const char *token, int *out)
{
	if (!is_valid_uint(token))
		return (0);
	*out = ft_atoi(token);
	return (*out <= RGB_MAX_VALUE);
}

static void	free_split(char **parts)
{
	int	i;

	if (parts == NULL)
		return ;
	i = 0;
	while (parts[i] != NULL)
		free(parts[i++]);
	free(parts);
}

int	parse_color_line(const char *content, t_color *color)
{
	char	**parts;
	int		ok;

	parts = ft_split(content, ',');
	if (parts == NULL)
		return (0);
	ok = parts[0] && parts[1] && parts[2] && !parts[3];
	if (ok)
		ok = parse_color_value(parts[0], &color->red);
	if (ok)
		ok = parse_color_value(parts[1], &color->green);
	if (ok)
		ok = parse_color_value(parts[2], &color->blue);
	free_split(parts);
	if (ok)
		color->value = (color->red << 16) | (color->green << 8) | color->blue;
	return (ok);
}

int	parse_texture_line(const char *content, char **dest)
{
	if (content[0] == '\0')
		return (0);
	*dest = ft_strdup(content);
	return (*dest != NULL);
}
