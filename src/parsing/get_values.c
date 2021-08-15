/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_values.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 05:09:35 by bledda            #+#    #+#             */
/*   Updated: 2021/08/15 05:58:35 by bledda           ###   ########.fr       */
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

static void	add_config_data(const char *line, t_isset *isset, t_cub *cub)
{
	char	**sline;

	if (ft_strlen(line) == 0)
		return ;
	sline = ft_split(line, ' ');
	if (sline[0] && (!ft_strncmp(sline[0], "NO", 2)
			&& !ft_strncmp(sline[0], "SO", 2) && !ft_strncmp(sline[0], "WE", 2)
			&& !ft_strncmp(sline[0], "EA", 2) && !ft_strncmp(sline[0], "F", 1)
			&& !ft_strncmp(sline[0], "C", 1)))
	{
		isset->error = 1;
		free_split(&sline);
		return ;
	}
	if (!sline[1])
	{
		free_split(&sline);
		return ;
	}
	else if (ft_strlen(sline[0]) == 2)
		add_simple(isset, cub, &sline);
	else if (ft_strlen(sline[0]) == 1)
		add_multi(isset, cub, &sline);
	free_split(&sline);
}

static void	error_print(int is_true, const char *str, char **free_ptr)
{
	if (!is_true)
	{
		ft_error("\t", RED);
		ft_error(str, RED);
		ft_error("\n", RED);
	}
	else
		free(*free_ptr);
}

static int	param_not_found(t_isset *isset, t_cub *cub)
{
	if (isset->no && isset->so && isset->we
		&& isset->ea && isset->f && isset->c && !isset->error)
		return (0);
	ft_error("Error:\n", RED);
	error_print(isset->no, "-NO is not found or not valid",
		&cub->config.path_no);
	error_print(isset->so, "-SO is not found or not valid",
		&cub->config.path_so);
	error_print(isset->we, "-WE is not found or not valid",
		&cub->config.path_we);
	error_print(isset->ea, "-EA is not found or not valid",
		&cub->config.path_ea);
	if (!isset->f)
		ft_error("\t-F is not found or not valid\n", RED);
	if (!isset->c)
		ft_error("\t-C is not found or not valid\n", RED);
	if (isset->no && isset->so && isset->we
		&& isset->ea && isset->f && isset->c && isset->error)
		ft_error("\t-Badly formatted file or a texture could not be opened\n",
			RED);
	return (1);
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
