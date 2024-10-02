#include "coordinate.h"
#include "parser.h"

void print_point(t_point a) {
	printf ("point x = %f, y = %f, z = %f\n", a.x, a.y, a.z);
}

void print_vector(t_vector a) {
	printf ("vector beginning:\n");
	print_point(*a.begining);
	printf ("vector ending:\n");
	print_point(*a.ending);
}

void print_sphpoint(t_sph sph) {
	printf ("sph_point a = %f, b = %f, R = %f\n", sph.a, sph.b, sph.R);
}