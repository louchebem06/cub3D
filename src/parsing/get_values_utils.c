/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_values_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 05:19:53 by bledda            #+#    #+#             */
/*   Updated: 2021/08/14 06:17:18 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/ft_config.h"

static void	check_value_simple(char ***split_line, char **content, int *etat)
{
	*content = ft_strdup((*split_line)[1]);
	if (*etat)
		printf("error: several param %s exist\n", (*split_line)[0]);
	*etat = 1;
}

void	add_simple(t_isset *isset, t_cub *cub, char ***split_line)
{
	int		fd;

	if (!ft_strncmp((*split_line)[0], "NO", 2))
		check_value_simple(split_line, &cub->config.path_no, &isset->no);
	else if (!ft_strncmp((*split_line)[0], "SO", 2))
		check_value_simple(split_line, &cub->config.path_so, &isset->so);
	else if (!ft_strncmp((*split_line)[0], "WE", 2))
		check_value_simple(split_line, &cub->config.path_we, &isset->we);
	else if (!ft_strncmp((*split_line)[0], "EA", 2))
		check_value_simple(split_line, &cub->config.path_ea, &isset->ea);
	if ((*split_line)[2])
	{
		isset->error = 1;
		printf("error: to many values in %s\n", (*split_line)[0]);
		return ;
	}
	fd = open((*split_line)[1], O_RDONLY);
	if (fd == -1)
	{
		printf("error: %s in param %s cannot be opened\n",
			(*split_line)[1], (*split_line)[0]);
		isset->error = 1;
		return ;
	}
	close (fd);
}

static void	check_value_multi(char ***split_arg, char ***split_line,
	t_rgb *color, t_isset *isset)
{
	int	i;

	if ((*split_arg)[0] && (*split_arg)[1] && (*split_arg)[2]
		&& !(*split_arg)[3] && ft_strisdigit((*split_arg)[0])
		&& ft_strisdigit((*split_arg)[1]) && ft_strisdigit((*split_arg)[2]))
	{
		color->r = ft_atoi((*split_arg)[0]);
		color->g = ft_atoi((*split_arg)[1]);
		color->b = ft_atoi((*split_arg)[2]);
		if (color->r > 255 || color->g > 255 || color->b > 255)
		{
			isset->error = 1;
			printf("error: value color for %s and above 255\n",
				(*split_line)[0]);
		}
	}
	else
	{
		isset->error = 1;
		printf("error: arg is not valid for %s\n", (*split_line)[0]);
	}
	i = -1;
	while ((*split_arg)[++i])
		free((*split_arg)[i]);
	free(*split_arg);
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
	free(arg);
	if ((!ft_strncmp((*split_line)[0], "F", 1) && isset->f)
		|| (!ft_strncmp((*split_line)[0], "C", 1) && isset->c))
	{
		printf("error: several param %s exist\n", (*split_line)[0]);
		isset->error = 1;
	}
	if (!ft_strncmp((*split_line)[0], "F", 1))
		isset->f = 1;
	else if (!ft_strncmp((*split_line)[0], "C", 1))
		isset->c = 1;
	if (!ft_strncmp((*split_line)[0], "F", 1))
		check_value_multi(&split_arg, split_line, &cub->config.floor, isset);
	else if (!ft_strncmp((*split_line)[0], "C", 1))
		check_value_multi(&split_arg, split_line, &cub->config.ceiling, isset);
}
