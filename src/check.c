/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyukang <kyukang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:06:44 by kyukang           #+#    #+#             */
/*   Updated: 2024/08/27 14:37:14 by kyukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	count_parameters(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.columns)
		{
			if (!ft_strchr("CEP01", game->map.full[y][x]))
				error_msg("[ERROR]Map has unexpected parameter.\n", game);
			else if (game->map.full[y][x] == PLAYER)
			{
				game->map.players++;
				game->map.player.x = x;
				game->map.player.y = y;
			}
			else if (game->map.full[y][x] == ITEM)
				game->map.item++;
			else if (game->map.full[y][x] == EXIT)
				game->map.exit++;
			x++;
		}
		y++;
	}
}

void	check_parameters(t_game *game)
{
	count_parameters(game);
	if (game->map.item == 0)
		error_msg("[ERROR]No Item on the map.\n", game);
	else if (game->map.exit == 0)
		error_msg("[ERROR]No Exit on the map.\n", game);
	else if (game->map.players != 1)
		error_msg("[ERROR]Player should be always 1.\n", game);
}

void	check_walls(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.rows)
	{
		if (i == 0 || i == game->map.rows - 1)
		{
			j = 0;
			while (j < game->map.columns)
			{
				if (game->map.full[i][j] != WALL)
					error_msg("[ERROR]Map has imperfect wall.\n", game);
				j++;
			}
		}
		else
		{
			if (game->map.full[i][0] != WALL
				|| game->map.full[i][game->map.columns - 1] != WALL)
				error_msg("[ERROR]Map has imperfect wall.\n", game);
		}
		i++;
	}
}

void	check_empty_line(char *map, t_game *game)
{
	int	i;

	i = 0;
	if (map[0] == '\n' || map[ft_strlen(map) - 1] == '\n')
	{
		free(map);
		error_msg("[ERROR]There is an empty line on the map.\n", game);
	}
	while (map[i + 1])
	{
		if (map[i] == '\n' && map[i + 1] == '\n')
		{
			free(map);
			error_msg("[ERROR]There is an empty line on the map.\n", game);
		}
		i++;
	}
}

void	check_arguments(int argc, char **argv, t_game *game)
{
	int	arg_len;

	game->map_alloc = false;
	if (argc > 2)
		error_msg("[ERROR]Too many arguments.\n", game);
	if (argc < 2)
		error_msg("[ERROR]Map file is missed.\n", game);
	arg_len = ft_strlen(argv[1]);
	if (!ft_strnstr(&argv[1][arg_len - 4], ".ber", 4))
		error_msg("[ERROR]Map file has wrong extension.\n", game);
}
