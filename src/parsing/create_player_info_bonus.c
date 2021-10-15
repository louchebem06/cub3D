/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_player_info_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 02:57:14 by bledda            #+#    #+#             */
/*   Updated: 2021/10/15 03:26:52 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/ft_config.h"
#include <math.h>

static void	convert_player_angle(t_cub *cub)
{
	if (cub->player.angle == 'N')
		cub->player.angle = M_PI * 270 / 180;
	else if (cub->player.angle == 'E')
		cub->player.angle = M_PI * 0 / 180;
	else if (cub->player.angle == 'S')
		cub->player.angle = M_PI * 90 / 180;
	else if (cub->player.angle == 'W')
		cub->player.angle = M_PI * 180 / 180;
}

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
	return (ground[max(choose, 5)]);
}

void	create_player_info(t_cub *cub)
{
	int	y;
	int	x;

	y = -1;
	while (cub->config.map[++y])
	{
		x = -1;
		while (cub->config.map[y][++x])
		{
			if (cub->config.map[y][x] == 'N' || cub->config.map[y][x] == 'S'
				|| cub->config.map[y][x] == 'E' || cub->config.map[y][x] == 'W')
			{
				cub->player.pos.x = floorf(x) + 0.5;
				cub->player.pos.y = floorf(y) + 0.5;
				cub->player.angle = cub->config.map[y][x];
				cub->config.map[y][x] = floor_texture(cub->config.map, x, y);
				convert_player_angle(cub);
			}
		}
	}
}
