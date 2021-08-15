/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forbiden_char_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 20:56:14 by bledda            #+#    #+#             */
/*   Updated: 2021/08/15 05:57:43 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/ft_config.h"

static void	error_msg_forbiden_char_map(int c)
{
	char	tab[2];

	tab[0] = c;
	tab[1] = 0;
	ft_error("Error:\n'", RED);
	ft_error(tab, RED);
	ft_error("' forbiden char in map\n", RED);
}

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
				error_msg_forbiden_char_map(map[y][x]);
				return (1);
			}
		}
	}
	return (0);
}
