/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forbiden_char_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 20:56:14 by bledda            #+#    #+#             */
/*   Updated: 2021/08/14 22:12:08 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/ft_config.h"

int	forbiden_char_map(char **map)
{
	int	y;
	int	x;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] != 'N' && map[y][x] != 'S'
				&& map[y][x] != 'E' && map[y][x] != 'W'
				&& map[y][x] != '0' && map[y][x] != '1'
				&& map[y][x] != ' ')
			{
				printf("Error:\n'%c' is forbiden char in map\n", map[y][x]);
				return (1);
			}
		}
	}
	return (0);
}
