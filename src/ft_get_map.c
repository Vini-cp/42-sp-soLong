#include "../so_long.h"

int	ft_get_map(int argc, char *argv[])
{
    if (argc == 2 && ft_check_file_extension(argv[1]))
        return (SUCCESS_EXIT);
    return (FAILURE_EXIT);
}
