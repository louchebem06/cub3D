/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 23:43:42 by mmehran           #+#    #+#             */
/*   Updated: 2021/11/05 05:39:56 by mmehran          ###   ########.fr       */
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

static void	next_d(t_position *pos, const t_position *dir)
{
	const float	dx = left_right(pos->x * 2, dir->x > 0) / 2;
	const float	dy = left_right(pos->y, dir->y > 0);
	const float	slope = dir->y / dir->x;
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
		pos->x += next_x.x;
		pos->y += next_x.y;
	}
	else
	{
		pos->x += next_y.x;
		pos->y += next_y.y;
	}
}

char	get_map_char2(const t_map *map, const t_position *ray,
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
	if (x == 4 && y == 4)
		return ('P');
	return (map->map[y][x]);
}


t_position	ray_cast(const t_position *p, const float angle, const t_map *map)
{
	const t_position	dir = {cosf(angle), sinf(angle)};
	t_position			ray_pos;
	char				c;
	int					i;

	ray_pos = *p;
	c = get_map_char2(map, &ray_pos, p);
	i = 0;
	while (i++ < 100 && ft_isset_tab(c, "0!`@$"))
	{
		next(&ray_pos, &dir);
		c = get_map_char2(map, &ray_pos, p);
		if (c == 'P')
		{
			next_d(&ray_pos, &dir);
			c = get_map_char2(map, &ray_pos, p);
		}
	}
	return (ray_pos);
}
