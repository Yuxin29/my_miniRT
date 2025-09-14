#include "miniRT.h"
#include "parsing.h"
#include    "render.h"


//test printing delete alter
//=======================================================

void ft_print_scene(t_scene *scene)
{
	t_sphere	*cur_sp;
	t_plane		*cur_pl;
	t_cylinder	*cur_cy;
	int i = 1;

	printf("\n===== TEST PRINTING SCENE =====\n");

	// Ambient Light
	printf("Ambient Light:\n");
	printf("  ratio: %.2f\n", scene->ambient_light.ratio);
	printf("  color: R=%d G=%d B=%d\n",
		scene->ambient_light.rgb.r,
		scene->ambient_light.rgb.g,
		scene->ambient_light.rgb.b);

	// Camera
	printf("Camera:\n");
	printf("  position: x=%.2f y=%.2f z=%.2f\n",
		scene->cam.v_point.x,
		scene->cam.v_point.y,
		scene->cam.v_point.z);
	printf("  orientation: x=%.2f y=%.2f z=%.2f\n",
		scene->cam.v_orien.x,
		scene->cam.v_orien.y,
		scene->cam.v_orien.z);
	printf("  FOV: %.2f\n", scene->cam.fov);

	// Ambient Light
	printf("Light:\n");
	printf("  light point: x=%.2f y=%.2f z=%.2f\n",
		scene->light.l_point.x,
		scene->light.l_point.y,
		scene->light.l_point.z);
	printf("  brightness ratio: %.2f\n", scene->light.br_ratio);

	// Spheres
	cur_sp = scene->sp;
	if (!cur_sp)
		printf("Spheres: (none)\n");
	else
	{
		printf("Spheres (%d):\n", scene->sp_nbr);
		while (cur_sp)
		{
			printf("  Sphere %d:\n", i++);
			printf("    center: x=%.2f y=%.2f z=%.2f\n",
				cur_sp->sp_center.x, cur_sp->sp_center.y, cur_sp->sp_center.z);
			printf("    diameter: %.2f (radius: %.2f)\n",
				cur_sp->dia, cur_sp->radius);
			printf("    color: R=%d G=%d B=%d\n",
				cur_sp->rgb.r, cur_sp->rgb.g, cur_sp->rgb.b);
			cur_sp = cur_sp->next;
		}
	}

	// plane
	cur_pl = scene->pl;
	if (!cur_pl)
		printf("Planes: (none)\n");
	else
	{
		printf("Planes (%d):\n", scene->pl_nbr);
		while (cur_pl)
		{
			printf("  Planes %d:\n", i++);
			printf("    a point in the plane: x=%.2f y=%.2f z=%.2f\n",
				cur_pl->p_in_pl.x, cur_pl->p_in_pl.y, cur_pl->p_in_pl.z);
			printf("    3d normalized normal vector: x=%.2f y=%.2f z=%.2f\n",
				cur_pl->nor_v.x, cur_pl->nor_v.y, cur_pl->nor_v.z);
			printf("    color: R=%d G=%d B=%d\n",
				cur_pl->rgb.r, cur_pl->rgb.g, cur_pl->rgb.b);
			cur_pl = cur_pl->next;
		}
	}

	// Cylinder
	cur_cy = scene->cl;
	if (!cur_cy)
		printf("Cylinders: (none)\n");
	else
	{
		printf("Cylinders (%d):\n", scene->cl_nbr);
		while (cur_cy)
		{
			printf("  Cylinder %d:\n", i++);
			printf("    center of the cylinder: x=%.2f y=%.2f z=%.2f\n",
				cur_cy->cy_center.x, cur_cy->cy_center.y, cur_cy->cy_center.z);
			printf("    axis of cylinder: x=%.2f y=%.2f z=%.2f\n",
				cur_cy->cy_axis.x, cur_cy->cy_axis.y, cur_cy->cy_axis.z);
			printf("    diameter: %.2f (radius: %.2f)\n",
				cur_cy->dia, cur_cy->dia);
			printf("    height: %.2f (radius: %.2f)\n",
				cur_cy->dia, cur_cy->height);
			printf("    color: R=%d G=%d B=%d\n",
				cur_cy->rgb.r, cur_cy->rgb.g, cur_cy->rgb.b);
			cur_cy = cur_cy->next;
		}
	}

	// MLX info
	printf("MLX:\n");
	printf("  mlx ptr : %p\n", (void *)scene->mlx);
	printf("  img ptr : %p\n", (void *)scene->img);

	printf("===== END OF SCENE PRINT =====\n\n");
}


//=======================================================

//test version for compiling
int main(int ac, char **av)
{
	t_scene	*scene;
	
    //parsing
    scene = parsing(ac, av);
	if (!scene)
		return(-1); //erro msg sent in parsing
	
    // mlx
	if (!mlx_window(scene))
		return(err_msg_code("mlx initiation failed\n", -1));
	
        //cleaning up and exit
	ft_print_scene(scene);
	ft_free_scene(scene);
	
    return (0);
}


// #define WIDTH 800 //test
// #define HEIGHT 600 //test

// void	hook(void *param)
// {
// 	mlx_t	*mlx = param;
// 	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
// 		mlx_close_window(mlx);
// }

// int	main(void)
// {
// 	mlx_t	*mlx;

// 	mlx = mlx_init(WIDTH, HEIGHT, "miniRT", true);
// 	if (!mlx)
// 		return (EXIT_FAILURE);
// 	mlx_loop_hook(mlx, &hook, mlx);
// 	mlx_loop(mlx);
// 	mlx_terminate(mlx);
// 	return (EXIT_SUCCESS);
// }
