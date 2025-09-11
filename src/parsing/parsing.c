#include "miniRT.h"
#include "parsing.h"

//check if each line is valid,
//it has to start with the 6 identifies, it can be empty line
//return 0 as error and 1 as valid line
static int validating_identifier(char *line)
{
	if (!line[0])
		return (0);
	if (ft_isspace(line[0]))
		return (1);
	else if (ft_strncmp(line, "A ", 2) == 0)
		return (1);
	else if (ft_strncmp(line, "C ", 2) == 0)
		return (1);
	else if (ft_strncmp(line, "L ", 2) == 0)
		return (1);
	else if (ft_strncmp(line, "sp ", 3) == 0)
		return (1);
	else if (ft_strncmp(line, "pl ", 3) == 0)
		return (1);
	else if (ft_strncmp(line, "cy ", 3) == 0)
		return (1);
	return (0);
}

static int	precheck_av(int ac, char **av)
{
	char	*ext;

	if (ac != 2)
		return(err_msg_code("wrong ac nbr", 0));
	ext = ft_strrchr(av[1], '.');
	if (!ext || ft_strcmp(ext, ".rt") != 0)
		return (err_msg_code("wrong format", 0));
	return (1);
}

//return 0 as error and 1 as parsing success
t_scene *parsing(int ac, char **av)
{
    int		fd;
	char	*line;
	t_scene	*scene;
	
	if (!precheck_av(ac, av))
		return (NULL);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("open file failed", 1);
		return (NULL);
	}
	scene = malloc(sizeof(t_scene));
	if (!scene)
	{
		ft_putstr_fd("malloc scene failed", 1);
		return (NULL);
	}
	ft_bzero(scene, sizeof(t_scene));
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);	//test printing, remove later
		//indentifila liken
		if (!validating_identifier(line))
		{
			ft_putstr_fd("invalid line in the file", 1);
			ft_free_scene(scene);
			return (NULL);
		}
		parsing_line(line, scene);
		free (line);
		line = get_next_line(fd);
	}
	return (scene);
}
