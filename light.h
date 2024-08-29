#pragma once

typedef struct s_color	t_color;

#include "coordinate.h"
#include "color.h"

typedef struct s_light {
	t_point *position;
	t_color *color;
} t_light;

// uint32_t pic_color(t_light source, t_point surf, t_vector normal);
t_light *new_light(t_point *pos, t_color *color);
void free_light(t_light *a);