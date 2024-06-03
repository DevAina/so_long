#include "../include/so_long.h"

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i] != NULL)
	{
		free(split[i]);
		i++;
	}
	free(split);
}

t_coord	get_coord(char **map, char character_symbol)
{
	t_coord	coord;
	int		y;
	int		x;

	y = 0;
	coord.x = -1;
	coord.y = -1;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == character_symbol)
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

void	define_size(t_game *game)
{
	int	length;
	int	width;

	length = ft_strlen(game->map.map[0]) * 64;
	width = get_width(game->map.map) * 64;
	if (length > 1920 || width > 1080)
	{
		game->map.width = length = get_width(game->map.map) * 32;
		game->map.length = ft_strlen(game->map.map[0]) * 32;
		game->img.size = 32;
	}
	else
	{
		game->img.size = 64;
		game->map.width = width;
		game->map.length = length;
	}
}

void	ft_free(t_game *game)
{
	destroy_image(game);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	free_split(game->map.map);
}