#include    "miniRT.h"
#include    "render.h"
#include    "parsing.h"

void	close_window(void *param)
{
	t_scene	*scene;

	scene = (t_scene *)param;
	ft_free_scene(scene);
}

void    key_hook(mlx_key_data_t keydata, void *param)
{
	t_scene *scene;
    t_vec3  move;
    float   move_unit;
    float   scale;

    move = (t_vec3){0,0,0};
	move_unit = 1.0;
    scale = 0;
    scene = (t_scene *)param;
    if (keydata.action != MLX_PRESS)
    {
        return ;    
    }
	if (keydata.key == MLX_KEY_ESCAPE)
		close_window(scene);
    if (keydata.key == MLX_KEY_W)
		move = (t_vec3){0, +move_unit, 0};
    if (keydata.key == MLX_KEY_S)
		move = (t_vec3){0, -move_unit, 0};
    if (keydata.key == MLX_KEY_A)
		move = (t_vec3){move_unit, 0, 0};
    if (keydata.key == MLX_KEY_D)
		move = (t_vec3){-move_unit, 0, 0};

    // if (keydata.key == MLX_KEY_LEFT)
	// 	close_window(scene);
    // if (keydata.key == MLX_KEY_RIGHT)
	// 	close_window(scene);
    if (keydata.key == MLX_KEY_UP)
		scale = 1.2;
    if (keydata.key == MLX_KEY_DOWN)
		scale = 0.8;

    if (vec_len(move) > 0 || scale != 0)
    {
        scene->need_loop = 1;
        change_scene(scene, move, scale);
    }
}