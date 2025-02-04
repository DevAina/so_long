/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 09:54:26 by trarijam          #+#    #+#             */
/*   Updated: 2024/05/29 10:59:36 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	fill_zone(int x, int y, t_coord size, char **tab)
{
	if (x < 0 || x >= size.x || y < 0 || y >= size.y)
		return ;
	if (tab[y][x] == '0' || tab[y][x] == 'C' || tab[y][x] == 'E'
			|| tab[y][x] == 'P')
	{
		tab[y][x] = 'F';
		fill_zone(x + 1, y, size, tab);
		fill_zone(x - 1, y, size, tab);
		fill_zone(x, y + 1, size, tab);
		fill_zone(x, y - 1, size, tab);
	}
}

void	flood_fill(char **tab, t_coord size, t_coord begin)
{
	char	fill_char;

	fill_char = tab[begin.y][begin.x];
	if (fill_char == 'F')
		return ;
	fill_zone(begin.x, begin.y, size, tab);
}

int	check_path_valid(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'F')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
