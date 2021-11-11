/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_check_map_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 02:30:25 by bledda            #+#    #+#             */
/*   Updated: 2021/11/11 13:56:35 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/ft_config.h"

static int	check_player_ground(t_direction_parsing_wall d, char **map,
								int x, int y)
{
	if (d.up >= 0 && d.up < d.y_map)
		if (!ft_isset_tab(map[d.up][x], "123456789]")
			&& !ft_isset_tab(map[d.up][x], "0NSWELpPOFHI|A!`@$"))
			return (0);
	if (d.down >= 0 && d.down < d.y_map)
		if (!ft_isset_tab(map[d.down][x], "123456789]")
			&& !ft_isset_tab(map[d.down][x], "0NSWELpPOFHI|A!`@$"))
			return (0);
	if (d.left >= 0 && d.left < d.x_map)
		if (!ft_isset_tab(map[y][d.left], "123456789]")
			&& !ft_isset_tab(map[y][d.left], "0NSWELpPOFHI|A!`@$"))
			return (0);
	if (d.right >= 0 && d.right < d.x_map)
		if (!ft_isset_tab(map[y][d.right], "123456789]")
			&& !ft_isset_tab(map[y][d.right], "0NSWELpPOFHI|A!`@$"))
			return (0);
	if ((d.up < 0 || d.up >= d.y_map)
		|| (d.down < 0 || d.down >= d.y_map)
		|| (d.left < 0 || d.left >= d.x_map)
		|| (d.right < 0 || d.right >= d.x_map))
		return (0);
	return (1);
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
	if (ft_isset_tab(map[y][x], "0NSWELpPOFHI|A!`@$"))
		if (!check_player_ground(d, map, x, y))
			return (0);
	return (1);
}

static int	check_space(t_direction_parsing_wall dir, char **map, int x, int y)
{
	if (dir.up >= 0 && dir.up < dir.y_map)
		if (!ft_isset_tab(map[dir.up][x], "123456789]")
			&& map[dir.up][x] != ' ')
			return (0);
	if (dir.down >= 0 && dir.down < dir.y_map)
		if (!ft_isset_tab(map[dir.down][x], "123456789]")
			&& map[dir.down][x] != ' ')
			return (0);
	if (dir.left >= 0 && dir.left < dir.x_map)
		if (!ft_isset_tab(map[y][dir.left], "123456789]")
			&& map[y][dir.left] != ' ')
			return (0);
	if (dir.right >= 0 && dir.right < dir.x_map)
		if (!ft_isset_tab(map[y][dir.right], "123456789]")
			&& map[y][dir.right] != ' ')
			return (0);
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
		if (!check_space(dir, map, x, y))
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
			if (!check_direction_player_ground(cub->config.map, x, y, cub)
				|| !check_direction_space(cub->config.map, x, y, cub))
			{
				ft_error("Error\n\t-Map invalid\n", RED);
				return (1);
			}
		}
	}
	return (0);
}
