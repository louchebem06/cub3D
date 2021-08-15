/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 06:02:51 by bledda            #+#    #+#             */
/*   Updated: 2021/08/15 06:04:05 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/ft_config.h"

int	size_map(char ***map, int c)
{
	int	i;
	int	x;
	int	tmp;

	if (c == 'x')
	{
		i = -1;
		x = 0;
		while ((*map)[++i])
		{
			tmp = ft_strlen((*map)[i]);
			if (tmp > x)
				x = tmp;
		}
		return (x);
	}
	else if (c == 'y')
	{
		i = 0;
		while ((*map)[i])
			i++;
		return (i);
	}
	return (0);
}
