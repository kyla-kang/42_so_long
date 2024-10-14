/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyukang <kyukang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 14:44:01 by kyukang           #+#    #+#             */
/*   Updated: 2024/10/14 20:30:32 by kyukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		return (1);
	check_arguments(argc, argv, game);
	init_map(game, argv[1]);
	check_parameters(game);
	check_walls(game);
	game->mlx = mlx_init();
	if (!game->mlx)
		error_msg("[ERROR]MLX initialization failed.\n", game);
	init_sprites(game);
	game->window = mlx_new_window(game->mlx, game->map.columns * IMG_WIDTH,
			game->map.rows * IMG_HEIGHT, "so_long");
	if (!game->window)
		error_msg("[ERROR]Window creation failed.\n", game);
	rendor_map(game);
	mlx_hook(game->window, KeyPress, KeyPressMask, move_player, game);
	mlx_hook(game->window, DestroyNotify, ButtonPressMask, close_game, game);
	mlx_hook(game->window, Expose, ExposureMask, rendor_map, game);
	mlx_loop(game->mlx);
	free_malloc(game);
	return (0);
}
