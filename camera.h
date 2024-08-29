#pragma once

#include "miniRT.h"

typedef struct s_camera {
	t_point *veiw_point;     // veiw_point and direction can be one vector instead (I will implement it later...)
	t_point *direction;
	t_sph *sph_coordinate;
	double width;
	double hight;
	double pic_h;
	double pic_w;
	double turning_angle;
	double speed;
	double focal_distance;
} t_camera;

void free_camera(t_camera *camera);
t_camera *new_camera(int width, int hight, t_point *direction);
void camera_move(t_camera *camera, char dir);