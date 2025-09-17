#include    "miniRT.h"
#include    "render.h"
#include    "parsing.h"

void change_scene(t_scene *scene, t_vec3 move, float scale)
{
    t_object *cur;

    cur = scene->objects;
    while (cur)
    {
        if (cur->type == OBJ_SP)
        {
            if (vec_len(move) > 0 || scale != 0)
            {
                t_sphere *sp = (t_sphere *)cur->data;
                if (scale)
                    sp->radius = sp->radius * scale; 
                if (vec_len(move) > 0)
                    sp->sp_center = vec_add(sp->sp_center, move); 
            }
        }
        if (cur->type == OBJ_PL)
        {
            t_plane *pl = (t_plane *)cur->data;
            pl->p_in_pl = vec_add(pl->p_in_pl, move); 
        }
        if (cur->type == OBJ_CY)
        {
            t_cylinder *cy = (t_cylinder *)cur->data;
            cy->cy_center = vec_add(cy->cy_center, move);
        }    
        cur = cur->next;
    }
}