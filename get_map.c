/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 10:47:12 by trarijam          #+#    #+#             */
/*   Updated: 2024/05/27 14:32:24 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

char	**get_map(char *path_map)
{
	char	*line;
	char	**map;
	char	*all_lines;
	char	*tmp;
	int		fd;

	fd = open(path_map, O_RDONLY);
	all_lines = NULL;
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (all_lines == NULL)
		{
			all_lines = ft_strdup(line);
			free(line);
		}
		else
		{
			tmp = all_lines;
			all_lines = ft_strjoin(all_lines, line);
			free(tmp);
			free(line);
		}
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	map = ft_split(all_lines, '\n');
	free(all_lines);
	return (map);
}
