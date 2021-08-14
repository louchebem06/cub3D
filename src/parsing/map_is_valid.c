/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_is_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 06:21:35 by bledda            #+#    #+#             */
/*   Updated: 2021/08/14 19:15:52 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/ft_config.h"

static void	copy_map(char ***new_map, char ***map)
{
	int	i;

	i = -1;
	while ((*map)[++i])
		free((*map)[i]);
	free(*map);
	i = 0;
	while ((*new_map)[i])
		i++;
	*map = ft_calloc(sizeof(char *), i + 1);
	i = -1;
	while ((*new_map)[++i])
	{
		(*map)[i] = ft_strdup((*new_map)[i]);
		free((*new_map)[i]);
	}
	free(*new_map);
}

static int	end_map(char **map)
{
	int	end_i;

	end_i = 0;
	while (map[end_i])
		end_i++;
	if (end_i)
		while (map[end_i - 1] && !ft_strlen(map[end_i - 1]))
		{
			end_i--;
			if (end_i < 1)
				break ;
		}
	return (end_i);
}

static int	start_map(char **map)
{
	int	start_i;

	start_i = 0;
	while (map[start_i] && !ft_strlen(map[start_i]))
		start_i++;
	return(start_i);
}

static int	remove_newlines(char ***map)
{
	int		start_i;
	int		end_i;
	int		i;
	char	**new_map;

	end_i = end_map(*map);
	start_i = start_map(*map);
	i = -1;
	if (start_i == end_i || start_i > end_i)
	{
		while ((*map)[++i])
			free((*map)[i]);
		free(*map);
		printf("Error:\nMap not found\n");
		return (0);
	}
	new_map = ft_calloc(sizeof(char *), end_i - start_i);
	while (start_i < end_i)
		new_map[i++] = ft_strdup((*map)[start_i++]);
	copy_map(&new_map, map);
	return (1);
}

int	map_is_valid(t_cub *cub)
{
	if (!remove_newlines(&cub->config.map))
	{
		free(cub->config.path_ea);
		free(cub->config.path_no);
		free(cub->config.path_so);
		free(cub->config.path_we);
		return (0);
	}
	for (int i = 0;cub->config.map[i];i++)
		free(cub->config.map[i]);
	free(cub->config.map);
	free(cub->config.path_ea);
	free(cub->config.path_no);
	free(cub->config.path_so);
	free(cub->config.path_we);
	while(1)
	{
	}
	return (1);
}
