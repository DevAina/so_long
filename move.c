/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 14:20:40 by trarijam          #+#    #+#             */
/*   Updated: 2024/05/31 16:07:09 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_nb_collectibale(t_mlx *mlx, void *player)
{
	t_coord coord;

	coord = get_coord(mlx->map.map, 'E');
	ft_printf("Collectible: %d\n", mlx->map.nb_collectibale);
	if (mlx->map.nb_collectibale == 0)
	{
		mlx->map.map[coord.y][coord.x] = 'O';
	   render_map(mlx->map.map, mlx, player);	
	}
	
}

void	move_right(t_mlx *mlx)
{
	t_coord	coord;
	t_coord	coord_c;

	coord_c = get_coord(mlx->map.map, 'C');
	coord = get_coord(mlx->map.map, 'P');
	if (mlx->map.map[coord.y][coord.x + 1] != '1')
	{
		ft_printf(BLUE "Total movement count: %d\n" RESET_COLOR, mlx->move += 1);
		mlx->map.map[coord.y][coord.x + 1] = 'P';
		mlx->map.map[coord.y][coord.x] = '0';
		if (coord_c.x == coord.x && coord_c.y == coord.y)
			mlx->map.nb_collectibale -= 1;
		check_nb_collectibale(mlx, mlx->img.player_right);
		render_map(mlx->map.map, mlx, mlx->img.player_right);
	}
}

void	move_left(t_mlx *mlx)
{
	t_coord	coord;
	t_coord	coord_c;

	coord_c = get_coord(mlx->map.map, 'C');
	coord = get_coord(mlx->map.map, 'P');
	if (mlx->map.map[coord.y][coord.x - 1] != '1')
	{
		ft_printf(BLUE "Total movement count: %d\n" RESET_COLOR, mlx->move += 1);
		mlx->map.map[coord.y][coord.x - 1] = 'P';
		mlx->map.map[coord.y][coord.x] = '0';
		if (coord_c.x == coord.x && coord_c.y == coord.y)
			mlx->map.nb_collectibale -= 1;
		check_nb_collectibale(mlx, mlx->img.player_left);
		render_map(mlx->map.map, mlx, mlx->img.player_left);
	}	
}

void	move_up(t_mlx *mlx)
{
	t_coord	coord;
	t_coord	coord_c;

	coord_c = get_coord(mlx->map.map, 'C');
	coord = get_coord(mlx->map.map, 'P');
	if (mlx->map.map[coord.y - 1][coord.x] != '1')
	{
		ft_printf(BLUE "Total movement count: %d\n" RESET_COLOR, mlx->move += 1);
		mlx->map.map[coord.y - 1][coord.x] = 'P';
		mlx->map.map[coord.y][coord.x] = '0';
		if (coord_c.x == coord.x && coord_c.y == coord.y)
			mlx->map.nb_collectibale -= 1;
		check_nb_collectibale(mlx, mlx->img.player_back);
		render_map(mlx->map.map, mlx, mlx->img.player_back);
	}
}

void	move_down(t_mlx *mlx)
{
	t_coord	coord;
	t_coord	coord_c;

	coord_c = get_coord(mlx->map.map, 'C');
	coord = get_coord(mlx->map.map, 'P');
	if (mlx->map.map[coord.y + 1][coord.x] != '1')
	{
		ft_printf(BLUE "Total movement count: %d\n" RESET_COLOR, mlx->move += 1);
		mlx->map.map[coord.y + 1][coord.x ] = 'P';
		mlx->map.map[coord.y][coord.x] = '0';
		if (coord_c.x == coord.x && coord_c.y == coord.y)
			mlx->map.nb_collectibale -= 1;
		check_nb_collectibale(mlx, mlx->img.player_front);
		render_map(mlx->map.map, mlx, mlx->img.player_front);
	}
}
