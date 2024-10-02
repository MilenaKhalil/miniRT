#include "miniRT.h"

static void ft_hook(void *param) // перерисовка при попадании в один из ифов ***
{
	t_info *info = (t_info *) param;

	if (mlx_is_key_down(info->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(info->mlx);
	if (mlx_is_key_down(info->mlx, MLX_KEY_LEFT)) {
		camera_move(info->scene->camera, 'l');
		draw_pic(*info->scene, info->img);
	}
	if (mlx_is_key_down(info->mlx, MLX_KEY_RIGHT)) {
		camera_move(info->scene->camera, 'r');
		draw_pic(*info->scene, info->img);
	}
	if (mlx_is_key_down(info->mlx, MLX_KEY_UP)) {
		camera_move(info->scene->camera, 'u');
		draw_pic(*info->scene, info->img);
	}
	if (mlx_is_key_down(info->mlx, MLX_KEY_DOWN)) {
		camera_move(info->scene->camera, 'd');
		draw_pic(*info->scene, info->img);
	}
	if (mlx_is_key_down(info->mlx, MLX_KEY_A)) {
		camera_move(info->scene->camera, 'i');
		draw_pic(*info->scene, info->img);
	}
	if (mlx_is_key_down(info->mlx, MLX_KEY_Z)) {
		camera_move(info->scene->camera, 'o');
		draw_pic(*info->scene, info->img);
	}
}

t_scene	*parse_scene(void) {    // должен парсить, но сейчас я заполняю вручную
	t_scene	*scene = new_scene();

	scene->camera = new_camera(WIDTH, HEIGHT, new_point(0, 0, 0));
	add_ambient(new_color(0, 0, 0, 1), scene);
	add_light_to_scene(new_light(new_point(-3, 3, -3),
		new_color(255, 255, 255, 1)), scene);
	add_object_to_scene((void *) new_sphere(new_point(0.5, 0, 0),
			new_color(14, 250, 50, 1), 1), 's', scene);
	add_object_to_scene((void *) new_sphere(new_point(-0.5, 0, 0),
			new_color(250, 0, 50, 1), 1), 's', scene);
	add_object_to_scene((void *) new_sphere(new_point(1, 1, 0),
			new_color(250, 240, 20, 1), 1), 's', scene);
	add_object_to_scene((void *) new_sphere(new_point(0, 1, 0),
			new_color(250, 0, 220, 1), 1), 's', scene);
	return (scene);
}

int	main(int args, char **argv)
{
	t_input	*input;

	if (args != 2)
		exit_error("Invalid number of arguments");
	input = parse_input(argv[1]);
	if (!input)
		exit_error("Parsing error");
	debug_print(input);

	// mlx_set_setting(MLX_MAXIMIZED, true);  // ???
	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "miniRT", true);

	mlx_image_t* img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		ft_error();
	
	t_scene *scene = parse_scene();
	t_info *info = new_info(mlx, scene, img);	
	draw_pic(*scene, info->img);
	mlx_loop_hook(mlx, ft_hook, (void *) info);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	free_info(info);
	return (EXIT_SUCCESS);
}
