/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_check_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 23:33:33 by bledda            #+#    #+#             */
/*   Updated: 2021/10/28 13:38:06 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/ft_config.h"

static int	is_player_ground(int c)
{
	const char	set[] = "0NSWE";
	int			isset;
	int			i;

	isset = 0;
	i = -1;
	while (set[++i])
	{
		if (set[i] == c)
		{
			isset = 1;
			break ;
		}
	}
	return (isset);
}

static int	is_wall(int c)
{
	const char	set[] = "1";
	int			isset;
	int			i;

	isset = 0;
	i = -1;
	while (set[++i])
	{
		if (set[i] == c)
		{
			isset = 1;
			break ;
		}
	}
	return (isset);
}

static int	check_direction_player_ground(char **map, int x, int y, t_cub *cub)
{
	t_direction_parsing_wall	d;

	d.y_map = (int)cub->config.map_y;
	d.x_map = (int)cub->config.map_x;
	d.up = y - 1;
	d.down = y + 1;
	d.left = x - 1;
	d.right = x + 1;
	if (is_player_ground(map[y][x]))
	{
		if (d.up >= 0 && d.up < d.y_map)
			if (!is_wall(map[d.up][x]) && !is_player_ground(map[d.up][x]))
				return (0);
		if (d.down >= 0 && d.down < d.y_map)
			if (!is_wall(map[d.down][x]) && !is_player_ground(map[d.down][x]))
				return (0);
		if (d.left >= 0 && d.left < d.x_map)
			if (!is_wall(map[y][d.left]) && !is_player_ground(map[y][d.left]))
				return (0);
		if (d.right >= 0 && d.right < d.x_map)
			if (!is_wall(map[y][d.right])
				&& !is_player_ground(map[y][d.right]))
				return (0);
		if ((d.up < 0 || d.up >= d.y_map)
			|| (d.down < 0 || d.down >= d.y_map)
			|| (d.left < 0 || d.left >= d.x_map)
			|| (d.right < 0 || d.right >= d.x_map))
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
			if (!is_wall(map[dir.up][x]) && map[dir.up][x] != ' ')
				return (0);
		if (dir.down >= 0 && dir.down < dir.y_map)
			if (!is_wall(map[dir.down][x]) && map[dir.down][x] != ' ')
				return (0);
		if (dir.left >= 0 && dir.left < dir.x_map)
			if (!is_wall(map[y][dir.left]) && map[y][dir.left] != ' ')
				return (0);
		if (dir.right >= 0 && dir.right < dir.x_map)
			if (!is_wall(map[y][dir.right]) && map[y][dir.right] != ' ')
				return (0);
	}
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
			if (!check_direction_player_ground(cub->config.map, x, y, cub)
				|| !check_direction_space(cub->config.map, x, y, cub))
			{
				ft_error("Error\n\t -Maps not valid\n", RED);
				return (1);
			}
		}
	}
	return (0);
}
