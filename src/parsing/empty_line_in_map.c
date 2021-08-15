/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty_line_in_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 20:55:24 by bledda            #+#    #+#             */
/*   Updated: 2021/08/15 05:57:29 by bledda           ###   ########.fr       */
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
			ft_error("Error:\nLine empty in map is detect\n", RED);
			return (1);
		}
	}
	return (0);
}
