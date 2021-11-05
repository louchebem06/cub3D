/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 23:43:42 by mmehran           #+#    #+#             */
/*   Updated: 2021/11/05 14:11:52 by mmehran          ###   ########.fr       */
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

static void	next_d(t_position *pos, const t_position *dir, float percent)
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
		if (percent < pos->y + next_x.y - floorf(pos->y + next_x.y))
		{
			next(pos, dir);
			return ;
		}
		pos->x += next_x.x;
		pos->y += next_x.y;
	}
	else
	{
		pos->x += next_y.x;
		pos->y += next_y.y;
	}
}

static void	next_d2(t_position *pos, const t_position *dir, float percent)
{
	const float	dx = left_right(pos->x, dir->x > 0);
	const float	dy = left_right(pos->y * 2, dir->y > 0) / 2;
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
		if (percent < pos->x + next_y.x - floorf(pos->x + next_y.x))
		{
			next(pos, dir);
			return ;
		}
		pos->x += next_y.x;
		pos->y += next_y.y;
	}
}


t_position	ray_cast(const t_position *p, const float angle, const t_cub *cub)
{
	const t_position	dir = {cosf(angle), sinf(angle)};
	t_position			ray;
	char				c;
	int					i;
	int j;


	ray = *p;
	c = get_map_char2(cub, &ray, p);
	i = 0;
	if (c == 'p')
	{
		int	x;
		int	y;

		if (p->x > ray.x)
			x = ceilf(ray.x - 1);
		else
			x = floorf(ray.x);
		if (p->y > ray.y)
			y = ceilf(ray.y - 1);
		else
			y = floorf(ray.y);
		for (j = 0; j < cub->nb_doors; j++)
		{
			t_position door_pos =  cub->doors[j].pos;
			if (door_pos.x == x && door_pos.y == y)
				break ;
		}
		next_d(&ray, &dir, cub->doors[j].percent_closed);
		c = get_map_char2(cub, &ray, p);
	}
	else if (c == 'P')
	{
		int	x;
		int	y;

		if (p->x > ray.x)
			x = ceilf(ray.x - 1);
		else
			x = floorf(ray.x);
		if (p->y > ray.y)
			y = ceilf(ray.y - 1);
		else
			y = floorf(ray.y);
		for (j = 0; j < cub->nb_doors; j++)
		{
			t_position door_pos =  cub->doors[j].pos;
			if (door_pos.x == x && door_pos.y == y)
				break ;
		}
		next_d2(&ray, &dir, cub->doors[j].percent_closed);
		c = get_map_char2(cub, &ray, p);
	}
	while (i++ < 100 && ft_isset_tab(c, "0!`@$"))
	{
		next(&ray, &dir);
		c = get_map_char2(cub, &ray, p);
		if (c == 'p')
		{
			int	x;
			int	y;

			if (p->x > ray.x)
				x = ceilf(ray.x - 1);
			else
				x = floorf(ray.x);
			if (p->y > ray.y)
				y = ceilf(ray.y - 1);
			else
				y = floorf(ray.y);
			for (j = 0; j < cub->nb_doors; j++)
			{
				t_position door_pos =  cub->doors[j].pos;
				//if (cub->doors[j].closed)
				//{
				//	cub->doors[j].percent_closed -= 0.00001;
				//	if (cub->doors[j].percent_closed <= 0)
				//	{
				//		cub->doors[j].percent_closed = 0;
				//		cub->doors[j].closed = false;
				//	}
				//}
				//else
				//{
				//	cub->doors[j].percent_closed += 0.00001;
				//	if (cub->doors[j].percent_closed >= 1)
				//	{
				//		cub->doors[j].percent_closed = 1;
				//		cub->doors[j].closed = true;
				//	}
				//}
				if (door_pos.x == x && door_pos.y == y)
					break ;
			}
			next_d(&ray, &dir, cub->doors[j].percent_closed);
			c = get_map_char2(cub, &ray, p);
		}
		else if (c == 'P')
		{
			int	x;
			int	y;

			if (p->x > ray.x)
				x = ceilf(ray.x - 1);
			else
				x = floorf(ray.x);
			if (p->y > ray.y)
				y = ceilf(ray.y - 1);
			else
				y = floorf(ray.y);
			for (j = 0; j < cub->nb_doors; j++)
			{
				t_position door_pos =  cub->doors[j].pos;
				if (door_pos.x == x && door_pos.y == y)
					break ;
			}
			next_d2(&ray, &dir, cub->doors[j].percent_closed);
			c = get_map_char2(cub, &ray, p);
	}
	}
	return (ray);
}
