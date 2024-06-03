#include "../include/so_long.h"

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