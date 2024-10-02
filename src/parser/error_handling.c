#include <stdlib.h>
#include "parser.h"

void	exit_error(char *str)
{
	printf("Error\n");
	perror(str);
	exit(EXIT_FAILURE);
}

void	free_input(t_input *input)
{
	if (input->ambient_lightning)
		free(input->ambient_lightning);
	if (input->camera)
		free(input->camera);
	if (input->light)
		free(input->light);
	if (input->spheres)
		ft_lstclear(&input->spheres, free);
	if (input->cylinders)
		ft_lstclear(&input->cylinders, free);
	if (input->planes)
		ft_lstclear(&input->planes, free);
	free(input);
}
