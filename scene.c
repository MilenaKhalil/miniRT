#include "scene.h"

static t_objects	*last_obj(t_objects *list) { // было бы круто иметь одну функцию для обих структур, но я не знаю, как это сделать
	while (list->next)
		list = list->next;
	return list;
}

static t_lights	*last_lie(t_lights *list) {
	while (list->next)
		list = list->next;
	return list;
}

int	obj_len(t_objects *head) {
	int	i = 0;

	while (head) {
		head = head->next;
		i++;
	}
	return (i);
}

int	light_len(t_lights *head) {
	int	i = 0;

	while (head) {
		head = head->next;
		i++;
	}
	return (i);
}

void	add_object_to_scene(void *obj, char type, t_scene *scene) {
	t_objects *object = malloc(sizeof(t_objects));
	object->obj = obj;
	object->next = NULL;
	object->type = type;
	if (!scene->objects)
		scene->objects = object;
	else {
		t_objects *last = last_obj(scene->objects);
		last->next = object;
	}
}

void	add_light_to_scene(t_light *light, t_scene *scene) {
	t_lights *source = malloc(sizeof(t_lights));
	source->next = 0;
	source->light = light;
	if (!scene->lights)
		scene->lights = source;
	else {
		t_lights *last = last_lie(scene->lights);
		last->next = source;
	}
}

static void free_lights(t_lights *head) {
	t_lights *temp;

	while (head) {
		temp = head->next;
		free_light(head->light);
		free(head);
		head = temp;
	}
}

static void free_objects(t_objects *head) {
	t_objects *temp;

	while (head) {
		temp = head->next;
		if (head->type == 's')                   // later more ifs
			free_sphere((t_sphere *) head->obj);
		free(head);
		head = temp;
	}
}

t_scene	*new_scene(void) {
	t_scene *scene = malloc(sizeof(t_scene));
	scene->ambient = new_color(0, 0, 0, 1);  // default
	scene->objects = 0;
	scene->camera = 0;
	scene->lights = 0;
	return (scene);
}

void add_ambient(t_color *amb, t_scene *scene) {
	free(scene->ambient);
	scene->ambient = amb;
}

void free_scene (t_scene *scene) {
	free_camera(scene->camera);
	free_lights(scene->lights);
	free_objects(scene->objects);
	free(scene->ambient);
}