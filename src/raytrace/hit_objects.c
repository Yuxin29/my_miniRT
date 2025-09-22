#include "miniRT.h"

//static bool	update_hit_record(t_hit_record *tmp, float *closest_t, t_hit_record *rec, t_object *obj)
// static bool	update_hit_record(t_hit_record *tmp, float *closest_t, t_hit_record *rec)
// {
// 	bool	any_hit;

// 	any_hit = false;
// 	if (tmp->t > EPSILON && tmp->t < *closest_t)
// 	// if(tmp->t < *closest_t)
// 	{
// 		*closest_t = tmp->t;
// 		*rec = *tmp;
// 		// if (obj->type == OBJ_SP)
// 		// 	rec->rgb = ((t_sphere *)obj->data)->rgb;
// 		// else if(obj->type == OBJ_PL)
// 		// 	rec->rgb = ((t_plane *)obj->data)->rgb;
// 		// else if(obj->type == OBJ_CY)
// 		// 	rec->rgb = ((t_cylinder *)obj->data)->rgb;
// 		any_hit = true;
// 	}
// 	return (any_hit);
// }
bool	hit_objects(t_ray ray, t_object *obj, t_hit_record *rec)
// bool	hit_objects(t_ray ray, t_object *obj, t_hit_record *rec, t_object *ignore)
{
	bool			cur_hit;
	t_hit_record	tmp;
	float			closest_t;
	bool			any_hit;

	closest_t = INFINITY;
	any_hit = false;
	while(obj)
	{
		// if (obj == ignore) // ignore itself
		// {
		// 	obj = obj->next;
		// 	continue;
		// }
		cur_hit = false;
		if (obj->type == OBJ_SP)
			cur_hit = hit_sphere(ray, (t_sphere *)obj->data, &tmp);
		if (obj->type == OBJ_PL)
			cur_hit = hit_plane(ray, (t_plane *)obj->data, &tmp);
		if(obj->type == OBJ_CY)
			cur_hit = hit_cylinder(ray, (t_cylinder *)obj->data, &tmp);
		// if (cur_hit)
		// 	any_hit = update_hit_record(&tmp, &closest_t, rec);
		if (cur_hit && tmp.t < closest_t && tmp.t > 1e-4)
		{
			closest_t = tmp.t;
			*rec = tmp;
			any_hit = true;
		}
		obj = obj->next;
	}
	return (any_hit);
}
