#pragma once
#include "miniRT.h"

typedef struct s_color
{
	double R;
	double G;
	double B;
}	t_color;

uint32_t	get_rgba(double r, double g, double b);
t_color		*new_color(double r, double g, double b, double brightness);
