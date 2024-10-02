#pragma once

typedef struct s_color	t_color;
typedef struct s_light	t_light;

#include "color.h"
#include "light.h"
#include "coordinate.h"

typedef struct s_sphere {
	double	radius;
	t_color	*color;
	t_point	*center;
}	t_sphere;

void		free_sphere(t_sphere *sph);
t_sphere	*new_sphere(t_point* center, t_color *color, double radius);
t_point		*sphere_intersect(t_vector ray, t_sphere sph, t_vector dist);
uint32_t	pic_color(t_scene scene, t_point surf, t_sphere sph, t_vector normal);
