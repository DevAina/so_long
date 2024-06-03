/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 09:54:48 by trarijam          #+#    #+#             */
/*   Updated: 2024/05/30 11:32:32 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_rectangular_map(char **map)
{
	int	width;
	int	lenght;

	width = get_width(map);
	lenght = ft_strlen(map[0]);
	if (width != lenght && check_all_lenght_is_same(map))
		return (1);
	free_split(map);
	ft_printf(RED_COLOR "Error\nThe map is not rectangular.\n" RESET_COLOR);
	exit(1);
	return (0);
}

int	check_nb_character(char **map)
{
	int	count_character[3];
	int	i;

	i = 0;
	while (i < 3)
	{
		count_character[i] = 0;
		i++;
	}
	count_characters(map, count_character);
	if (count_character[0] == 1 && count_character[1] >= 1
		&& count_character[2] == 1)
		return (1);
	free_split(map);
	ft_printf(RED_COLOR "Error\nThe map contains either multiple "
			"exits, no items or multiple starting positions.\n" RESET_COLOR);
	exit(1);
	return (0);
}

int	check_character(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'P'
					&& map[i][j] != 'C' && map[i][j] != 'E')
			{
				free_split(map);
				ft_printf(RED_COLOR "Error\nThe map contains characters other than:"
					" '1', '0', 'P', 'C', 'E'\n" RESET_COLOR);
				exit(1);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_map_surronded_by_walls(char **map)
{
	int	width;

	width = get_width(map);
	if (cols_is_wall(map, 0) && cols_is_wall(map, ft_strlen(map[0]) - 1)
		&& line_is_wall(map, 0)
		&& line_is_wall(map, width - 1))
		return (1);
	free_split(map);
	ft_printf(RED_COLOR "Error\nThe map is not surronded by walls\n" RESET_COLOR);
	exit(1);
	return (0);
}

int	is_path_valid(char **map, char *path_map)
{
	char	**tmp;
	t_coord	player;
	t_coord	size;

	tmp = get_map(path_map);
	size.x = ft_strlen(tmp[0]);
	size.y = get_width(tmp);
	player = get_coord(tmp, 'P');
	flood_fill(tmp, size, player);
	if (check_path_valid(tmp))
	{
		free_split(tmp);
		return (1);
	}
	free_split(tmp);
	free_split(map);
	ft_printf(RED_COLOR "Error\nThere is not path valid\n" RESET_COLOR);
	exit(1);
	return (0);
}
