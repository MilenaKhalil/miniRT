#include "coordinate.h"
#include "parser.h"

t_sph *new_sphpoint (double a, double b, double R) {
	t_sph *k = malloc(sizeof(t_sph));
	k->a = a;
	k->b = b;
	k->R = R;
	return k;
}

t_sph* copy_sphpoint (t_sph point) {
	t_sph *k = malloc(sizeof(t_sph));
	k->a = point.a;
	k->b = point.b;
	k->R = point.R;
	return k;
}

void change_point (t_sph coordinates, t_point *point) {
	double R = coordinates.R;
	double a = coordinates.a;
	double b = coordinates.b;

	point->y = R * cos(b);
	point->x = R * sin(b) * cos(a);
	point->z = R * sin(b) * sin(a) * -1;
}

void free_sphpoint(t_sph *s) {
	free(s);
}