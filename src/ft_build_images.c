#include "../so_long.h"

static void ft_to_image(void **img, char *img_name, void *mlx)
{
  int		img_width;
	int		img_height;

  img = mlx_xpm_file_to_image(mlx, img_name, &img_width, &img_height);
}

void	ft_build_images(t_game_set **game_set, t_win_render **game_window)
{
  ft_to_image(&(*game_set)->player, PLAYER, (*game_window)->mlx)
  ft_to_image(&(*game_set)->wall, WALL, (*game_window)->mlx)
  ft_to_image(&(*game_set)->background, BACKGROUND, (*game_window)->mlx)
  ft_to_image(&(*game_set)->exit, EXIT, (*game_window)->mlx)
  ft_to_image(&(*game_set)->collectible, COLLECTIBLE, (*game_window)->mlx)
}
