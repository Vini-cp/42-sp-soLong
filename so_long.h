/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 03:18:31 by coder             #+#    #+#             */
/*   Updated: 2022/01/30 23:14:51 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include "./libft/libft.h"
# include <fcntl.h>

# define WINDOW_NAME "soLong game"
# define TILE_WIDTH 32
# define SUCCESS_EXIT 1
# define FAILURE_EXIT 0

# define ESC 65307
# define UP 119
# define DOWN 115
# define LEFT 97
# define RIGHT 100

# define PLAYER "./assets/player.xpm"
# define WALL "./assets/wall.xpm"
# define BACKGROUND "./assets/background.xpm"
# define EXIT "./assets/exit.xpm"
# define COLLECTIBLE "./assets/collectible.xpm"

# define ORANGE 0xFFFF00

typedef struct game_set
{
	char					**map;
	int						map_height;
	int						map_length;
	int						player_position_x;
	int						player_position_y;
	int						player_movements;
	int						no_collectibles;
	int						no_exits;
	int						game_won;
	int						img_width;
	int						img_height;
	void					*player;
	void					*wall;
	void					*background;
	void					*exit;
	void					*collectible;
	void					*mlx;
	void					*win;
}	t_game_set;

int		ft_game_loop(t_game_set *game_set);
int		ft_get_map(int argc, char *argv[], t_game_set *game_set);
int		ft_check_map(t_game_set *game_set);
int		ft_get_info_from_map(t_game_set *game_set);
int		ft_key_hook(int keycode, t_game_set *game_set);
int		ft_exit_hook(t_game_set *game_set);
int		ft_set_configs(t_game_set *game_set);
int		ft_exit_error(t_game_set *game_set, char *message,
			void (*f)(t_game_set *));
void	ft_build_images(t_game_set *game_set);
void	ft_render(t_game_set *game_set);
void	ft_free_map(t_game_set *game_set);
void	ft_free(t_game_set *game_set);

#endif
