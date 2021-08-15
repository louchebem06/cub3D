/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_player_info.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 22:43:37 by bledda            #+#    #+#             */
/*   Updated: 2021/08/15 10:04:13 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/ft_config.h"

static void	convert_player_angle(t_cub *cub)
{
	if (cub->player.angle == 'N')
		cub->player.angle = 0;
	else if (cub->player.angle == 'E')
		cub->player.angle = 90;
	else if (cub->player.angle == 'S')
		cub->player.angle = 180;
	else if (cub->player.angle == 'W')
		cub->player.angle = 270;
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
				cub->player.pos.x = x;
				cub->player.pos.y = y;
				cub->player.angle = cub->config.map[y][x];
				cub->config.map[y][x] = '0';
				convert_player_angle(cub);
			}
		}
	}
}
