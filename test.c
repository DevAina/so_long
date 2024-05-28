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

int	handle_key(int keysym, t_mlx *mlx)
{
	static int	mouve;
	static int	x;
	static int	y;
	static int	back;
	static int	back_y;
	
	if (keysym == XK_Escape)
	{
		printf("state escape: ON\n");
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
		mlx_destroy_image(mlx->mlx_ptr, mlx->img);
		mlx_destroy_image(mlx->mlx_ptr, mlx->img_background);
		mlx_destroy_display(mlx->mlx_ptr);
		free(mlx->mlx_ptr);
		free_split(mlx->map);
		//free(mlx->img);
		exit(0);
	}
	if (keysym == XK_d && x + 64 < 512)
	{
		mouve += 1;
		ft_printf("Mouve: %d\n", mouve);
		if (x <= 0)
			back = 0;
		else
			back = x;
		x += 64;
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_background, back, y);
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img, x, y);
	}
	else if (keysym == XK_a && x > 0 && x - 64 >= 0)
	{
		mouve += 1;
		ft_printf("Mouve: %d\n", mouve); 
		back = x;
		x -= 64;
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_background, back, y);
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img, x, y); 
	}
	else if (keysym == XK_s && y + 64 < 512)
	{
		mouve += 1;
		ft_printf("Mouve: %d\n", mouve); 
		back_y = y;
		y += 64;
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_background, x, back_y);
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img, x, y);
	}
	else if (keysym == XK_w && y > 0)
	{
		mouve += 1;
		ft_printf("Mouve: %d\n", mouve); 
		back_y = y;
		y -= 64;
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_background, x, back_y);
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img, x, y);
	}
	return (0);
}

int	main()
{
	t_mlx mlx;
	int	width;
	int	height;
	int	width_1;
	int	height_1;

	mlx.map = get_map("test.ber");
	if (check_rectangular_map(mlx.map) && check_nb_character(mlx.map)
				&& check_character(mlx.map)
				&& check_map_surronded_by_walls(mlx.map)
				&& is_path_valid("test.ber"))
		ft_printf("map: ok\n");
	mlx.mlx_ptr = mlx_init();
	if (mlx.mlx_ptr == NULL)
		return (1);
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, 512, 512, "test");
	if (mlx.win_ptr == NULL)
	{
		mlx_destroy_display(mlx.mlx_ptr);
		free(mlx.mlx_ptr);
		return (1);
	}
	mlx.img = mlx_xpm_file_to_image(mlx.mlx_ptr, "vaisseau.xpm", &width, &height);
	printf("width: %d   heaight: %d\n", width, height);
	mlx.img_background = mlx_xpm_file_to_image(mlx.mlx_ptr, "background.xpm", &width_1, &height_1);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.img, 0, 0);
	mlx_key_hook(mlx.win_ptr, &handle_key, &mlx);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
