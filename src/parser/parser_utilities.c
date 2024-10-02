#include "libft.h"
#include "parser.h"

int	is_str_num(const char *str)
{
	int	len;
	int	i;

	i = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		if (!ft_isdigit(str[i]))
			return (0);
		++i;
	}
	return (1);
}

void	fill_vector(t_point *vec, double x, double y, double z)
{
	vec->x = x;
	vec->y = y;
	vec->z = z;
}

int	parse_rgb_vector(const char	*str, t_point *vec)
{
	char	**arr;
	int		len;
	int		i;
	int		num;
	double	res[3];

	arr = ft_split(str, ',');
	if (!arr)
		return (0);
	len = ft_arrlen((const char **)arr);
	if (len != 3)
		return (ft_arrfree(arr), 0);
	i = 0;
	while (i < len)
	{
		if (!is_str_num(arr[i]))
			return (ft_arrfree(arr), 0);
		num = ft_atoi(arr[i]);
		if (num > 255 || num < 0)
			return (ft_arrfree(arr), 0);
		res[i] = (double)num;
		++i;
	}
	fill_vector(vec, res[0], res[1], res[2]);
	return (ft_arrfree(arr), 1);
}

int	parse_3d_vector(const char	*str, t_point *vec)
{
	char	**arr;
	int		len;

	arr = ft_split(str, ',');
	if (!arr)
		return (0);
	len = ft_arrlen((const char **)arr);
	if (len != 3)
		return (ft_arrfree(arr), 0);
	fill_vector(vec, ft_atod(arr[0]), ft_atod(arr[1]), ft_atod(arr[2]));
	return (ft_arrfree(arr), 1);
}

int	is_double(const char *str)
{
	int	dots_num;
	int	len;
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		++i;
	dots_num = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		if (!ft_isdigit(str[i]) && str[i] != '.')
			return (0);
		else if (str[i] == '.')
			++dots_num;
		++i;
	}
	return (dots_num == 1 || dots_num == 0);
}

int	is_vector_in_range(t_point *vec, double min, double max)
{
	double	tmp[3];
	int		i;

	tmp[0] = vec->x;
	tmp[1] = vec->y;
	tmp[2] = vec->z;
	i = 0;
	while (i < 3)
	{
		if (tmp[i] < min || tmp[i] > max)
			return (0);
		++i;
	}
	return (1);
}

void	debug_print(t_input *input)
{
	printf("INPUT\n");
	if (input->ambient_lightning)
	{
		printf("A %f	%f,%f,%f\n",
				input->ambient_lightning->ratio,
				input->ambient_lightning->rgb.x, input->ambient_lightning->rgb.y, input->ambient_lightning->rgb.z);
	}
	if (input->camera)
	{
		printf("C %f,%f,%f	%f,%f,%f	%i\n",
				input->camera->view_point.x, input->camera->view_point.y, input->camera->view_point.z,
				input->camera->normal_vec.x, input->camera->normal_vec.y, input->camera->normal_vec.z,
				input->camera->fov);
	}
	if (input->light)
	{
		printf("L %f,%f,%f	%f\n",
				input->light->light_point.x, input->light->light_point.y, input->light->light_point.z,
				input->light->ratio);
	}
	if (input->spheres)
	{
		t_list *tmp = input->spheres;
		while(tmp)
		{
			t_parsed_sphere *sphere = (t_parsed_sphere*)tmp->content;
			printf("sp %f,%f,%f	%f	%f,%f,%f\n",
				sphere->center.x, sphere->center.y, sphere->center.z,
				sphere->diameter,
				sphere->rgb.x, sphere->rgb.y, sphere->rgb.z);
				tmp = tmp->next;
		}
	}
	if (input->planes)
	{
		t_list *tmp = input->planes;
		while(tmp)
		{
			t_parsed_plane *plane = (t_parsed_plane*)tmp->content;
			printf("pl %f,%f,%f	%f,%f,%f	%f,%f,%f\n",
					plane->point.x, plane->point.y, plane->point.z,
					plane->normal_vec.x, plane->normal_vec.y, plane->normal_vec.z,
					plane->rgb.x, plane->rgb.y, plane->rgb.z);
			tmp = tmp->next;
		}
	}
	if (input->cylinders)
	{
		t_list *tmp = input->cylinders;
		while(tmp)
		{
			t_parsed_cylinder *cylinder = (t_parsed_cylinder*)tmp->content;
			printf("cy %f,%f,%f	%f,%f,%f	%f	%f	%f,%f,%f\n",
					cylinder->center.x, cylinder->center.y, cylinder->center.z,
					cylinder->normal_vec.x, cylinder->normal_vec.y, cylinder->normal_vec.z,
					cylinder->diameter,
					cylinder->height,
					cylinder->rgb.x, cylinder->rgb.y, cylinder->rgb.z);
			tmp = tmp->next;
		}
	}
	printf("END INPUT\n");
}

