/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_values.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 05:09:35 by bledda            #+#    #+#             */
/*   Updated: 2021/08/14 05:37:36 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/ft_config.h"

static int	sm(char **config)
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

static void	add_config_data(const char *line, t_isset *isset, t_cub *cub)
{
	char	**split_line;
	int		i;

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
	i = -1;
	while (split_line[++i])
		free(split_line[i]);
	free(split_line);
}

static int	param_not_found(t_isset *isset)
{
	int	i;

	i = 0;
	if (!isset->no || !isset->so || !isset->we
		|| !isset->ea || !isset->f || !isset->c)
		i = 1;
	if (!isset->no)
		printf("error: param NO is not found\n");
	if (!isset->so)
		printf("error: param SO is not found\n");
	if (!isset->we)
		printf("error: param WE is not found\n");
	if (!isset->ea)
		printf("error: param EA is not found\n");
	if (!isset->f)
		printf("error: param F is not found\n");
	if (!isset->c)
		printf("error: param C is not found\n");
	return (i);
}

int	get_values(char ***data_file, t_cub *cub)
{
	t_isset	isset;
	int		i;
	int		j;

	isset = (t_isset){0};
	i = -1;
	while ((*data_file)[++i])
	{
		add_config_data((*data_file)[i], &isset, cub);
		free((*data_file)[i]);
		if (isset.no && isset.so && isset.we && isset.ea && isset.f && isset.c)
			cub->config.map = ft_calloc(sizeof(char *), sm(*data_file + i) + 1);
		if (isset.no && isset.so && isset.we && isset.ea && isset.f && isset.c)
			break ;
	}
	j = 0;
	while ((*data_file)[++i])
	{
		cub->config.map[j++] = ft_strdup((*data_file)[i]);
		free((*data_file)[i]);
	}
	free((*data_file));
	if (param_not_found(&isset) || isset.error)
		return (0);
	return (1);
}
