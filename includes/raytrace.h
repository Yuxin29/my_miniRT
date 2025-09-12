#ifndef RAYTRACE_H
# define RAYTRACE_H

# include "miniRT.h"

typedef struct s_ray
{
	t_vec3	origin;
	t_vec3	direction;;
}	t_ray;

typedef struct s_hit_record
{
	float	t; //t represents how far along the ray we go to reach the hit point.
	t_vec3	point; //hit point
	t_vec3	normal; //A normal is a vector that points perpendicular to the surface at a specific point.

}	t_hit_record;

t_vec3	ray_at(t_ray a, float t);

#endif
