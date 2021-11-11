/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty_line_in_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 20:55:24 by bledda            #+#    #+#             */
/*   Updated: 2021/11/11 13:50:23 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/ft_config.h"

int	empty_line_in_map(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
	{
		if (!ft_strlen(map[i]))
		{
			ft_error("Error:\n\t-Empty line in map\n", RED);
			return (1);
		}
	}
	return (0);
}
