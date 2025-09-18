#include	"miniRT.h"
#include	"render.h"
#include	"parsing.h"

//lin needs to uses this ??
// this is probably where our work overlapping each other
// I write this prototype here just as a starting point
// the color of each pixel will be calulated by lin
//0xAAFF1111, Transparency + rgb
void	render_scene(t_scene *scene)
{
	int				x;
	int				y;
	t_render_data	data;

	init_viewport(&scene->cam, &data.view);
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			data.ray = generate_primary_ray(x, y, &data.view);
			if (hit_objects(data.ray, scene->objects, &data.rec))
			{
				data.c = final_color(data.rec.rgb, scene->ambient_light, scene->light, data.rec);
				mlx_put_pixel(scene->img, x, y, (data.c.r << 24 | data.c.g << 16 | data.c.b << 8 | 255));
			}
			else
				mlx_put_pixel(scene->img, x, y, 0x000000FF);
			x++;
		}
		y++;
	}
}


static void render_scene_loop(void *param)
{
    t_scene *scene = (t_scene *)param;
	if (scene->need_loop)
	{
		render_scene(scene);
		scene->need_loop = false;
	}
}

//remove to render later
//mlx_init: 4th: full scree> true or false
bool	mlx_window(t_scene *scene)
{
	//this part need to take out later
	scene->mlx = mlx_init(WIDTH, HEIGHT, "miniRT_test", false);
	if (!scene->mlx)
    {
        ft_putstr_fd("mlx_init failed\n", 1);
        return (false);
    }
	scene->img = mlx_new_image(scene->mlx, WIDTH, HEIGHT);
    if (!scene->img)
	{
        ft_putstr_fd("mlx_new image failed\n", 1);
        return (false);
    }
	mlx_image_to_window(scene->mlx, scene->img, 0, 0);
	render_scene(scene);
    mlx_key_hook(scene->mlx, key_hook, scene); //Keyboard press/release
	mlx_close_hook(scene->mlx, close_window, scene);  //clicking red x
    
	//render_scene(scene);yuxin chcnange it to loop
	//scene->need_loop = true;
	mlx_loop_hook(scene->mlx, render_scene_loop, scene);
	mlx_loop(scene->mlx);
	return (true);
}
