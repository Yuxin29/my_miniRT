#include "miniRT.h"
#include "parsing.h"

void get_a_light(char *line, t_scene *scene)
{
	char	**phases;
	char	**colors;

	phases = ft_split(line, ' ');
	if (!phases)
		return; //need to have error msgs???
	colors = ft_split(phases[2], ',');
	if (!colors)
		return; //need to have error msgs???	
	scene->ambient_light->ratio = phases[1]; // I need a atoi for floats here
	scene->ambient_light->r = ft_atoi((const char *)colors[0]);
	scene->ambient_light->g = ft_atoi((const char *)colors[1]);
	scene->ambient_light->b = ft_atoi((const char *)colors[2]);
}

void get_camera(char *line, t_scene *scene)
{
	char	**phases;

	phases = ft_split(line, ' ');
	if (!phases)
		return; //need to have error msgs???
	ft_bzero(scene->cam, sizeof(t_camera));
}

// static void get_light(char *line, t_scene *scene)
// {

// }

void get_sphere(char *line, t_scene *scene)
{
	char	**phases;

	phases = ft_split(line, ' ');
	if (!phases)
		return; //need to have error msgs???
	ft_bzero(scene->sp, sizeof(t_sphere));
}

void parsing_line(char *line, t_scene *scene)
{
	if (ft_isspace(line[0]))
		return ;
	else if (line[0] == 'A')
		get_a_light(line, scene);
	else if (line[0] == 'C')
		get_camera(line, scene);
	// else if (line[0] == 'L')
	// 	get_light(line, scene);
	if (line[0] && line[1])//I need a strncmp here
	{
		if (line[0] == 's' && line[1] == 'p')
			get_sphere(line, scene);
		// else if (line[0] == 'p' && line[1] == 'l')
		// 	get_plane(line, scene);
		// else if (line[0] == 'c' && line[1] == 'y')
		// 	get_cylinder(line, scene);
	}
}