/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_char_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 20:57:18 by bledda            #+#    #+#             */
/*   Updated: 2021/10/15 02:22:31 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/ft_config.h"

int	min_char_map(char **m)
{
	t_position	p;
	int			player;
	int			wall;

	player = 0;
	p.y = -1;
	while (m[(int)++p.y])
	{
		p.x = -1;
		while (m[(int)p.y][(int)++p.x])
		{
			if (m[(int)p.y][(int)p.x] == 'N' || m[(int)p.y][(int)p.x] == 'S'
				|| m[(int)p.y][(int)p.x] == 'E' || m[(int)p.y][(int)p.x] == 'W')
				player = 1;
			if (m[(int)p.y][(int)p.x] == '1')
				wall = 1;
		}
	}
	if (!player)
		ft_error("Error:\n\t -Player position is not found in map\n", RED);
	if (!wall)
		ft_error("Error:\n\t -Wall is not found in map\n", RED);
	if (!player || !wall)
		return (1);
	return (0);
}
