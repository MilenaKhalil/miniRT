#include "sphere.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

t_sphere	*new_sphere(t_point *center, t_color *color, double radius) {
	t_sphere	*sph = malloc(sizeof(t_sphere));

	sph->color = color;
	sph->center = center;
	sph->radius = radius;
	return (sph);
}

t_point		*sphere_intersect(t_vector ray, t_sphere sph, t_vector dist) {
	double vtcd = length(dist);
	double c = pow(vtcd, 2) - pow(sph.radius, 2);
	double cos = cos_vect(dist, ray);
	double D = pow(vtcd * cos, 2) - c;

	if (D < 0)                                       // не пересекает (по идее)
		return new_point(INT_MIN, INT_MIN, INT_MIN);
	double len = vtcd * cos - sqrt(D);
	double ray_len = length(ray);
	t_point a = diff(ray);
	t_point *res = new_point(ray.begining->x + (a.x / ray_len) * len,
							ray.begining->y + (a.y / ray_len) * len,
							ray.begining->z + (a.z / ray_len) * len);
	return (res);
}

uint32_t	pic_color(t_scene scene, t_point surf, t_sphere sph, t_vector normal) {
	t_light		source = *scene.lights->light;
	t_vector	*radius = new_vector(point_copy(surf), point_copy(*sph.center));
	t_vector	*vect = new_vector(point_copy(*source.position), point_copy(surf));
	double		cos = 0;

	if (length(*vect) < sqrt(pow(length(normal), 2)
		- pow(length(*radius), 2)))
		cos = cos_vect(*vect, *radius);
	uint32_t	color = get_rgba(strict(source.color->R, sph.color->R, cos, scene.ambient->R),
							strict(source.color->G, sph.color->G, cos, scene.ambient->G),
							strict(source.color->B, sph.color->B, cos, scene.ambient->B));
	free_vector(vect);
	free_vector(radius);
	return (color);
}

void		free_sphere(t_sphere *sph) {
	free(sph->center);
	free(sph->color);
	free(sph);
}