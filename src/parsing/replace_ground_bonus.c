/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_ground_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 00:53:49 by bledda            #+#    #+#             */
/*   Updated: 2021/10/27 16:35:41 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/ft_config_bonus.h"
#include "../../header/cub_bonus.h"

static int	max(const int *tab, const int size)
{
	int	tmp;
	int	i;

	tmp = 0;
	i = 0;
	while (++i < size)
	{
		if (tab[tmp] < tab[i])
			tmp = i;
	}
	return (tmp);
}

static char	floor_texture(char **map, int x, int y)
{
	const char	c[8] = {map[y - 1][x - 1], map[y - 1][x], map[y - 1][x + 1],
		map[y][x - 1], map[y][x + 1], map[y + 1][x - 1], map[y + 1][x],
		map[y + 1][x + 1]};
	const char	ground[5] = "0!`@$";
	int			choose[5];
	int			i;
	int			j;

	i = -1;
	while (++i < 5)
		choose[i] = 0;
	i = -1;
	while (++i < 8)
	{
		j = -1;
		while (++j < 5)
		{
			if (c[i] == ground[j])
				choose[j]++;
		}
	}
	if (!choose[0] && !choose[1] && !choose[2] && !choose[3] && !choose[4])
		return ('a');
	return (ground[max(choose, 5)]);
}

static bool	isset_in_map(const char *set, char **map)
{
	int	y;
	int	x;
	int	i;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			i = -1;
			while (set[++i])
				if (map[y][x] == set[i])
					return (true);
		}
	}
	return (false);
}

static void	map_sprite(t_cub *cub, char **map)
{
	const char	set[] = "NSEWL";
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
	const char	set[] = "NSEWLPOFHI|Aa";
	const char	set2[] = "NSEWLPOFHI|A";
	int			y;
	int			x;
	int			i;

	map_sprite(cub, cub->config.map);
	while (isset_in_map(set, cub->config.map))
	{
		y = -1;
		while (cub->config.map[++y])
		{
			x = -1;
			while (cub->config.map[y][++x])
			{
				i = -1;
				while (set2[++i])
				{
					if (cub->config.map[y][x] == set[i])
						cub->config.map[y][x] = \
							floor_texture(cub->config.map, x, y);
				}
			}
		}
	}
}
