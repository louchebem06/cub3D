/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_ground_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 00:53:49 by bledda            #+#    #+#             */
/*   Updated: 2021/11/05 12:02:17 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/ft_config_bonus.h"
#include "../../header/cub_bonus.h"

static char	floor_texture(char **map, int x, int y)
{
	const char	c[8] = {map[y - 1][x - 1], map[y - 1][x], map[y - 1][x + 1],
		map[y][x - 1], map[y][x + 1], map[y + 1][x - 1], map[y + 1][x],
		map[y + 1][x + 1]};
	const char	ground[5] = "0!`@$";
	int			choose[5];
	int			i;
	int			j;

	ft_memcpy(&choose, (int []){0, 0, 0, 0, 0}, sizeof(choose));
	i = -1;
	while (++i < 8)
	{
		j = -1;
		while (++j < 5)
			if (c[i] == ground[j])
				choose[j]++;
	}
	i = 0;
	j = 0;
	while (++i < 5)
		if (choose[j] < choose[i])
			j = i;
	return (ground[j]);
}

static void	map_sprite(t_cub *cub, char **map)
{
	const char	set[] = "NSEW";
	int			y;
	int			x;
	int			i;

	cub->config.map_s = ft_calloc(sizeof(char *), cub->config.map_y + 1);
	y = -1;
	while (++y < cub->config.map_y)
		cub->config.map_s[y] = ft_strdup(map[y]);
	y = -1;
	while (cub->config.map_s[++y])
	{
		x = -1;
		while (cub->config.map_s[y][++x])
		{
			i = -1;
			while (set[++i])
			{
				if (cub->config.map_s[y][x] == set[i])
					cub->config.map_s[y][x] = \
						floor_texture(cub->config.map_s, x, y);
			}
		}
	}
}

void	replace_ground(t_cub *cub)
{
	int	x;
	int	y;

	map_sprite(cub, cub->config.map);
	y = -1;
	while (++y < cub->config.map_y)
	{
		x = -1;
		while (++x < cub->config.map_x)
			if (ft_isset_tab(cub->config.map[y][x], "NSEWLpPOFHI|A"))
				find_texture(cub, cub->config.map, x, y);
	}
}
