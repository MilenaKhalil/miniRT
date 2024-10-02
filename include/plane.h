#pragma once
#include "light.h"
#include "coordinate.h"

typedef struct s_plane {
	// t_point *points[3];
	double a;
	double b;
	t_point nol;
	t_vector *normal;
} t_plane;

void free_plane(t_point *one, t_point *two, t_point *three);
t_plane *new_plane(t_point* center, double radius);
t_point *plane_intersect(t_vector ray, t_plane sph);
uint32_t plane_color(t_light source, t_point surf, t_plane sph);