#include "color.h"

uint32_t	get_rgba(double r, double g, double b) {
    return (uint32_t) ((int) r << 24 | (int) g << 16 | (int) b << 8 | 255);
}

t_color		*new_color(double r, double g, double b, double brightness) {
	t_color	*out = malloc(sizeof(t_color));

	out->R = r * brightness;
	out->G = g * brightness;
	out->B = b * brightness;
	return (out);
}
