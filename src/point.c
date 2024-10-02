#include "coordinate.h"
#include "parser.h"

t_point *new_point (double x, double y, double z) {
	t_point *k = malloc(sizeof(t_point));
	k->x = x;
	k->y = y;
	k->z = z;
	return k;
}

t_point *point_copy (t_point a) {
	return new_point(a.x, a.y, a.z);
}

t_point *point_from_sph (t_sph sph) {
	t_point *new = malloc(sizeof(t_point));

	change_point (sph, new);
	return new;
}

double dist(t_point a) { // calculates the distance to (0, 0, 0)
	return (sqrt(pow(a.x, 2) + pow(a.y, 2) + pow(a.z, 2)));
}

double two_points_dist(t_point a, t_point b) {
	return (sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2) + pow(a.z - b.z, 2)));
}

double cos_points(t_point a, t_point b) {
	double cos = a.x * b.x + a.y * b.y + a.z * b.z;
	cos /= (dist(a) * dist(b));

	return cos;
}
