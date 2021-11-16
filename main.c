#include "so_long.h"

int main(int argc, char *argv[])
{
    if(!ft_get_map(argc, argv))
      return (FAILURE_EXIT);
    if(!ft_start())
        return (FAILURE_EXIT);
    return (SUCCESS_EXIT);
}
