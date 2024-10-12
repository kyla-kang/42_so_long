/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyukang <kyukang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:42:43 by kyukang           #+#    #+#             */
/*   Updated: 2024/10/12 18:50:22 by kyukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static t_image	ft_new_sprite(void *mlx, char *path, t_game *game)
{
	t_image	sprite;

	sprite.xpm = mlx_xpm_file_to_image(mlx, path, &sprite.x, &sprite.y);
	if (sprite.xpm == NULL)
		error_msg("[ERROR]Sprite is not found.\n", game);
	return (sprite);
}

void	init_sprites(t_game *game)
{
	void	*mlx;

	mlx = game->mlx;
	game->wall = ft_new_sprite(mlx, WALL_XPM, game);
	game->space = ft_new_sprite(mlx, SPACE_XPM, game);
	game->item = ft_new_sprite(mlx, ITEM_XPM, game);
	game->player = ft_new_sprite(mlx, PLAYER_XPM, game);
	game->exit_opened = ft_new_sprite(mlx, EXIT_OPENED_XPM, game);
	game->exit_closed = ft_new_sprite(mlx, EXIT_CLOSED_XPM, game);
}

void	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
	{
		free(game->mlx);
		error_msg("[ERROR]There is no mxl pointer.\n", game);
	}
	game->window = mlx_new_window(game->mlx, \
	game->map.columns * IMG_WIDTH, game->map.rows * IMG_HEIGHT, "so_long");
	if (game->window == NULL)
	{
		free(game->mlx);
		error_msg("[ERROR]Window is not created.\n", game);
	}
}

static char	**read_map_lines(int map_fd, t_game *game)
{
	char	*map_tmp;
	char	*line_tmp;
	char	*new_map_tmp;
	char	**full_map;

	map_tmp = ft_strdup("");
	game->map.rows = 0;
	while (true)
	{
		line_tmp = get_next_line(map_fd);
		if (line_tmp == NULL)
			break ;
		new_map_tmp = ft_strjoin(map_tmp, line_tmp);
		free(map_tmp);
		map_tmp = new_map_tmp;
		free(line_tmp);
		game->map.rows++;
	}
	full_map = ft_split(map_tmp, '\n');
	free(map_tmp);
	return (full_map);
}

void	init_map(t_game *game, char *argv)
{
	int		map_fd;

	map_fd = open(argv, O_RDONLY);
	if (map_fd == -1)
		error_msg("[ERROR]Map does not exist.\n", game);
	game->map.full = read_map_lines(map_fd, game);
	close(map_fd);
	check_empty_line(*game->map.full, game);
	game->map_alloc = true;
	game->map.item = 0;
	game->map.exit = 0;
	game->map.players = 0;
	game->map.columns = ft_strlen(game->map.full[0]);
	game->move = 0;
	game->player_sprite = PLAYER;
}
