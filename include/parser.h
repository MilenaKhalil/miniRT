#ifndef PARSER_H
# define PARSER_H
# include <stdio.h>
#include "get_next_line.h"


typedef struct s_point {
	double x;
	double y;
	double z;
} t_point;

typedef struct s_ambient_lightning
{
	double	ratio;
	t_point	rgb;
}	t_ambient_lightning;

typedef struct s_parsed_camera
{
	t_point	view_point;
	t_point	normal_vec;
	int		fov;
}	t_parsed_camera;

typedef struct s_parsed_light
{
	t_point	light_point;
	double	ratio;
}	t_parsed_light;

typedef struct s_parsed_sphere
{
	t_point	center;
	t_point	rgb;
	double	diameter;
}	t_parsed_sphere;

typedef struct s_parsed_plane
{
	t_point	point;
	t_point	normal_vec;
	t_point	rgb;
}	t_parsed_plane;

typedef struct s_parsed_cylinder
{
	t_point	center;
	t_point	normal_vec;
	t_point	rgb;
	double	diameter;
	double	height;
}	t_parsed_cylinder;

typedef struct s_input
{
	t_ambient_lightning	*ambient_lightning;
	t_parsed_camera		*camera;
	t_parsed_light		*light;
	t_list				*spheres;
	t_list				*planes;
	t_list				*cylinders;
}	t_input;

int		open_file(char *file);
void	exit_error(char *str);
void	free_input(t_input *input);

t_input	*parse_input(char *file);

//parse elements
t_ambient_lightning	*parse_ambient_lightning(char **argv);
t_parsed_camera		*parse_camera(char **argv);
t_parsed_light		*parse_light(char **argv);
t_parsed_sphere		*parse_sphere(char **argv);
t_parsed_plane		*parse_plane(char **argv);
t_parsed_cylinder	*parse_cylinder(char **argv);

//utilities
int		is_double(const char *str);
int		parse_rgb_vector(const char	*str, t_point *vec);
int		parse_3d_vector(const char	*str, t_point *vec);
void	fill_vector(t_point *vec, double x, double y, double z);
int		is_vector_in_range(t_point *vec, double min, double max);

//debug
void	debug_print(t_input *input);

#endif