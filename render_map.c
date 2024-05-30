/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 14:50:53 by trarijam          #+#    #+#             */
/*   Updated: 2024/05/30 15:48:25 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_map(char **map, t_mlx *mlx)
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
			y += 64;
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == '1')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img, x, y);
			x += 64;
			j++;
		}
		x = 0;
		i++;
	}
}
