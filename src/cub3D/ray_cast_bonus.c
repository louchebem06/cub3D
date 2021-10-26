/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 23:43:42 by mmehran           #+#    #+#             */
/*   Updated: 2021/10/23 23:52:15 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"
#include "../../header/utils_bonus.h"

static float	left_right(const float number, const bool direction)
{
	if (direction)
		return (floorf(number + 1) - number);
	return (ceilf(number - 1) - number);
}

static void	next(t_position *pos, const t_position *direction)
{
	const float	dx = left_right(pos->x, direction->x > 0);
	const float	dy = left_right(pos->y, direction->y > 0);
	const float	slope = direction->y / direction->x;
	t_position	next_x;
	t_position	next_y;

	next_x = (t_position){0};
	next_y = (t_position){0};
	next_x.x = dx;
	next_x.y = dx * slope;
	next_y.x = dy / slope;
	next_y.y = dy;
	if (next_x.x * next_x.x + next_x.y * next_x.y
		< next_y.x * next_y.x + next_y.y * next_y.y)
	{
		pos->x = roundf(pos->x + next_x.x);
		pos->y += next_x.y;
	}
	else
	{
		pos->x += next_y.x;
		pos->y = roundf(pos->y + next_y.y);
	}
}

t_position	ray_cast(const t_position *p, const float angle, const t_map *map)
{
	t_position	dir;
	t_position	ray_pos;
	char		c;

	dir.x = cosf(angle);
	dir.y = sinf(angle);
	ray_pos = *p;
	c = get_map_char(map, &ray_pos, p);
	while (ft_isset_tab(c, "0LPOFHI|A!`@$"))
	{
		next(&ray_pos, &dir);
		c = get_map_char(map, &ray_pos, p);
	}
	return (ray_pos);
}

t_position	ray_cast_sprite(const t_position *p, const float angle,
							const t_map *map)
{
	t_position	dir;
	t_position	ray_pos;
	char		c;

	dir.x = cosf(angle);
	dir.y = sinf(angle);
	ray_pos = *p;
	c = get_map_char(map, &ray_pos, p);
	while (ft_isset_tab(c, "0!`@$"))
	{
		next(&ray_pos, &dir);
		c = get_map_char(map, &ray_pos, p);
	}
	if (ft_isset_tab(c, "LPOFHI|A"))
	{
		//if (p->x > ray_pos.x)
		//	ray_pos.x = ceilf(ray_pos.x - 1);
		//else
		//	ray_pos.x = floorf(ray_pos.x);
		//if (p->y > ray_pos.y)
		//	ray_pos.y = ceilf(ray_pos.y - 1);
		//else
		//	ray_pos.y = floorf(ray_pos.y);
		//ray_pos.x += 0.5;
		//ray_pos.y += 0.5;
		return (ray_pos);
	}
	return ((t_position){-1, -1});
}
