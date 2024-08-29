#pragma once 

typedef struct s_light	t_light;
typedef struct s_sphere t_sphere;
typedef struct s_scene	t_scene;

#include "MLX42/include/MLX42/MLX42.h"
#include "utils.h"
#include "color.h"
#include "light.h"
#include "scene.h"
#include "sphere.h"
#include "camera.h"
#include "ray_tracing.h"

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct info {
	mlx_image_t*	img;
	t_scene			*scene;
	mlx_t			*mlx;
}	t_info;

t_info	*new_info(mlx_t *mlx, t_scene *scene, mlx_image_t* img);
void	free_info(t_info *info);

#define WIDTH 1000
#define HEIGHT 500