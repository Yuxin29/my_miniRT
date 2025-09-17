#ifndef RENDER_H
# define RENDER_H

typedef struct s_scene t_scene;

typedef struct s_render_data
{
	t_ray			ray;
	t_camera_view	view;
	t_hit_record	rec;
	t_color			c;
}	t_render_data;

//self_defined header
# include "../libft/libft.h"
#include "MLX42/MLX42.h"
#include "miniRT.h"
#include "parsing.h"

//mlx_window.c
void	render_scene(t_scene *scene);
bool	mlx_window(t_scene *scene);

#endif
