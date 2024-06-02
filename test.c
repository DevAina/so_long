#include "so_long.h"

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

void	destroy_image(t_game *game)
{
	mlx_destroy_image(game->mlx_ptr, game->img.player_front);
	mlx_destroy_image(game->mlx_ptr, game->img.player_back);
	mlx_destroy_image(game->mlx_ptr, game->img.player_left);
	mlx_destroy_image(game->mlx_ptr, game->img.player_right);
	mlx_destroy_image(game->mlx_ptr, game->img.tile);
	mlx_destroy_image(game->mlx_ptr, game->img.wall);
	mlx_destroy_image(game->mlx_ptr, game->img.door_open);
	mlx_destroy_image(game->mlx_ptr, game->img.door_close);
	mlx_destroy_image(game->mlx_ptr, game->img.collectibale);
}

int	handle_key(int keysym, t_game *game)
{
	if (keysym == XK_Escape)
	{
		destroy_image(game);
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
		free_split(game->map.map);
		exit(0);
	}
	if (keysym == XK_d)
		move_right(game);
	else if (keysym == XK_q)
		move_left(game);
	else if (keysym == XK_s)
		move_down(game);
	else if (keysym == XK_z)
		move_up(game);
	return (0);
}

int	close_window(t_game *game)
{
	ft_free(game);
	exit(0);
	return (0);
}

int	main()
{
	t_game game;

	game = init_game("test.ber");
	render_map(game.map.map, &game, game.img.player_right);
	mlx_hook(game.win_ptr, KeyPress, KeyPressMask, &handle_key, &game);
	mlx_hook(game.win_ptr, 17, 0, close_window, &game);
	mlx_loop(game.mlx_ptr);
	return (0);
}
