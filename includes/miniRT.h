#ifndef MINIRT_H
# define MINIRT_H

# include "MLX42/MLX42.h"
# include <math.h>
# include <stdio.h>

typedef struct s_vec3
{
	float	x;
	float	y;
	float	z;
}	t_vec3;

//vector
t_vec3	vec_add(t_vec3 a, t_vec3 b);
t_vec3	vec_sub(t_vec3 a, t_vec3 b);
t_vec3	vec_scale(t_vec3 a, float scalar);
float	vec_len(t_vec3 a);
t_vec3	vec_normalize(t_vec3 v);
float	vec_dot(t_vec3 a, t_vec3 b);
t_vec3	vec_cross(t_vec3 a, t_vec3 b);

#include "raytrace.h"

#endif
