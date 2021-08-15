/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_values_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 05:19:53 by bledda            #+#    #+#             */
/*   Updated: 2021/08/15 04:43:50 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/ft_config.h"

static void	check_value_simple(char ***split_line, t_cub *cub, t_isset *isset)
{
	if (!ft_strncmp((*split_line)[0], "NO", 2))
	{
		if (isset->no)
		{
			free(cub->config.path_no);
			isset->error = 1;
		}
		cub->config.path_no = ft_strdup((*split_line)[1]);
		isset->no = 1;
	}
	if (!ft_strncmp((*split_line)[0], "SO", 2))
	{
		if (isset->so)
		{
			free(cub->config.path_so);
			isset->error = 1;
		}
		cub->config.path_so = ft_strdup((*split_line)[1]);
		isset->so = 1;
	}
	if (!ft_strncmp((*split_line)[0], "WE", 2))
	{
		if (isset->we)
		{
			free(cub->config.path_we);
			isset->error = 1;
		}
		cub->config.path_we = ft_strdup((*split_line)[1]);
		isset->we = 1;
	}
	if (!ft_strncmp((*split_line)[0], "EA", 2))
	{
		if (isset->ea)
		{
			free(cub->config.path_ea);
			isset->error = 1;
		}
		cub->config.path_ea = ft_strdup((*split_line)[1]);
		isset->ea = 1;
	}
}

void	add_simple(t_isset *isset, t_cub *cub, char ***split_line)
{
	int		fd;

	if ((*split_line)[2])
	{
		isset->error = 1;
		return ;
	}
	check_value_simple(split_line, cub, isset);
	fd = open((*split_line)[1], O_RDONLY);
	if (fd == -1)
	{
		isset->error = 1;
		return ;
	}
	close (fd);
}

static void	check_value_multi(char ***split_arg, t_rgb *color, t_isset *isset)
{
	if ((*split_arg)[0] && (*split_arg)[1] && (*split_arg)[2]
		&& !(*split_arg)[3] && ft_strisdigit((*split_arg)[0])
		&& ft_strisdigit((*split_arg)[1]) && ft_strisdigit((*split_arg)[2]))
	{
		color->r = ft_atoi((*split_arg)[0]);
		color->g = ft_atoi((*split_arg)[1]);
		color->b = ft_atoi((*split_arg)[2]);
		if (color->r > 255 || color->g > 255 || color->b > 255)
			isset->error = 1;
	}
	else
		isset->error = 1;
	free_split(split_arg);
}

static int	count_char(const char *str)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (str[++i])
		if (str[i] == ',')
			j++;
	return (j);
}

void	add_multi(t_isset *isset, t_cub *cub, char ***split_line)
{
	int		i;
	char	*arg;
	char	**split_arg;

	i = 1;
	arg = ft_strdup((*split_line)[1]);
	if ((*split_line)[2])
		while ((*split_line)[++i])
			add_value(&arg, (*split_line)[i]);
	split_arg = ft_split(arg, ',');
	if (count_char(arg) > 2)
		isset->error = 1;
	free(arg);
	if ((!ft_strncmp((*split_line)[0], "F", 1) && isset->f)
		|| (!ft_strncmp((*split_line)[0], "C", 1) && isset->c))
		isset->error = 1;
	if (!ft_strncmp((*split_line)[0], "F", 1))
		isset->f = 1;
	else if (!ft_strncmp((*split_line)[0], "C", 1))
		isset->c = 1;
	if (!ft_strncmp((*split_line)[0], "F", 1))
		check_value_multi(&split_arg, &cub->config.floor, isset);
	else if (!ft_strncmp((*split_line)[0], "C", 1))
		check_value_multi(&split_arg, &cub->config.ceiling, isset);
}
