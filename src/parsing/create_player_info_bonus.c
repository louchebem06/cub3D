/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_player_info_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 02:57:14 by bledda            #+#    #+#             */
/*   Updated: 2021/10/27 01:00:33 by bledda           ###   ########.fr       */
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
				convert_player_angle(cub);
			}
		}
	}
}
