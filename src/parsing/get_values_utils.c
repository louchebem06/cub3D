/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_values_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 05:19:53 by bledda            #+#    #+#             */
/*   Updated: 2021/10/12 02:14:08 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/ft_config.h"

static void	add_error(int is_true, char **free_ptr, int *error)
{
	if (is_true)
	{
		free(*free_ptr);
		*error = 1;
	}
}

static void	check_value_simple(char ***split_line, t_cub *cub, t_isset *isset)
{
	if (!ft_strncmp((*split_line)[0], "NO", 2))
	{
		add_error(isset->no, &cub->config.path_no, &isset->error);
		cub->config.path_no = ft_strdup((*split_line)[1]);
		isset->no = 1;
	}
	if (!ft_strncmp((*split_line)[0], "SO", 2))
	{
		add_error(isset->so, &cub->config.path_so, &isset->error);
		cub->config.path_so = ft_strdup((*split_line)[1]);
		isset->so = 1;
	}
	if (!ft_strncmp((*split_line)[0], "WE", 2))
	{
		add_error(isset->we, &cub->config.path_we, &isset->error);
		cub->config.path_we = ft_strdup((*split_line)[1]);
		isset->we = 1;
	}
	if (!ft_strncmp((*split_line)[0], "EA", 2))
	{
		add_error(isset->ea, &cub->config.path_ea, &isset->error);
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
		&& !(*split_arg)[3] && is_valid_int((*split_arg)[0])
		&& is_valid_int((*split_arg)[1]) && is_valid_int((*split_arg)[2]))
	{
		color->r = ft_atoi((*split_arg)[0]);
		color->g = ft_atoi((*split_arg)[1]);
		color->b = ft_atoi((*split_arg)[2]);
		if (color->r > 255 || color->g > 255 || color->b > 255)
			isset->error = 1;
		if (color->r < 0 || color->g < 0 || color->b < 0)
			isset->error = 1;
	}
	else
		isset->error = 1;
	free_split(split_arg);
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
	if (count_char(arg, ',') > 2)
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
