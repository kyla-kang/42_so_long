/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyukang <kyukang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 14:44:01 by kyukang           #+#    #+#             */
/*   Updated: 2024/09/16 15:27:25 by kyukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	check_arguments(argc, argv, game);
	init_map(game, argv[1]);
	check_parameters(game);
	check_walls(game);
	init_mlx(game);
	init_sprites(game);
	rendor_map(game);
	mlx_hook(game->window, KeyPress, KeyPressMask, move_player, game);
	mlx_hook(game->window, DestroyNotify, ButtonPressMask, close_game, game);
	mlx_hook(game->window, Expose, ExposureMask, rendor_map, game);
	mlx_loop(game->mlx);
	free_malloc(game);
}
