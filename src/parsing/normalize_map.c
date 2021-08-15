/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 06:03:06 by bledda            #+#    #+#             */
/*   Updated: 2021/08/15 06:04:06 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/ft_config.h"

void	normalize_map(char ***map)
{
	int	max_size;
	int	y;

	max_size = size_map(map, 'x');
	y = -1;
	while ((*map)[++y])
	{
		if ((int)ft_strlen((*map)[y]) < max_size)
			add_space(&(*map)[y], max_size - (int)ft_strlen((*map)[y]));
	}
}
