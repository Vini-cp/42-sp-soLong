#include "so_long.h"

int main(int argc, char *argv[])
{
  t_game_set *game_set;

  if (!ft_get_map(argc, argv, &game_set))
    return (FAILURE_EXIT);
  if (!ft_start(game_set))
    return (FAILURE_EXIT);
  return (SUCCESS_EXIT);
}
