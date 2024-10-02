#include "ray_tracing.h"

static void	define_vect(t_vector **x, t_vector **y, t_sph middle, t_camera camera) {
	t_point *beg = point_from_sph(middle);
	t_vector temp;
	temp.begining = camera.veiw_point;
	temp.ending = beg;

	t_sph sph_y;

	sph_y.R = sqrt(pow(middle.R, 2) + pow(1, 2));
	sph_y.a = middle.a;
	sph_y.b = middle.b - asin(1 / sph_y.R);

	*y = new_vector(beg, point_from_sph(sph_y));
	*x = vect_mul(temp, **y, *beg);
}

static t_vector	*creating_ray (t_camera camera, t_sph middle, int he, int wi, t_vector vect_x,
	t_vector vect_y) {

	double x_dist = ((wi - camera.width / 2) * camera.pic_w) / camera.width;
	double y_dist = ((camera.hight / 2 - he) * camera.pic_h) / camera.hight;

	t_point *beg = point_from_sph(middle);
	t_vector *x = proportional_vector(vect_x, x_dist, *beg);
	t_vector *y = proportional_vector(vect_y, y_dist, *beg);
	
	t_point *ray_end = vector_sum(*x, *y, *x->begining);
	t_point *ray_beg = point_copy (*camera.veiw_point);
	
	free(beg);
	free_vector(x);
	free_vector(y);

	return (new_vector(ray_beg, ray_end));
}

t_objects	*find_closest_obj (t_vector ray, t_objects *objects) { // проверить что расстояние от начала вектора до точки пересечения больше, чем от конца вектора
	int	i = 0;
	double	arr[1000];
	t_objects *obj = objects;
	int	len = obj_len(objects);

	while (i < len) {
		if (objects->type == 's') {
			t_sphere *sph = (t_sphere *) objects->obj;
			t_vector *dist = new_vector(point_copy(*ray.begining), point_copy(*sph->center));
			t_point *cross = sphere_intersect(ray, *sph, *dist);
			if (cross->x < -30000)
				arr[i] = INT_MAX;
			else
				arr[i] = two_points_dist(*cross, *ray.begining);
			free(cross);
			free_vector(dist);
		}
		i++;
		objects = objects->next;
	}
	double min = arr[0];
	int iter = 0;
	int k = 0;
	while (k < len) {
		if (min > arr[k]) {
			iter = k;
			min = arr[k];
		}
		k++;
	}
	while (iter) {
		obj = obj->next;
		iter--;
	}
	return obj;
}

void		draw_pic(t_scene scene, mlx_image_t *img) {
	t_camera *camera = scene.camera;
	t_light *source = scene.lights->light; // для лучей света в программе можно использовать ту же функцию (find closest obj), но только рэй идёт источника света (для теней)
	t_sph middle = *camera->sph_coordinate;
	middle.R -= camera->focal_distance;
	t_vector *y, *x;
	define_vect(&x, &y, middle, *camera);
	for (int i = 0; i < camera->hight; i++) {
		for (int j = 0; j < camera->width; j++) {
			t_vector *ray = creating_ray(*camera, middle, i, j, *x, *y);
			t_objects *obj = find_closest_obj(*ray, scene.objects);
			if (obj->type == 's') {
				t_sphere *sph = (t_sphere *) obj->obj;
				t_vector *dist = new_vector(point_copy(*camera->veiw_point), point_copy(*sph->center));
				t_vector *normal = new_vector(point_copy(*source->position), point_copy(*sph->center));
				t_point *temp = sphere_intersect(*ray, *sph, *dist);
				// printf ("hahah\n");
				if (temp->x > -30000) {
					u_int32_t color = pic_color(scene, *temp, *sph, *normal);
					mlx_put_pixel(img, j, i, color);
				}
				else
					mlx_put_pixel(img, j, i, 0x100510FF);
				free(temp);
				free_vector(dist);
				free_vector(normal);
			}
			free_vector(ray);
		}
	}
	free_vector(x);
	free_vector(y);
}