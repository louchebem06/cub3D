/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_end_space_map.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 22:16:26 by bledda            #+#    #+#             */
/*   Updated: 2021/08/14 22:16:30 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/ft_config.h"

int	remove_end_space_map(char ***map)
{
	int	size;
	int	i;

	i = -1;
	while ((*map)[++i])
	{
		size = ft_strlen((*map)[i]);
		while (size > 0 && (*map)[i][size - 1] == ' ')
		{
			(*map)[i][size - 1] = 0;
			size = ft_strlen((*map)[i]);
		}
	}
	return (0);
}
