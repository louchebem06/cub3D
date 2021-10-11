/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_in_air.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 23:46:57 by mmehran           #+#    #+#             */
/*   Updated: 2021/10/11 23:47:12 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

bool	is_in_air(const t_map *map, const t_position *ray, const t_position *p)
{
	int	x;
	int	y;

	if (p->x > ray->x)
		x = ceilf(ray->x - 1);
	else
		x = floorf(ray->x);
	if (p->y > ray->y)
		y = ceilf(ray->y - 1);
	else
		y = floorf(ray->y);
	if (x >= map->width || x < 0 || y >= map->height || y < 0)
		return (false);
	if (map->map[y][x] == '0')
		return (true);
	return (false);
}
