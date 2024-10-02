// #include "sphere.h"
// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>

// t_sphere *new_sphere(t_point *center, double radius) {
// 	t_sphere *sph = malloc(sizeof(t_sphere));
// 	sph->center = center;
// 	sph->radius = radius;
// 	return sph;
// }

// t_point *sphere_intersect(t_vector ray, t_sphere sph) { // are classes slower then structs?
// 	t_point *beg = new_point(ray.begining->x, ray.begining->y, ray.begining->z);
// 	t_point *end = new_point(sph.center->x, sph.center->y, sph.center->z);
// 	t_vector *temp = new_vector(beg, end);

// 	double temp_len = length(*temp);
// 	double c = pow(temp_len, 2) - pow(sph.radius, 2);
// 	double cos = cos_vect(ray, *temp);
// 	double D = pow(temp_len * cos, 2) - c;

// 	if (D < 0)
// 		return free_vector(temp), new_point(INT_MIN, INT_MIN, INT_MIN); // double min should be...
// 	double len = temp_len * cos - sqrt(D); // smaller dist ***
// 	double ray_len = length(ray);
// 	t_point a = diff(ray);
// 	t_point *res = new_point(ray.begining->x + a.x / ray_len * len,
// 							ray.begining->y + a.y / ray_len * len,
// 							ray.begining->z + a.z / ray_len * len); // proportional
// 	free_vector(temp);
// 	return res;
// }

// int get_rgba(int r, int g, int b, int a) {
//     return (r << 24 | g << 16 | b << 8 | a);
// }

// double len_min(t_vector normal, double radius) {
// 	return sqrt(pow(length(normal), 2) - pow(radius, 2));
// }

// uint32_t pic_color(t_light source, t_point surf, t_sphere sph) { // no light absorbation !!!
// 	t_vector *normal = new_vector(point_copy(*sph.center), point_copy(*source.position));
// 	t_vector *temp = new_vector(point_copy(surf), point_copy(*source.position));
// 	double length_min = len_min(*normal, sph.radius);
// 	double cos;
// 	double min_cos = length_min / length(*normal);
// 	if (length(*temp) > length_min) // later *
// 		cos = min_cos;
// 	else
// 		cos = cos_vect(*temp, *normal);
// 	cos = (cos - min_cos) * (1 / (1 - min_cos));
// 	int color = get_rgba(255 * cos, 255 * cos, 255 * cos, 255); // temp change
// 	free_vector(temp);
// 	free_vector(normal);
// 	// color = cos * 0x11111100;
// 	// color = color - (color % 0xFF) + 0xFF;
// 	return (uint32_t) color;
// }

// void free_sphere(t_sphere *sph) {
// 	free(sph->center);
// 	free(sph);
// }