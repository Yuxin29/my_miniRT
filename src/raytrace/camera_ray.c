#include "miniRT.h"

/*
get the forward, up, right vector of the camera
forward → where the camera is looking (like Z axis)
right → the direction to the camera’s right-hand side (like X axis)
up → the direction above the camera’s head (like Y axis)
These three must form a right-handed system (not left-handed).
*/


void	init_camera_frame(t_camera	*cam, t_vec3 *right, t_vec3 *up)
{
	t_vec3	forward;
	t_vec3	up;

	forward = vec_normalize(cam->v_orien);
	up = {0, 1, 0};
	if (fabs(vec_dot(forward, up)) > 0.999)
		up = {0, 0, 1};
	*right = vec_normalize(vec_cross(forward, up));
	*up = vec_cross(*right, forward);
}
