#include "so_long.h"

void	init_img(t_game *game)
{
	int	width;
	int	height;

	game->img.player_front = mlx_xpm_file_to_image(game->mlx_ptr,
			"player_front.xpm", &width, &height);
	game->img.player_back = mlx_xpm_file_to_image(game->mlx_ptr,
			"player_back.xpm", &width, &height);
	game->img.player_left = mlx_xpm_file_to_image(game->mlx_ptr,
			"player_left.xpm", &width, &height);
	game->img.player_right = mlx_xpm_file_to_image(game->mlx_ptr,
			"player_right.xpm", &width, &height);
	game->img.tile = mlx_xpm_file_to_image(game->mlx_ptr,
			"tile.xpm", &width, &height);
	game->img.wall = mlx_xpm_file_to_image(game->mlx_ptr,
			"wall.xpm", &width, &height);
	game->img.door_close = mlx_xpm_file_to_image(game->mlx_ptr,
			"door_close.xpm", &width, &height);
	game->img.door_open = mlx_xpm_file_to_image(game->mlx_ptr,
			"door_open.xpm", &width, &height);
	game->img.collectibale = mlx_xpm_file_to_image(game->mlx_ptr,
			"collectibale.xpm", &width, &height);
}

int	get_nb_collectibale(char **map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

t_game	init_game(char *path_map)
{
	t_game	game;

	game.map.map = get_map(path_map);
	check_map(game.map.map, path_map);
	game.map.width = get_width(game.map.map) * 64;
	game.map.length = ft_strlen(game.map.map[0]) * 64;
	game.move = 0;
	game.map.nb_collectibale = get_nb_collectibale(game.map.map);
	game.map.exit = get_coord(game.map.map, 'E');
	game.mlx_ptr = mlx_init();
	if (game.mlx_ptr == NULL)
		exit(1);
	game.win_ptr = mlx_new_window(game.mlx_ptr, game.map.length, game.map.width, "so_long");
	if (game.win_ptr == NULL)
	{
		mlx_destroy_display(game.mlx_ptr);
		free(game.mlx_ptr);
		exit(1);
	}
	init_img(&game);
	return (game);
}
