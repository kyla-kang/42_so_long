/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyukang <kyukang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 16:50:28 by kyukang           #+#    #+#             */
/*   Updated: 2024/09/20 15:20:21 by kyukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	close_game(t_game *game)
{
	ft_printf("GAME WINDOW CLOSED.\n");
	ft_printf("Total Movement: %d\n", game->move);
	free_malloc(game);
	exit (EXIT_FAILURE);
}

static void	move(t_game *game, int new_y, int new_x, int player_sprite)
{
	int	last_x;
	int	last_y;

	game->player_sprite = player_sprite;
	last_x = game->map.player.x;
	last_y = game->map.player.y;
	if (game->map.full[new_y][new_x] == EXIT && game->map.item == 0)
		win_msg(game);
	else if ((game->map.full[new_y][new_x] == SPACE)
			|| (game->map.full[new_y][new_x] == ITEM))
	{
		game->map.full[last_y][last_x] = SPACE;
		if (game->map.full[new_y][new_x] == ITEM)
			game->map.item--;
		game->map.player.x = new_x;
		game->map.player.y = new_y;
		game->map.full[new_y][new_x] = PLAYER;
		game->move++;
		rendor_map(game);
		if (game->map.full[new_y][new_x] != game->map.full[last_y][last_x])
			ft_printf("Number of Movement: %d\n", game->move);
	}
}

int	move_player(int keysym, t_game *game)
{
	if (keysym == KEY_UP)
		move(game, game->map.player.y - 1, game->map.player.x, BACK);
	if (keysym == KEY_LEFT)
		move(game, game->map.player.y, game->map.player.x - 1, LEFT);
	if (keysym == KEY_RIGHT)
		move(game, game->map.player.y, game->map.player.x + 1, RIGHT);
	if (keysym == KEY_DOWN)
		move(game, game->map.player.y + 1, game->map.player.x, FRONT);
	if (keysym == KEY_ESC)
		close_game(game);
	return (0);
}
