/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_check_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 23:33:33 by bledda            #+#    #+#             */
/*   Updated: 2021/08/15 08:05:22 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/ft_config.h"

static int	is_player_ground(int c)
{
	if (c == '0' || c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	return (0);
}

static int	check_direction_player_ground(char **map, int x, int y, t_cub *cub)
{
	t_direction_parsing_wall	dir;

	dir.y_map = (int)cub->config.map_y;
	dir.x_map = (int)cub->config.map_x;
	dir.up = y - 1;
	dir.down = y + 1;
	dir.left = x - 1;
	dir.right = x + 1;
	if (is_player_ground(map[y][x]))
	{
		if (dir.up >= 0 && dir.up < dir.y_map)
			if (map[dir.up][x] != '1' && !is_player_ground(map[dir.up][x]))
				return (0);
		if (dir.down >= 0 && dir.down < dir.y_map)
			if (map[dir.down][x] != '1' && !is_player_ground(map[dir.down][x]))
				return (0);
		if (dir.left >= 0 && dir.left < dir.x_map)
			if (map[y][dir.left] != '1' && !is_player_ground(map[y][dir.left]))
				return (0);
		if (dir.right >= 0 && dir.right < dir.x_map)
			if (map[y][dir.right] != '1'
				&& !is_player_ground(map[y][dir.right]))
				return (0);
	}
	return (1);
}

static int	check_direction_space(char **map, int x, int y, t_cub *cub)
{
	t_direction_parsing_wall	dir;

	dir.y_map = (int)cub->config.map_y;
	dir.x_map = (int)cub->config.map_x;
	dir.up = y - 1;
	dir.down = y + 1;
	dir.left = x - 1;
	dir.right = x + 1;
	if (map[y][x] == ' ')
	{
		if (dir.up >= 0 && dir.up < dir.y_map)
			if (map[dir.up][x] != '1' && map[dir.up][x] != ' ')
				return (0);
		if (dir.down >= 0 && dir.down < dir.y_map)
			if (map[dir.down][x] != '1' && map[dir.down][x] != ' ')
				return (0);
		if (dir.left >= 0 && dir.left < dir.x_map)
			if (map[y][dir.left] != '1' && map[y][dir.left] != ' ')
				return (0);
		if (dir.right >= 0 && dir.right < dir.x_map)
			if (map[y][dir.right] != '1' && map[y][dir.right] != ' ')
				return (0);
	}
	return (1);
}

static int	check_direction(char **map, int x, int y, t_cub *cub)
{
	if (!check_direction_player_ground(map, x, y, cub)
		|| !check_direction_space(map, x, y, cub))
		return (0);
	return (1);
}

int	wall_check_map(t_cub *cub)
{
	int	x;
	int	y;

	cub->config.map_x = size_map(&cub->config.map, 'x');
	cub->config.map_y = size_map(&cub->config.map, 'y');
	normalize_map(&cub->config.map);
	y = -1;
	while (cub->config.map[++y])
	{
		x = -1;
		while (cub->config.map[y][++x])
		{
			if (!check_direction(cub->config.map, x, y, cub))
			{
				ft_error("Error\n\tMaps not valid\n", RED);
				return (1);
			}
		}
	}
	return (0);
}
