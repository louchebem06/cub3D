/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_char_map_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 02:23:34 by bledda            #+#    #+#             */
/*   Updated: 2021/10/15 02:27:40 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/ft_config.h"

static int	forbidden(char const c, char const *set)
{
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
			if (forbidden(m[(int)p.y][(int)p.x], "NSWE"))
				player = 1;
			if (forbidden(m[(int)p.y][(int)p.x], "123456789]"))
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
