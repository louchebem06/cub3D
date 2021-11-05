/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_char_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 04:16:01 by mmehran           #+#    #+#             */
/*   Updated: 2021/11/05 14:47:03 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub_bonus.h"

char	get_map_char(const t_map *map, const t_position *ray,
		const t_position *p)
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
		return ('1');
	return (map->map[y][x]);
}

char	get_map_char2(const t_cub *cub, const t_position *ray,
						const t_position *p)
{
	const char	c = get_map_char(&cub->map, ray, p);
	t_position	door_pos;
	int			x;
	int			y;
	int			i;

	if (!cub->nb_doors)
		return (c);
	if (p->x > ray->x)
		x = ceilf(ray->x - 1);
	else
		x = floorf(ray->x);
	if (p->y > ray->y)
		y = ceilf(ray->y - 1);
	else
		y = floorf(ray->y);
	i = -1;
	while (++i < cub->nb_doors)
	{
		door_pos = cub->doors[i].pos;
		if (door_pos.x == x && door_pos.y == y)
			return (cub->doors[i].c);
	}
	return (c);
}
