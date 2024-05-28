/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 09:54:48 by trarijam          #+#    #+#             */
/*   Updated: 2024/05/28 15:41:46 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_coord get_coord(char **map, char character_icon)
{
	t_coord coord;
	int	y;
	int	x;

	y = 0;
	coord.x = -1;
	coord.y = -1;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == character_icon)
			{
				coord.x = x;
				coord.y = y;
				return (coord);
			}
			x++;
		}
		y++;
	}
	return (coord);
}

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
		if (lenght != (int)ft_strlen(map[i]))
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
	ft_printf(RED_COLOR "The map is not rectangular.\n" RESET_COLOR);
	return (0);
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
	if (count_character[0] == 1 && count_character[1] >= 1 && count_character[2] == 1)
		return (1);
	ft_printf(RED_COLOR "The map contains either multiple exits, no items, or multiple starting positions.\n" RESET_COLOR);
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
				ft_printf("Other character: %c\n", map[i][j]);
				ft_printf(RED_COLOR "The map contains characters other than: '1', '0', 'P', 'C', 'E'\n" RESET_COLOR);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int cols_is_wall(char **map, int index)
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

int	line_is_it_wall(char **map, int index)
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

int	check_map_surronded_by_walls(char **map)
{
	int	width;

	width = get_width(map);
	if (cols_is_wall(map, 0) && cols_is_wall(map, ft_strlen(map[0]) - 1)
			&& line_is_it_wall(map, 0) && line_is_it_wall(map, width - 1))
		return (1);
	ft_printf(RED_COLOR "The map is not surronded by walls\n" RESET_COLOR);
	return (0);
}

void	fill_zone(int x, int y, t_coord size, char **tab)
{
	if (x < 0 || x >= size.x || y < 0 || y >= size.y)
		return ;
	if (tab[y][x] == '0' || tab[y][x] == 'C' || tab[y][x] == 'E' || tab[y][x] == 'P')
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
    char fill_char;

	fill_char = tab[begin.y][begin.x];
	if (fill_char == 'F')
		return ;
	fill_zone(begin.x, begin.y, size, tab);
}

int check_path_valid(char **map)
{
	int i;
	int j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'F')
			{
				ft_printf("Other character %c\n", map[i][j]);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	is_path_valid(char *path_map)
{
	char    **tmp;
	t_coord player;
	t_coord size;

	tmp = get_map(path_map);
	size.x = ft_strlen(tmp[0]);
	size.y = get_width(tmp);
	player = get_coord(tmp, 'P');
	flood_fill(tmp, size, player);
	int i = 0;
	while (tmp[i] != NULL)
	{
		ft_printf("%s\n", tmp[i]);
		i++;
	}
	if (check_path_valid(tmp))
	{
		free_split(tmp);
		return (1);
	}
	free_split(tmp);
	ft_printf(RED_COLOR "There is not path valid\n" RESET_COLOR);
	return (0);
}
