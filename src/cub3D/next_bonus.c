/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:51:52 by bledda            #+#    #+#             */
/*   Updated: 2021/11/05 16:03:35 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub_bonus.h"

static float	left_right(const float number, const bool direction)
{
	if (direction)
		return (floorf(number + 1) - number);
	return (ceilf(number - 1) - number);
}

void	next(t_position *pos, const t_position *direction)
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

void	next_d(t_position *pos, const t_position *dir, float percent)
{
	const float			dx = left_right(pos->x * 2, dir->x > 0) / 2;
	const float			dy = left_right(pos->y, dir->y > 0);
	const float			slope = dir->y / dir->x;
	const t_position	next_x = {dx, dx * slope};
	const t_position	next_y = {dy / slope, dy};

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

void	next_d2(t_position *pos, const t_position *dir, float percent)
{
	const float			dx = left_right(pos->x, dir->x > 0);
	const float			dy = left_right(pos->y * 2, dir->y > 0) / 2;
	const float			slope = dir->y / dir->x;
	const t_position	next_x = {dx, dx * slope};
	const t_position	next_y = {dy / slope, dy};

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
