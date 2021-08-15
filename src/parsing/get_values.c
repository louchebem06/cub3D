/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_values.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 05:09:35 by bledda            #+#    #+#             */
/*   Updated: 2021/08/15 04:32:18 by bledda           ###   ########.fr       */
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

	if (ft_strlen(line) == 0)
		return ;
	split_line = ft_split(line, ' ');
	if (split_line[0] && !valid_param(split_line[0]))
	{
		isset->error = 1;
		free_split(&split_line);
		return ;
	}
	if (!split_line[1])
	{
		free_split(&split_line);
		return ;
	}
	else if (ft_strlen(split_line[0]) == 2)
		add_simple(isset, cub, &split_line);
	else if (ft_strlen(split_line[0]) == 1)
		add_multi(isset, cub, &split_line);
	free_split(&split_line);
}

static int	param_not_found(t_isset *isset, t_cub *cub)
{
	int	i;

	i = 0;
	if (!isset->no || !isset->so || !isset->we
		|| !isset->ea || !isset->f || !isset->c || isset->error)
	{
		printf("Error:\n");
		i = 1;
	}
	if (!isset->no)
		printf("\t-NO is not found or not valid\n");
	else if (i)
		free(cub->config.path_no);
	if (!isset->so)
		printf("\t-SO is not found or not valid\n");
	else if (i)
		free(cub->config.path_so);
	if (!isset->we)
		printf("\t-WE is not found or not valid\n");
	else if (i)
		free(cub->config.path_we);
	if (!isset->ea)
		printf("\t-EA is not found or not valid\n");
	else if (i)
		free(cub->config.path_ea);
	if (!isset->f)
		printf("\t-F is not found or not valid\n");
	if (!isset->c)
		printf("\t-C is not found or not valid\n");
	if (isset->no && isset->so && isset->we
		&& isset->ea && isset->f && isset->c && isset->error)
		printf("\t-Badly formatted file or a texture could not be opened\n");
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
		if (isset.no && isset.so && isset.we && isset.ea && isset.f && isset.c
			&& !isset.error)
		{
			cub->config.map = ft_calloc(sizeof(char *), sm(*data_file + i) + 1);
			break ;
		}
	}
	j = 0;
	while ((*data_file)[i] && (*data_file)[++i])
		if (isset.no && isset.so && isset.we && isset.ea && isset.f && isset.c)
			cub->config.map[j++] = ft_strdup((*data_file)[i]);
	free_split(data_file);
	if (param_not_found(&isset, cub))
		return (0);
	return (1);
}
