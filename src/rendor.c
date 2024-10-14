/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyukang <kyukang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 16:33:02 by kyukang           #+#    #+#             */
/*   Updated: 2024/10/14 20:17:14 by kyukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	rendor_sprite(t_game *game, t_image sprite, int row, int column)
{
	int	x;
	int	y;

	x = column * sprite.x;
	y = row * sprite.y;
	mlx_put_image_to_window (game->mlx, game->window, sprite.xpm, x, y);
}

void	identify_sprite(t_game *game, int y, int x)
{
	char	param;

	param = game->map.full[y][x];
	if (param == WALL)
		rendor_sprite(game, game->wall, y, x);
	else if (param == SPACE)
		rendor_sprite(game, game->space, y, x);
	else if (param == ITEM)
		rendor_sprite(game, game->item, y, x);
	else if (param == EXIT)
	{
		if (game->map.item == 0)
			rendor_sprite(game, game->exit_opened, y, x);
		else
			rendor_sprite(game, game->exit_closed, y, x);
	}
	else if (param == PLAYER)
		rendor_sprite(game, game->player, y, x);
}

int	rendor_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.columns)
		{
			identify_sprite(game, y, x);
			x++;
		}
		y++;
	}
	return (0);
}
