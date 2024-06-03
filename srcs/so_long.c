/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 09:36:17 by trarijam          #+#    #+#             */
/*   Updated: 2024/06/03 14:16:34 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
		free_split(game->map.map);
		exit(0);
	}
	if (keysym == XK_d)
		move_right(game);
	else if (keysym == XK_a)
		move_left(game);
	else if (keysym == XK_s)
		move_down(game);
	else if (keysym == XK_w)
		move_up(game);
	return (0);
}

int	close_window(t_game *game)
{
	ft_free(game);
	exit(0);
	return (0);
}

int	check_argument(int argc)
{
	if (argc == 2)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game game;

	if (check_argument(argc) == 0)
	{
		ft_printf(RED_COLOR "Error\n"
				"There is either no argument or several arguments"
			   " (you must pass only one argument).\n" RESET_COLOR);
		return (1);
	}
	game = init_game(argv[1]);
	render_map(game.map.map, &game, game.img.player_right);
	mlx_hook(game.win_ptr, KeyPress, KeyPressMask, &handle_key, &game);
	mlx_hook(game.win_ptr, 17, 0, close_window, &game);
	mlx_loop(game.mlx_ptr);
	return (0);
}
