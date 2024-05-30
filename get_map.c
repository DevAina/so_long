/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 10:47:12 by trarijam          #+#    #+#             */
/*   Updated: 2024/05/30 13:55:20 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_extension(char *path_map)
{
	char	*ext;

	ext = ft_substr(path_map, ft_strlen(path_map) - 4, 4);
	if (ft_memcmp(ext, ".ber", 4) != 0)
	{
		free(ext);
		ft_printf(RED_COLOR
				"Error\nExtension of file is not '.ber'\n" RESET_COLOR);
		exit(1);
	}
	free(ext);
}

char	*get_all_lines(int fd)
{
	char	*all_lines;
	char	*line;
	char	*tmp;

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
	close(fd);
	return (all_lines);
}

char	**get_map(char *path_map)
{
	char	**map;
	char	*all_lines;
	int		fd;

	fd = open(path_map, O_RDONLY);
	check_extension(path_map);
	if (fd < 0)
	{
		ft_printf(RED_COLOR "Error\nFailed to open file.\n" RESET_COLOR);
		exit(1);
	}
	all_lines = get_all_lines(fd);
	if (all_lines == NULL)
	{
		ft_printf(RED_COLOR"Error\nWrong lecture map\n");
		exit(1);
	}
	map = ft_split(all_lines, '\n');
	free(all_lines);
	return (map);
}
