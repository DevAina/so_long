/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 10:33:02 by trarijam          #+#    #+#             */
/*   Updated: 2024/05/31 15:45:18 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define RESET_COLOR "\033[0m"
# define RED_COLOR "\033[31m"
# define BLUE "\033[34m"

typedef struct s_img
{
	void	*player_front;
	void	*player_back;
	void	*player_right;
	void	*player_left;
	void	*tile;
	void	*door_open;
	void	*door_close;
	void	*wall;
	void	*collectibale;
}	t_img;

typedef struct s_coord
{
	int	x;
	int	y;
}	t_coord;

typedef struct	s_map
{
	char	**map;
	int		nb_collectibale;
	int		width;
	int		length;
}	t_map;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		move;
	t_img	img;
	t_map	map;
}	t_mlx;

# include "./ft_printf/includes/ft_printf.h"
# include "get_next_line.h"
# include "minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <X11/X.h>

void	render_map(char **map, t_mlx *mlx, void	*img_player);
char	**get_map(char *path_map);
t_coord	get_coord(char **map, char character_icon);
int		get_width(char **map);
void	fill_zone(int x, int y, t_coord size, char **tab);
void	flood_fill(char **tab, t_coord size, t_coord begin);
int		check_path_valid(char **map);
int		check_all_lenght_is_same(char **map);
void	count_characters(char **map, int count_character[]);
int		cols_is_wall(char **map, int index);
int		line_is_wall(char **map, int index);
int		check_rectangular_map(char **map);
int		check_nb_character(char **map);
int		check_character(char **map);
int		check_map_surronded_by_walls(char **map);
int		is_path_valid(char **map, char *path_map);
int		check_map(char **map, char *path_map);
void	free_split(char **split);
void	move_right(t_mlx *mlx);
void	move_left(t_mlx *mlx);
void    move_up(t_mlx *mlx);
void    move_down(t_mlx *mlx);

#endif
