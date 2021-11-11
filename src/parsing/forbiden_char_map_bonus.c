/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forbiden_char_map_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 02:12:14 by bledda            #+#    #+#             */
/*   Updated: 2021/11/11 13:50:57 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/ft_config.h"

static void	error_msg_forbiden_char_map(int c)
{
	char	tab[2];

	tab[0] = c;
	tab[1] = 0;
	ft_error("Error:\n\t -'", RED);
	ft_error(tab, RED);
	ft_error("' forbidden char in map\n", RED);
}

static int	forbidden(char const c)
{
	const char	set[] = "NESW01 LPpOFHI|A23456789]!`@$";
	int			isset;
	int			i;

	isset = 1;
	i = -1;
	while (set[++i])
	{
		if (set[i] == c)
		{
			isset = 0;
			break ;
		}
	}
	return (isset);
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
			if (forbidden(map[y][x]))
			{
				error_msg_forbiden_char_map(map[y][x]);
				return (1);
			}
		}
	}
	return (0);
}
