/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 18:24:31 by mmehran           #+#    #+#             */
/*   Updated: 2021/11/05 14:02:43 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub_bonus.h"

float	img_x_percent(const t_cub *cub, const t_position *ray_pos)
{
	const float	off_x = ray_pos->x - floorf(ray_pos->x);
	const float	off_y = ray_pos->y - floorf(ray_pos->y);
	float		res;


	if (get_map_char2(cub, ray_pos, &cub->player.pos) == 'p')
	{
			int	x;
			int	y;

			if (cub->player.pos.x > ray_pos->x)
				x = ceilf( ray_pos->x - 1);
			else
				x = floorf(ray_pos->x);
			if (cub->player.pos.y > ray_pos->y)
				y = ceilf(ray_pos->y- 1);
			else
				y = floorf(ray_pos->y);
			for (int i = 0; i < cub->nb_doors; i++)
			{
				t_position door_pos =  cub->doors[i].pos;
				if (door_pos.x == x && door_pos.y == y)
					return (1 - cub->doors[i].percent_closed + off_y);
			}
	} else if (get_map_char2(cub, ray_pos, &cub->player.pos) == 'P')
	{
			int	x;
			int	y;

			if (cub->player.pos.x > ray_pos->x)
				x = ceilf( ray_pos->x - 1);
			else
				x = floorf(ray_pos->x);
			if (cub->player.pos.y > ray_pos->y)
				y = ceilf(ray_pos->y- 1);
			else
				y = floorf(ray_pos->y);
			for (int i = 0; i < cub->nb_doors; i++)
			{
				t_position door_pos =  cub->doors[i].pos;
				if (door_pos.x == x && door_pos.y == y)
					return (1 - cub->doors[i].percent_closed + off_x);
			}
	}
	if (off_x > off_y)
	{
		res = off_x;
		if (cub->player.pos.y < ray_pos->y)
			res = 1 - res;
	}
	else
	{
		res = off_y;
		if (cub->player.pos.x > ray_pos->x)
			res = 1 - res;
	}
	return (res);
}

float	ceiling_x_percent(const t_cub *cub, int x)
{
	const float	p_x = (float) x / cub->screen.width;
	const float	p_a = cub->player.angle / (2 * M_PI);
	const float	res = (p_a + p_x * 0.25);

	return (res - floorf(res));
}
