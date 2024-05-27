/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 10:33:02 by trarijam          #+#    #+#             */
/*   Updated: 2024/05/27 16:01:30 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/*typedef struct s_img
{
	void	*img;
	void	*img_back_ground;
}	t_img;*/

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
	void	*img_background;
	char	**map;	
}	t_mlx;

# include "./ft_printf/includes/ft_printf.h"
# include "./get_next_line/get_next_line.h"
# include "minilibx-linux/mlx.h"
# include <X11/keysym.h>

char	**get_map(char *path_map);
int		check_rectangular_map(char **map);

#endif
