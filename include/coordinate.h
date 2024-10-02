#pragma once

#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

typedef struct s_point t_point;

typedef struct s_sph {
	double R;
	double a;
	double b;
} t_sph;

typedef struct s_vector {
	t_point* begining;
	t_point* ending;
} t_vector;

void change_point (t_sph coordinates, t_point *point);
t_sph *new_sphpoint (double a, double b, double R);
double two_points_dist(t_point a, t_point b);
double cos_points(t_point a, t_point b);
t_sph *copy_sphpoint (t_sph point);
void free_sphpoint(t_sph *s);

t_point *new_point (double x, double y, double z);
t_point *point_from_sph (t_sph sph);
t_point *point_copy(t_point a);
double dist(t_point a);

t_vector *proportional_vector(t_vector et, double length, t_point beg);
t_vector *vect_mul(t_vector first, t_vector second, t_point beg);
t_point *vector_sum(t_vector a, t_vector b, t_point beg);
t_vector *new_vector (t_point* begin, t_point* end);
double cos_vect(t_vector a, t_vector b);
void free_vector(t_vector *a);
double length(t_vector vect);
t_point diff(t_vector a);