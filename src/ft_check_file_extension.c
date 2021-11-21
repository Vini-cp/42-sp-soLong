#include "../so_long.h"

int	ft_check_file_extension(char *file_name)
{
	char	*extension;

	extension = (char *) &file_name[(ft_strlen(file_name) - 4)];
	if (ft_strncmp(extension, ".ber", 4) == 0)
	{
		return (SUCCESS_EXIT);
	}
	return (FAILURE_EXIT);
}
