/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyukang <kyukang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 14:44:27 by kyukang           #+#    #+#             */
/*   Updated: 2024/10/14 20:29:44 by kyukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <mlx.h>
# include <X11/X.h>
# include "../libft/libft.h"

# define IMG_HEIGHT	16
# define IMG_WIDTH	16

# define KEY_UP		65362
# define KEY_LEFT	65361
# define KEY_RIGHT	65363
# define KEY_DOWN	65364
# define KEY_ESC	65307

# define FRONT		1
# define LEFT		2
# define RIGHT		3
# define BACK		4

# define WALL_XPM			"image/wall.xpm"
# define SPACE_XPM			"image/space.xpm"
# define ITEM_XPM			"image/item.xpm"
# define PLAYER_XPM			"image/player.xpm"
# define EXIT_OPENED_XPM	"image/exit_opened.xpm"
# define EXIT_CLOSED_XPM	"image/exit_closed.xpm"

typedef enum e_tile
{
	WALL = '1',
	SPACE = '0',
	ITEM = 'C',
	PLAYER = 'P',
	EXIT = 'E'
}	t_tile;

typedef struct s_position
{
	int	x;
	int	y;
}	t_position;

typedef struct s_image
{
	void	*xpm;
	int		x;
	int		y;
}	t_image;

typedef enum e_bool
{
	false,
	true
}	t_bool;

typedef struct s_map
{
	char		**full;
	int			rows;
	int			columns;
	int			item;
	int			exit;
	int			players;
	t_position	player;
}	t_map;

typedef struct s_game
{
	void	*mlx;
	void	*window;
	int		move;
	int		player_sprite;
	t_map	map;
	t_bool	map_alloc;
	t_image	wall;
	t_image	space;
	t_image	item;
	t_image	exit_opened;
	t_image	exit_closed;
	t_image	player;
}	t_game;

//init.c
void	init_map(t_game *game, char *argv);
void	init_mlx(t_game *game);
void	init_sprites(t_game *game);

//check.c
void	check_arguments(int argc, char **argv, t_game *game);
void	check_empty_line(char *map, t_game *game);
void	check_walls(t_game *game);
void	check_parameters(t_game *game);

//rendor.c
int		rendor_map(t_game *game);
void	identify_sprite(t_game *game, int y, int x);

//move.c
int		move_player(int keysym, t_game *game);
int		close_game(t_game *game);

//utils.c
int		error_msg(char *msg, t_game *game);
int		win_msg(t_game *game);
void	free_map(t_game *game);
void	free_malloc(t_game *game);

#endif