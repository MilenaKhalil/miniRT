#include "parser.h"
#include <fcntl.h>

int	open_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit_error("File open error");
	return (fd);
}
