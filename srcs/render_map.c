/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 14:50:53 by trarijam          #+#    #+#             */
/*   Updated: 2024/06/03 14:44:30 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	block_while_for_render_map(int x, int y, t_game *game,
	void *img_player)
{
	if (game->map.map[y / game->img.size][x / game->img.size] == '1')
		mlx_put_image_to_window(game->mlx_ptr,
			game->win_ptr, game->img.wall, x, y);
	if (game->map.map[y / game->img.size][x / game->img.size] == '0')
		 mlx_put_image_to_window(game->mlx_ptr,
		 	game->win_ptr, game->img.tile, x, y);
	if (game->map.map[y / game->img.size][x / game->img.size] == 'C')
		mlx_put_image_to_window(game->mlx_ptr,
			game->win_ptr, game->img.collectibale, x, y);
	if (game->map.map[y / game->img.size][x / game->img.size] == 'P')
		mlx_put_image_to_window(game->mlx_ptr,
			game->win_ptr, img_player, x, y);
	if (game->map.map[y / game->img.size][x / game->img.size] == 'E')
		mlx_put_image_to_window(game->mlx_ptr,
			game->win_ptr, game->img.door_close, x, y);
	if (game->map.map[y / game->img.size][x / game->img.size] == 'O')
		mlx_put_image_to_window(game->mlx_ptr,
			game->win_ptr, game->img.door_open, x, y);	
}


void	render_map(char **map, t_game *game, void *img_player)
{
	int	x;
	int	y;
	int	i;
	int	j;

	i = 0;
	x = 0;
	y = 0;
	while (map[i] != NULL)
	{
		if (i == 0)
			y = 0;
		else
			y += game->img.size;
		j = 0;
		while (map[i][j] != '\0')
		{
			block_while_for_render_map(x, y, game, img_player);
			x += game->img.size;
			j++;
		}
		x = 0;
		i++;
	}
}
