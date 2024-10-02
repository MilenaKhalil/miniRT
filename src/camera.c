#include "camera.h"

t_camera *new_camera(int width, int hight, t_point *direction) {
	t_camera *camera = malloc(sizeof(t_camera));
	camera->sph_coordinate = new_sphpoint(M_PI / 2, M_PI / 2, 14);
	camera->veiw_point = point_from_sph(*camera->sph_coordinate);
	camera->direction = direction;       // now I am not using it yet
	camera->width = (double) width;
	camera->hight = (double) hight;
	camera->turning_angle = M_PI / 4;
	camera->speed = 1.3;
	camera->pic_h = 3;
	camera->pic_w = 3 / camera->hight * camera->width;
	camera->focal_distance = 10; // большое, чтобы не было искажений 
	return camera;
}

void new_coordinate(t_camera *camera, double a, double b, double R) {
	camera->sph_coordinate->a = a;
	camera->sph_coordinate->b = b;
	camera->sph_coordinate->R = R;

	change_point(*camera->sph_coordinate, camera->veiw_point);
}

void camera_move(t_camera *camera, char dir)
{
	double R = camera->sph_coordinate->R;
	double a = camera->sph_coordinate->a;
	double b = camera->sph_coordinate->b;
	if (dir == 'i') {
		R /= camera->speed;
		new_coordinate(camera, a, b, R);
	}
	if (dir == 'o') {
		R *= camera->speed;
		new_coordinate(camera, a, b, R);
	}
	if (dir == 'u') {
		b -= camera->turning_angle;
		if (b < 0)
			b += 2*M_PI;
		new_coordinate(camera, a, b, R);
	}
	if (dir == 'd') {
		b += camera->turning_angle;
		if (b > 2*M_PI)
			b = b - 2*M_PI;
		new_coordinate(camera, a, b, R);
	}
	if (dir == 'l') {
		a += camera->turning_angle;
		if (a > 2*M_PI)
			a = a - 2*M_PI;
		new_coordinate(camera, a, b, R);
	}
	if (dir == 'r') {
		a -= camera->turning_angle;
		if (a < 0)
			a += 2*M_PI;
		new_coordinate(camera, a, b, R);
	}
}

void free_camera(t_camera *camera) {
	free_sphpoint(camera->sph_coordinate);
	free(camera->direction);
	free(camera);
}