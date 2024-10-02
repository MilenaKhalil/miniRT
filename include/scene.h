#pragma once

typedef struct s_color	t_color;
typedef struct s_light	t_light;
typedef struct s_camera	t_camera;

#include "miniRT.h"

typedef struct s_lights	t_lights;
typedef struct s_objects	t_objects;

typedef struct s_lights { // light lights
	t_light		*light;
	t_lights 	*next;
}	t_lights;

typedef struct s_objects {
	void		*obj;
	char		type;       // s - sphere, p - plane, c - cylinder
	t_objects 	*next;
}	t_objects;

typedef struct s_scene // заполняется всё с инпутом...
{
	t_color		*ambient; // ambient lighting (0, 0, 0) by default (black)
	t_camera	*camera;
	t_lights	*lights;
	t_objects	*objects;
}	t_scene;

void	add_object_to_scene(void *obj, char type, t_scene *scene);
void	add_light_to_scene(t_light *light, t_scene *scene);
void	add_ambient(t_color *amb, t_scene *scene);
void	free_scene (t_scene *scene);
int		light_len(t_lights *head);
int		obj_len(t_objects *head);
t_scene	*new_scene(void);
