/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 18:13:22 by bledda            #+#    #+#             */
/*   Updated: 2021/08/14 03:41:11 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

typedef struct s_isset
{
	int	no;
	int	so;
	int	we;
	int	ea;
	int	f;
	int	c;
	int	error;
}		t_isset;

static int	size_map(char **config)
{
	int	i;

	i = 0;
	while (config[i])
		i++;
	return (i);
}

static int	valid_param(const char *str)
{
	if (!ft_strncmp(str, "NO", 2)
		|| !ft_strncmp(str, "SO", 2)
		|| !ft_strncmp(str, "WE", 2)
		|| !ft_strncmp(str, "EA", 2)
		|| !ft_strncmp(str, "F", 1)
		|| !ft_strncmp(str, "C", 1))
		return (1);
	return (0);
}

static void	add_simple(t_isset *isset, t_cub *cub, char ***split)
{
	char	**split_line;
	int		fd;

	split_line = *split;
	if (!ft_strncmp(split_line[0], "NO", 2))
	{
		cub->config.path_no = ft_strdup(split_line[1]);
		if (isset->no)
		{
			printf("error: several param %s exist\n", split_line[0]);
			isset->error = 1;
		}
		isset->no = 1;
	}
	else if (!ft_strncmp(split_line[0], "SO", 2))
	{
		cub->config.path_so = ft_strdup(split_line[1]);
		if (isset->so)
		{
			printf("error: several param %s exist\n", split_line[0]);
			isset->error = 1;
		}
		isset->so = 1;
	}
	else if (!ft_strncmp(split_line[0], "WE", 2))
	{
		cub->config.path_we = ft_strdup(split_line[1]);
		if (isset->we)
		{
			printf("error: several param %s exist\n", split_line[0]);
			isset->error = 1;
		}
		isset->we = 1;
	}
	else if (!ft_strncmp(split_line[0], "EA", 2))
	{
		cub->config.path_ea = ft_strdup(split_line[1]);
		if (isset->ea)
		{
			printf("error: several param %s exist\n", split_line[0]);
			isset->error = 1;
		}
		isset->ea = 1;
	}
	if (split_line[2])
	{
		isset->error = 1;
		printf("error: to many values in %s\n", split_line[0]);
		return ;
	}
	fd = open(split_line[1], O_RDONLY);
	if (fd == -1)
	{
		printf("error: %s in param %s cannot be opened\n", split_line[1], split_line[0]);
		isset->error = 1;
		return ;
	}
	close (fd);
}

//F 220,100,0
static void	add_multi(t_isset *isset, t_cub *cub, char ***split)
{
	char	**split_line;

	split_line = *split;
	(void)cub;
	/*
		Faut concatener si il y a lieu et apres split les virgule et faire le parsing
	*/
	printf("%s\n", split_line[1]);
	if (!ft_strncmp(split_line[0], "F", 1))
	{
		if (isset->f)
		{
			printf("error: several param %s exist\n", split_line[0]);
			isset->error = 1;
		}
		isset->f = 1;
	}
	else if (!ft_strncmp(split_line[0], "C", 1))
	{
		if (isset->c)
		{
			printf("error: several param %s exist\n", split_line[0]);
			isset->error = 1;
		}
		isset->c = 1;
	}
}

static void	add_config_data(const char *line, t_isset *isset, t_cub *cub)
{
	char	**split_line;

	if (ft_strlen(line) == 0)
		return ;
	split_line = ft_split(line, ' ');
	if (split_line[0] && !valid_param(split_line[0]))
	{
		printf("error: %s is an unknown parameter\n", split_line[0]);
		isset->error = 1;
		return ;
	}
	if (!split_line[1])
	{
		printf("error: param %s is empty\n", split_line[0]);
		isset->error = 1;
	}
	else if (ft_strlen(split_line[0]) == 2)
		add_simple(isset, cub, &split_line);
	else if (ft_strlen(split_line[0]) == 1)
		add_multi(isset, cub, &split_line);
}

static int	param_not_found(t_isset *isset)
{
	int	i;

	i = 0;
	if (!isset->no)
	{
		printf("error: param NO is not found\n");
		i = 1;
	}
	if (!isset->so)
	{
		printf("error: param SO is not found\n");
		i = 1;
	}
	if (!isset->we)
	{
		printf("error: param WE is not found\n");
		i = 1;
	}
	if (!isset->ea)
	{
		printf("error: param EA is not found\n");
		i = 1;
	}
	if (!isset->f)
	{
		printf("error: param F is not found\n");
		i = 1;
	}
	if (!isset->c)
	{
		printf("error: param C is not found\n");
		i = 1;
	}
	return (i);
}

static int	get_values(char ***data_file, t_cub *cub)
{
	char	**config;
	t_isset	isset;
	int		i;
	int		j;

	isset = (t_isset){0};
	config = *data_file;
	i = -1;
	while (config[++i])
	{
		add_config_data(config[i], &isset, cub);
		free(config[i]);
		if (isset.no && isset.so && isset.we && isset.ea && isset.f && isset.c)
		{
			cub->config.map = ft_calloc(sizeof(char *), size_map(config + i) + 1);
			break ;
		}
	}
	j = 0;
	while (config[++i])
	{
		cub->config.map[j++] = ft_strdup(config[i]);
		free(config[i]);
	}
	free(config);
	if (param_not_found(&isset) || isset.error)
		return (0);
	return (1);
}

static int	ft_extension(const char *file, const char *ext)
{
	int	size_file;
	int	size_ext;

	size_file = ft_strlen(file);
	size_ext = ft_strlen(ext);
	if (size_ext > size_file)
		return (0);
	size_file -= size_ext;
	size_ext = 0;
	while (file[size_file])
	{
		if (file[size_file++] != ext[size_ext++])
			return (0);
	}
	return (1);
}

static void	get_file(int fd, const char *file, char ***config)
{
	char	*line;
	int		i;

	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		i++;
		free(line);
	}
	i++;
	free(line);
	close (fd);
	fd = open(file, O_RDONLY);
	*config = ft_calloc(sizeof(char *), i + 1);
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		(*config)[i++] = ft_strdup(line);
		free(line);
	}
	if (ft_strlen(line) > 0)
		(*config)[i] = ft_strdup(line);
	free(line);
	close(fd);
}

static int	ft_config(t_cub *cub, const char *file)
{
	int		fd;
	char	**data_file;

	data_file = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1 || !ft_extension(file, ".cub"))
	{
		printf("error: your card is not in the correct format \".cub\" \
or the file could not be opened\n");
		return (0);
	}
	get_file(fd, file, &data_file);
	if (!get_values(&data_file, cub))
		return (0);
	for (int i = 0; cub->config.map[i]; i++)
		printf("%s\n", cub->config.map[i]);
	return (1);
}

int	main(int ac, const char **av)
{
	t_cub	cub;

	if (ac == 2 && ft_config(&cub, av[1]))
	{
		cub.win.mlx = mlx_init();
		cub.win.win = mlx_new_window(cub.win.mlx, WINDOWS_WIDTH,
				WINDOWS_HEIGHT, "cub3D");
		mlx_loop(cub.win.mlx);
	}
	else if (ac == 1)
		printf("error: please specify a map\n");
	else if (ac > 2)
		printf("error: too many arguments\n");
	return (0);
}
