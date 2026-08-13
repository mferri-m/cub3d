/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_identifiers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marferri <marferri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 00:00:00 by marferri          #+#    #+#             */
/*   Updated: 2026/07/29 00:00:00 by marferri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	is_blank_line(const char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	return (line[i] == '\0' || line[i] == '\n');
}

static int	is_separator(char c)
{
	return (c == ' ' || c == '\t');
}

static int	is_map_char(char c)
{
	return (c == '0' || c == '1' || c == 'N' || c == 'S'
		|| c == 'E' || c == 'W');
}

t_line_type	get_line_type(const char *line)
{
	if (is_blank_line(line))
		return (LINE_EMPTY);
	if (ft_strncmp(line, "NO", 2) == 0 && is_separator(line[2]))
		return (LINE_NO);
	if (ft_strncmp(line, "SO", 2) == 0 && is_separator(line[2]))
		return (LINE_SO);
	if (ft_strncmp(line, "WE", 2) == 0 && is_separator(line[2]))
		return (LINE_WE);
	if (ft_strncmp(line, "EA", 2) == 0 && is_separator(line[2]))
		return (LINE_EA);
	if (line[0] == 'F' && is_separator(line[1]))
		return (LINE_F);
	if (line[0] == 'C' && is_separator(line[1]))
		return (LINE_C);
	if (is_map_char(line[0]))
		return (LINE_MAP);
	return (LINE_INVALID);
}

char	*get_line_content(const char *line, t_line_type type)
{
	int	skip;

	skip = 1;
	if (type <= LINE_EA)
		skip = 2;
	while (line[skip] == ' ' || line[skip] == '\t')
		skip++;
	return (ft_strtrim(line + skip, " \t\n"));
}
