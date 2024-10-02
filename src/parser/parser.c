#include "parser.h"
#include "libft.h"

static	int	parse_object_element(t_input *input, char **argv)
{
	void	*obj;
	t_list	*node;
	t_list	**obj_list;

	obj = NULL;
	if (!ft_strncmp(argv[0], "sp", ft_strlen(argv[0])))
	{
		obj = parse_sphere(argv);
		obj_list = &input->spheres;
	}
	else if (!ft_strncmp(argv[0], "pl", ft_strlen(argv[0])))
	{
		obj = parse_plane(argv);
		obj_list = &input->planes;
	}
	else if (!ft_strncmp(argv[0], "cy", ft_strlen(argv[0])))
	{
		obj = parse_cylinder(argv);
		obj_list = &input->cylinders;
	}
	if (!obj)
		return (0);
	node = ft_lstnew((void *) obj);
	if (!node)
		return (free(obj), 0);
	ft_lstadd_back(obj_list, node);
	printf("Added to list\n");
	return (1);
}

static int	parse_element(t_input *input, char **argv)
{
	printf("Try to parse element with specifiers %s\n", argv[0]);
	if (!ft_strncmp(argv[0], "A", ft_strlen(argv[0]))
		&& !input->ambient_lightning)
	{
		input->ambient_lightning = parse_ambient_lightning(argv);
		if (input->ambient_lightning)
			return (1);
	}
	else if (!ft_strncmp(argv[0], "C", ft_strlen(argv[0])) && !input->camera)
	{
		input->camera = parse_camera(argv);
		if (input->camera)
			return (1);
	}
	else if (!ft_strncmp(argv[0], "L", ft_strlen(argv[0])) && !input->light)
	{
		input->light = parse_light(argv);
		if (input->light)
			return (1);
	}
	return (parse_object_element(input, argv));
}

static int	parse_line(t_input *input, char *line)
{
	char	**argv;
	int		len;

	len = ft_strlen(line);
	line[len - 1] = '\0';
	argv = ft_split(line, ' ');
	if (!argv)
		return (0);
	return (parse_element(input, argv));
}

t_input	*parse_input(char *file)
{
	t_input	*input;
	int		fd;
	char	*line;

	fd = open_file(file);
	input = (t_input *)malloc(sizeof(t_input));
	if (!input)
		return (NULL);
	line = get_next_line(fd);
	while (line)
	{
		printf("Try to parse line: %s\n", line);
		if (!parse_line(input, line))
		{
			free_input(input);
			free(line);
			return (NULL);
		}
		free(line);
		line = get_next_line(fd);
	}
	return (input);
}
