#include "miniRT.h"
#include "parsing.h"

static bool check_valid_color(char *color)
{
    int i;

    i = 0;
	while (color[i])
	{
		if (!ft_isdigit(color[i]))
			return false;
		i++;
	}
	if (ft_atoi(color) > 255)
		return false;
	return true;
}

bool do_color(char **colors, t_color *rgb)
{
	int i;

    i = 0;
    if (count_token_nbr(colors) != 3)
		return false;
	while(colors[i])
	{
        if (!check_valid_color(colors[i]))
			return false;
		i++;
	}
	rgb->r = ft_atoi(colors[0]);
	rgb->g  = ft_atoi(colors[1]);
	rgb->b  = ft_atoi(colors[2]);
	return (true);
}

// | Axis                           | Recommended Range | Explanation                                                           |
// | ------------------------------ | ----------------- | --------------------------------------------------------------------- |
// | x, y, z                        | `-1000 ~ +1000`   | Enough space to place multiple objects and move the camera around     |
// | Distance from camera to object | `10 ~ 500`        | Ensures objects are visible and don't clip or "go through" the camera |
bool do_xyz_vectoy(char **vec, t_vec3 *vec_xyz)
{
	int i;

    i = 0;
    if (count_token_nbr(vec) != 3)
		return false;
	while(vec[i])
	{
        if (vec[i][0] == '-')		//more check
			return false;
		i++;
	}
	vec_xyz->x = ft_atoi_float(vec[0]); 
	vec_xyz->y = ft_atoi_float(vec[1]); 
	vec_xyz->z = ft_atoi_float(vec[2]); 
	return true;
}

bool do_normalized_vectoy(char **vec, t_vec3 *vec_nor)
{  
	int i;

    i = 0;
    if (count_token_nbr(vec) != 3)
		return false;
	while(vec[i])
	{
        if (vec[i][0] == '-')		//more check
			return false;
		i++;
	}
	vec_nor->x = ft_atoi_float(vec[0]); 
	vec_nor->y = ft_atoi_float(vec[1]); 
	vec_nor->z = ft_atoi_float(vec[2]); 
	return true;
}