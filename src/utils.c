/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyukang <kyukang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 14:54:25 by kyukang           #+#    #+#             */
/*   Updated: 2024/08/27 14:26:22 by kyukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	free_map(t_game *game)
{
	int	str;

	str = 0;
	while (str < game->map.rows)
		free(game->map.full[str++]);
	free(game->map.full);
}

void	free_malloc(t_game *game)
{
	mlx_destroy_image(game->mlx, game->wall.xpm);
	mlx_destroy_image(game->mlx, game->space.xpm);
	mlx_destroy_image(game->mlx, game->item.xpm);
	mlx_destroy_image(game->mlx, game->player.xpm);
	mlx_destroy_image(game->mlx, game->exit_opened.xpm);
	mlx_destroy_image(game->mlx, game->exit_closed.xpm);
	free_map(game);
	mlx_destroy_window(game->mlx, game->window);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free(game);
}

int	error_msg(char *msg, t_game *game)
{
	if (game->map_alloc == true)
		free_map(game);
	free(game);
	ft_printf("%s", msg);
	exit(EXIT_FAILURE);
}

int	win_msg(t_game *game)
{
	ft_printf("\
	██╗   ██╗ ██████╗ ██╗   ██╗    ██╗    ██╗██╗███╗   ██╗██╗\n \
	╚██╗ ██╔╝██╔═══██╗██║   ██║    ██║    ██║██║████╗  ██║██║\n \
	 ╚████╔╝ ██║   ██║██║   ██║    ██║ █╗ ██║██║██╔██╗ ██║██║\n \
	  ╚██╔╝  ██║   ██║██║   ██║    ██║███╗██║██║██║╚██╗██║╚═╝\n \
	   ██║   ╚██████╔╝╚██████╔╝    ╚███╔███╔╝██║██║ ╚████║██╗\n \
	   ╚═╝    ╚═════╝  ╚═════╝      ╚══╝╚══╝ ╚═╝╚═╝  ╚═══╝╚═╝\n");
	ft_printf("	Your movement: %d steps\n", ++game->move);
	free_malloc(game);
	exit (EXIT_FAILURE);
}
