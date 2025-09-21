#include "miniRT.h"

/*
final_color = ambient + diffuse
*/
t_color	final_color(t_color obj_color, t_scene *scene, t_hit_record rec)
{
	t_color	final;
	t_color	ambient;
	t_color	diffuse;

	ambient = apply_ambient(obj_color, scene->ambient_light);
	if(is_in_shadow(rec, scene->light, scene->objects))
		diffuse = (t_color){0, 0, 0};
	else
		diffuse = apply_diffuse(scene->light, rec);
	final.r = clamp(ambient.r + diffuse.r, 0, 255);
	final.g = clamp(ambient.g + diffuse.g, 0, 255);
	final.b = clamp(ambient.b + diffuse.b, 0, 255);
	return (final);
}
