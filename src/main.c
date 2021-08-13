/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 18:13:22 by bledda            #+#    #+#             */
/*   Updated: 2021/08/14 01:04:38 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

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
		if (file[size_file++] != ext[size_ext++])
			return (0);
	return (1);
}

/*
	Ne peut etre valide car si il y a des retour a la ligne dans la maps
	ont ne peut pas les detecter
*/
static char	**get_config(int fd, const char *file)
{
	char	**config;
	char	*line;
	int		i;

	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (ft_strlen(line) > 0)
			i++;
		free(line);
	}
	if (ft_strlen(line) > 0)
		i++;
	free(line);
	close (fd);
	fd = open(file, O_RDONLY);
	config = ft_calloc(sizeof(char *), i + 1);
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (ft_strlen(line) > 0)
			config[i++] = ft_strdup(line);
		free(line);
	}
	if (ft_strlen(line) > 0)
		config[i] = ft_strdup(line);
	free(line);
	close(fd);
	return (config);
}

static int	ft_config(t_cub *cub, const char *file)
{
	int		fd;
	char	**config;

	(void)cub;
	fd = open(file, O_RDONLY);
	if (fd == -1 || !ft_extension(file, ".cub"))
	{
		printf("error: your card is not in the correct \".cub\" \
format or the file could not be opened\n");
		return (0);
	}
	config = get_config(fd, file);
	for (int i = 0; config[i]; i++)
		printf("%s\n", config[i]);
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
