#include "coordinate.h"
#include "utils.h"
#include <math.h>

t_vector *new_vector (t_point* begin, t_point* end) {
	t_vector *k = malloc(sizeof(t_vector));
	k->begining = begin;
	k->ending = end;
	return k;
}

t_point diff(t_vector a) {               // returns a transposed vector which begines at the point (0,0,0)
	t_point diff;

	diff.x = a.ending->x - a.begining->x;
	diff.y = a.ending->y - a.begining->y;
	diff.z = a.ending->z - a.begining->z;
	return diff;
}

t_point *vector_sum(t_vector a, t_vector b, t_point beg) { // beg is begining, where both of the vectors begin
	t_point a0 = diff(a);
	t_point b0 = diff(b);

	t_point *sum = malloc(sizeof(t_point));
	sum->x = a0.x + b0.x + beg.x;
	sum->y = a0.y + b0.y + beg.y;
	sum->z = a0.z + b0.z + beg.z;

	return sum;
}

double length(t_vector vect) {
	return (sqrt(pow(vect.begining->x - vect.ending->x, 2) + 
				pow(vect.begining->y - vect.ending->y, 2) +
				pow(vect.begining->z - vect.ending->z, 2)));
}

double cos_vect(t_vector a, t_vector b) {
	t_point diff_a = diff(a);
	t_point diff_b = diff(b);

	return cos_points(diff_a, diff_b);
}

void free_vector(t_vector *a) {
	free(a->begining);
	free(a->ending);
	free(a);
}

t_vector *vect_mul(t_vector first, t_vector second, t_point beg) {
	t_point a = diff(first);
	t_point b = diff(second);

	t_point *end = new_point(a.y * b.z - a.z * b.y, a.x * b.z - a.z * b.x, a.x * b.y - a.y * b.x);
	end->x += beg.x;
	end->y += beg.y;
	end->z += beg.z;
	return new_vector(point_copy(beg), end);
}

t_vector *proportional_vector(t_vector et, double length, t_point beg) {
	t_point di = diff(et);
	double dis = dist(di);

	t_point *end = new_point (di.x / dis * length, di.y / dis * length, di.z / dis * length);
	end->x += beg.x;
	end->y += beg.y;
	end->z += beg.z;
	return new_vector(point_copy(beg), end);
}