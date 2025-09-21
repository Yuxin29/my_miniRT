#include "miniRT_bonus.h"  

// typedef struct s_hit_record
// {
// 	float	t; //t represents how far along the ray we go to reach the hit point.
// 	t_vec3	point; //hit point
// 	t_vec3	normal; //A normal is a vector that points perpendicular to the surface at a specific point.
// 	t_color	rgb; //0916modify
// }	t_hit_record;
//yuxin added for checkerboard
//after hit obj, use (x, z) to decide is it single or double
static	t_color apply_checkerboard(t_hit_record rec, t_color original_color)
{
	int x;
	int z; 

	x = rec.point.x;
	z = rec.point.z; 
	if (((x + z) % 2) == 0) //double not change
		return (original_color);
	else //gingle reverse
		return (t_color){255 - original_color.r, 255 - original_color.g, 255 - original_color.b}; 
}

//this one from lin, just need to apply checkerboard color here
/*
final_color = ambient + diffuse
*/
t_color	final_color(t_color obj_color, t_scene *scene, t_hit_record rec)
{
	t_color	final;
	t_color	ambient;
	t_color	diffuse;

	obj_color = apply_checkerboard(rec, obj_color);  //this line added
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