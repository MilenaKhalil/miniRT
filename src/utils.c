#include "miniRT.h"

void ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

double strict(double a, double b, double cos, double c) {
	if (255 - b >= a)
		return c;
	if ((a + b - 255) * cos + c > 255)
		return 255;
	return (a + b - 255) * cos + c;
}