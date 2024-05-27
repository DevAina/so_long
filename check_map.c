/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 09:54:48 by trarijam          #+#    #+#             */
/*   Updated: 2024/05/27 16:13:43 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_width(char **map)
{
	int	width;

	width = 0;
	while (map[width] != NULL)
		width++;
	return (width);
}

int	check_all_lenght_is_same(char **map)
{
	int	i;
	int	lenght;

	lenght = ft_strlen(map[0]);
	i = 1;
	while (map[i] != NULL)
	{
		if (lenght != ft_strlen(map[i]))
			return (1);
		i++;
	}
	return (0);
}

int	check_rectangular_map(char **map)
{
	int width;
	int	lenght;

	width = get_width(map);
	lenght = ft_strlen(map[0]);
	if (width != lenght && check_all_lenght_is_same(map) != 1)
		return (1);
	return (0);
}

int	check_character(char **map)
{
	int	*count_character[3];
	int	i;
	int	j;

	i = 0;
	while (i < 3)
	{
		count_character[i] = 0;
		i++;
	}
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
