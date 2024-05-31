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

void	destroy_image(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx_ptr, mlx->img.player_front);
	mlx_destroy_image(mlx->mlx_ptr, mlx->img.player_back);
	mlx_destroy_image(mlx->mlx_ptr, mlx->img.player_left);
	mlx_destroy_image(mlx->mlx_ptr, mlx->img.player_right);
	mlx_destroy_image(mlx->mlx_ptr, mlx->img.tile);
	mlx_destroy_image(mlx->mlx_ptr, mlx->img.wall);
	mlx_destroy_image(mlx->mlx_ptr, mlx->img.door_open);
	mlx_destroy_image(mlx->mlx_ptr, mlx->img.door_close);
	mlx_destroy_image(mlx->mlx_ptr, mlx->img.collectibale);
}

int	handle_key(int keysym, t_mlx *mlx)
{
	if (keysym == XK_Escape)
	{
		ft_printf("state escape: ON\n");
		destroy_image(mlx);
		free(mlx->mlx_ptr);
		free_split(mlx->map.map);
		exit(0);
	}
	if (keysym == XK_d)
		move_right(mlx);
	else if (keysym == XK_a)
		move_left(mlx);
	else if (keysym == XK_s)
		move_down(mlx);
	else if (keysym == XK_w)
		move_up(mlx);
	return (0);
}


void	init_img(t_mlx *mlx)
{
	int	width;
	int	height;

	mlx->img.player_front = mlx_xpm_file_to_image(mlx->mlx_ptr, "player_front.xpm", &width, &height);
	mlx->img.player_back = mlx_xpm_file_to_image(mlx->mlx_ptr, "player_back.xpm", &width, &height);
	mlx->img.player_left = mlx_xpm_file_to_image(mlx->mlx_ptr, "player_left.xpm", &width, &height);
	mlx->img.player_right = mlx_xpm_file_to_image(mlx->mlx_ptr, "player_right.xpm", &width, &height);
	mlx->img.tile = mlx_xpm_file_to_image(mlx->mlx_ptr, "tile.xpm", &width, &height);
	mlx->img.wall = mlx_xpm_file_to_image(mlx->mlx_ptr, "wall.xpm", &width, &height);
	mlx->img.door_close = mlx_xpm_file_to_image(mlx->mlx_ptr, "door_close.xpm", &width, &height);
	mlx->img.door_open = mlx_xpm_file_to_image(mlx->mlx_ptr, "door_open.xpm", &width, &height);
	mlx->img.collectibale = mlx_xpm_file_to_image(mlx->mlx_ptr, "collectibale.xpm", &width, &height);
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

int	main()
{
	t_mlx mlx;

	mlx.map.map = get_map("test.ber");
	check_map(mlx.map.map, "test.ber");
	mlx.map.width = get_width(mlx.map.map) * 64;
	mlx.map.length = ft_strlen(mlx.map.map[0]) * 64;
	mlx.move = 0;
	mlx.map.nb_collectibale = get_nb_collectibale(mlx.map.map);
	mlx.mlx_ptr = mlx_init();
	if (mlx.mlx_ptr == NULL)
		return (1);
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, mlx.map.length, mlx.map.width, "so_long");
	if (mlx.win_ptr == NULL)
	{
		mlx_destroy_display(mlx.mlx_ptr);
		free(mlx.mlx_ptr);
		return (1);
	}
	init_img(&mlx);
	render_map(mlx.map.map, &mlx, mlx.img.player_right);
	mlx_hook(mlx.win_ptr, KeyPress, KeyPressMask, &handle_key, &mlx);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
