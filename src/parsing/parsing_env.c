#include "miniRT.h"
#include "parsing.h"

bool validate_parsing_tokens_a(char **tokens, t_scene *scene)
{
	char	**colors;

	ft_bzero(&scene->ambient_light, sizeof(t_a_light));
	colors = ft_split(tokens[2], ',');
	if (!colors)
		return false; //need to have error msgs??
	
	if (!do_color(colors, &(scene->ambient_light.rgb)))
	{
		ft_free_arr(colors);
		return false;
	}

	//float not check yet
	scene->ambient_light.ratio = ft_atoi_float(tokens[1]);
	ft_free_arr(colors);
	return true;
}

bool validate_parsing_tokens_c(char **tokens, t_scene *scene)
{
	char	**vec_1;
	char	**vec_2;

	ft_bzero(&scene->cam, sizeof(t_camera));
	vec_1 =  ft_split(tokens[1], ',');
	vec_2 =  ft_split(tokens[2], ',');
	scene->cam.fov = ft_atoi((const char *)tokens[3]);
	if (!vec_1 || !vec_2)
	{
		if (vec_1)
			ft_free_arr(vec_1);
		if (vec_2)
			ft_free_arr(vec_2);
		return false;
	}
	if (!do_xyz_vectoy(vec_1, &scene->cam.v_point) || !do_normalized_vectoy(vec_2, &scene->cam.v_orien))
	{
		ft_free_arr(vec_1);
		ft_free_arr(vec_2);
		return false;
	}
	ft_free_arr(vec_1);
	ft_free_arr(vec_2);
	return true;
}

bool validate_parsing_tokens_l(char **tokens, t_scene *scene)
{
	char	**vec;

	ft_bzero(&scene->light, sizeof(t_light));
	vec =  ft_split(tokens[1], ',');
	if (!vec)
		return false;
	if (!do_xyz_vectoy(vec, &scene->light.l_point))
	{
		ft_free_arr(vec);
		return false;
	}
	scene->light.br_ratio = ft_atoi((const char *)tokens[2]);
	ft_free_arr(vec);
	return true;
}


