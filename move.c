/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 14:20:40 by trarijam          #+#    #+#             */
/*   Updated: 2024/06/03 14:18:43 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_nb_collectibale(t_game *game, void *player)
{
	t_coord coord;

	coord = get_coord(game->map.map, 'E');
	if (coord.y < 0 && coord.x < 0)
		return ;
	if (game->map.nb_collectibale == 0)
	{
		game->map.map[coord.y][coord.x] = 'O';
	   render_map(game->map.map, game, player);	
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

void	is_win(t_coord coord, t_game *game, char symbol)
{
	t_coord	pos_player_current;

	if (symbol != 'O')
		return ;
	pos_player_current = get_coord(game->map.map, 'P');
	if (coord.x == pos_player_current.x
			&& coord.y == pos_player_current.y)
	{
		ft_free(game);
		ft_printf("🎉🎉 YOU WON 🎊🎊\n");
		exit(0);
	}
}

void	move_right(t_game *game)
{
	t_coord	coord;
	char	prev;

	coord = get_coord(game->map.map, 'P');
	if (game->map.map[coord.y][coord.x + 1] != '1')
	{
		ft_printf(BLUE "Total movement count: %d\n" RESET_COLOR, game->move += 1);
		prev = game->map.map[coord.y][coord.x + 1];
		game->map.map[coord.y][coord.x + 1] = 'P';
		if (game->map.exit.x == coord.x && game->map.exit.y == coord.y)
			game->map.map[coord.y][coord.x] = 'E';
		else
			game->map.map[coord.y][coord.x] = '0';
		if (prev == 'C')
			game->map.nb_collectibale -= 1;
		render_map(game->map.map, game, game->img.player_right);
		check_nb_collectibale(game, game->img.player_right);
		coord.x += 1;
		is_win(coord, game, prev);
	}
}

void	move_left(t_game *game)
{
	t_coord	coord;
	char	prev;

	coord = get_coord(game->map.map, 'P');
	if (game->map.map[coord.y][coord.x - 1] != '1')
	{
		ft_printf(BLUE "Total movement count: %d\n" RESET_COLOR, game->move += 1);
		prev = game->map.map[coord.y][coord.x - 1];
		game->map.map[coord.y][coord.x - 1] = 'P';
		if (coord.x == game->map.exit.x && coord.y == game->map.exit.y)
			game->map.map[coord.y][coord.x] = 'E';
		else
			game->map.map[coord.y][coord.x] = '0';
		if (prev == 'C')
			game->map.nb_collectibale -= 1;
		render_map(game->map.map, game, game->img.player_left);
		check_nb_collectibale(game, game->img.player_right);
		coord.x -= 1;
		is_win(coord, game, prev);
	}	
}

void	move_up(t_game *game)
{
	t_coord	coord;
	char	prev;

	coord = get_coord(game->map.map, 'P');
	if (game->map.map[coord.y - 1][coord.x] != '1')
	{
		ft_printf(BLUE "Total movement count: %d\n" RESET_COLOR, game->move += 1);
		prev = game->map.map[coord.y - 1][coord.x];
		game->map.map[coord.y - 1][coord.x] = 'P';
		if (game->map.exit.x == coord.x && game->map.exit.y == coord.y)
			game->map.map[coord.y][coord.x] = 'E';
		else
			game->map.map[coord.y][coord.x] = '0';
		if (prev == 'C')
			game->map.nb_collectibale -= 1;
		render_map(game->map.map, game, game->img.player_back);
		check_nb_collectibale(game, game->img.player_right);
		coord.y -= 1;
		is_win(coord, game, prev);
	}
}

void	move_down(t_game *game)
{
	t_coord	coord;
	char	prev;

	coord = get_coord(game->map.map, 'P');
	if (game->map.map[coord.y + 1][coord.x] != '1')
	{
		ft_printf(BLUE "Total movement count: %d\n" RESET_COLOR, game->move += 1);
		prev = game->map.map[coord.y + 1][coord.x];
		game->map.map[coord.y + 1][coord.x ] = 'P';
		if (game->map.exit.x == coord.x && game->map.exit.y == coord.y)
			game->map.map[coord.y][coord.x] = 'E';
		else
			game->map.map[coord.y][coord.x] = '0';
		if (prev == 'C')
			game->map.nb_collectibale -= 1;
		render_map(game->map.map, game, game->img.player_front);
		check_nb_collectibale(game, game->img.player_right);
		coord.y += 1;
		is_win(coord, game, prev);
	}
}
