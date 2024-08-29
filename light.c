#include "light.h"

t_light *new_light(t_point *pos, t_color *color) {
	t_light *new = malloc(sizeof(t_light));
	new->position = pos;
	new->color = color;
	return new;
}

void free_light(t_light *a) {
	free(a->position);
	free(a->color);
	free(a);
}

// uint32_t pic_color(t_light source, t_point surf, t_vector normal) { // no light absorbation !!!
// 	t_vector *temp = new_vector(point_copy(surf), point_copy(*source.position));
// 	double cos = cos_vect(*temp, normal);
// 	free_vector(temp);
// 	return (uint32_t)((double) source.color) * cos;
// }