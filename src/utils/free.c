#include "miniRT.h"
#include "parsing.h"

static void ft_free_objects(t_scene *scene)
{
    if (scene->sp)
    {
        free(scene->sp);
        scene->sp = NULL;
    }
    if (scene->pl)
    {
        free(scene->pl);
        scene->pl = NULL;
    }
    if (scene->cl)
    {
        free(scene->cl);
        scene->cl = NULL;
    }
}

void ft_free_scene(t_scene *scene)
{
    if (!scene)
        return;
    // Free spheres array if it exists
    if (scene->ambient_light)
        free(scene->ambient_light);
    if (scene->cam)
        free(scene->cam);
    // if (scene->light)
    //     free(scene->light);
    ft_free_objects(scene);
    free(scene);
}
