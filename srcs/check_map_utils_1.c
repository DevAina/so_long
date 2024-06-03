/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 10:03:46 by trarijam          #+#    #+#             */
/*   Updated: 2024/05/30 11:43:13 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_all_lenght_is_same(char **map)
{
	int	i;
	int	lenght;

	lenght = ft_strlen(map[0]);
	i = 1;
	while (map[i] != NULL)
	{
		if (lenght != (int)ft_strlen(map[i]))
			return (0);
		i++;
	}
	return (1);
}

void	count_characters(char **map, int count_character[])
{
	int	i;
	int	j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'E')
				count_character[0] += 1;
			else if (map[i][j] == 'C')
				count_character[1] += 1;
			else if (map[i][j] == 'P')
				count_character[2] += 1;
			j++;
		}
		i++;
	}
}

int	cols_is_wall(char **map, int index)
{
	int	j;

	j = 0;
	while (j < get_width(map))
	{
		if (map[j][index] != '1')
			return (0);
		j++;
	}
	return (1);
}

int	line_is_wall(char **map, int index)
{
	int	j;

	j = 0;
	while (map[index][j] != '\0')
	{
		if (map[index][j] != '1')
			return (0);
		j++;
	}
	return (1);
}

int	check_map(char **map, char *path_map)
{
	if (check_rectangular_map(map) && check_nb_character(map)
				&& check_character(map)
				&& check_map_surronded_by_walls(map)
				&& is_path_valid(map, path_map))	
		return (1);
	return (0);
}
