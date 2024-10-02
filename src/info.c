#include "miniRT.h"

t_info *new_info(mlx_t *mlx, t_scene *scene, mlx_image_t* img) {
	t_info *new = malloc(sizeof(t_info));
	new->scene = scene;
	new->img = img;
	new->mlx = mlx;
	return new;
}

void free_info(t_info *info) {
	free_scene(info->scene);
	free(info);
}