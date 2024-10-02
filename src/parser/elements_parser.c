#include "libft.h"
#include "parser.h"

t_ambient_lightning	*parse_ambient_lightning(char **argv)
{
	printf("parse_ambient_lightning\n");
	t_ambient_lightning	*res;
	int					arr_len;

	res = (t_ambient_lightning *)malloc(sizeof(t_ambient_lightning));
	if (!res)
		return (NULL);
	arr_len = ft_arrlen((const char **)argv);
	if (arr_len != 3)
		return (free(res), NULL);
	if (!is_double(argv[1]))
		return (free(res), NULL);
	res->ratio = ft_atod(argv[1]);
	if (res->ratio < 0.0 || res->ratio > 1.0)
		return (free(res), NULL);
	if (!parse_rgb_vector(argv[2], &(res->rgb)))
		return (free(res), NULL);
	printf("parse_ambient_lightning SC\n");
	return (res);
}

t_parsed_camera	*parse_camera(char **argv)
{
	printf("parse_camera\n");
	t_parsed_camera	*res;
	int			arr_len;

	res = (t_parsed_camera *)malloc(sizeof(t_parsed_camera));
	if (!res)
		return (NULL);
	arr_len = ft_arrlen((const char **)argv);
	if (arr_len != 4)
		return (free(res), NULL);
	if (!parse_3d_vector(argv[1], &(res->view_point)))
		return (free(res), NULL);
	if (!parse_3d_vector(argv[2], &(res->normal_vec)))
		return (free(res), NULL);
	if (!is_vector_in_range(&(res->normal_vec), -1, 1))
		return (free(res), NULL);
	res->fov = ft_atoi(argv[3]);
	if (res->fov < 0 || res->fov > 180)
		return (free(res), NULL);
	printf("parse_camera SC\n");
	return (res);
}

t_parsed_light	*parse_light(char **argv)
{
	printf("parse_light\n");
	t_parsed_light	*res;
	int		arr_len;

	res = (t_parsed_light *)malloc(sizeof(t_parsed_light));
	if (!res)
		return (NULL);
	arr_len = ft_arrlen((const char **)argv);
	if (arr_len < 3 || arr_len > 4)
		return (free(res), NULL);
	if (!parse_3d_vector(argv[1], &(res->light_point)))
		return (free(res), NULL);
	if (!is_double(argv[2]))
		return (free(res), NULL);
	res->ratio = ft_atod(argv[2]);
	if (res->ratio < 0.0 || res->ratio > 1.0)
		return (free(res), NULL);
	return (res);
}

t_parsed_sphere	*parse_sphere(char **argv)
{
	printf("parse_sphere\n");
	t_parsed_sphere	*res;
	int				arr_len;

	res = (t_parsed_sphere *)malloc(sizeof(t_parsed_sphere));
	if (!res)
		return (NULL);
	arr_len = ft_arrlen((const char **)argv);
	if (arr_len != 4)
		return (free(res), NULL);
	if (!parse_3d_vector(argv[1], &(res->center)))
		return (free(res), NULL);
	if (!is_double(argv[2]))
		return (free(res), NULL);
	res->diameter = ft_atod(argv[2]);
	if (!parse_rgb_vector(argv[3], &(res->rgb)))
		return (free(res), NULL);
	return (res);
}

t_parsed_plane	*parse_plane(char **argv)
{
	printf("parse_plane\n");
	t_parsed_plane		*res;
	int					arr_len;

	res = (t_parsed_plane *)malloc(sizeof(t_parsed_plane));
	if (!res)
		return (NULL);
	arr_len = ft_arrlen((const char **)argv);
	if (arr_len != 4)
		return (free(res), NULL);
	if (!parse_3d_vector(argv[1], &(res->point)))
		return (free(res), NULL);
	if (!parse_3d_vector(argv[2], &(res->normal_vec)))
		return (free(res), NULL);
	if (!is_vector_in_range(&(res->normal_vec), -1, 1))
		return (free(res), NULL);
	if (!parse_rgb_vector(argv[3], &(res->rgb)))
		return (free(res), NULL);
	return (res);
}

t_parsed_cylinder	*parse_cylinder(char **argv)
{
	printf("parse_cylinder\n");
	t_parsed_cylinder	*res;
	int					arr_len;

	res = (t_parsed_cylinder *)malloc(sizeof(t_parsed_cylinder));
	if (!res)
		return (NULL);
	arr_len = ft_arrlen((const char **)argv);
	if (arr_len != 6)
		return (free(res), NULL);
	if (!parse_3d_vector(argv[1], &(res->center)))
		return (free(res), NULL);
	if (!parse_3d_vector(argv[2], &(res->normal_vec)))
		return (free(res), NULL);
	if (!is_vector_in_range(&(res->normal_vec), -1, 1))
		return (free(res), NULL);
	if (!is_double(argv[3]))
		return (free(res), NULL);
	res->diameter = ft_atod(argv[3]);
	if (!is_double(argv[4]))
		return (free(res), NULL);
	res->height = ft_atod(argv[4]);
	if (!parse_rgb_vector(argv[5], &(res->rgb)))
		return (free(res), NULL);
	return (res);
}