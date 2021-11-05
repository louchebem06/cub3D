/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 18:24:31 by mmehran           #+#    #+#             */
/*   Updated: 2021/11/05 15:48:56 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub_bonus.h"

static float	calc_res(float off_x, float off_y, const t_position *pos_player,
							const t_position *ray_pos)
{
	float	res;

	if (off_x > off_y)
	{
		res = off_x;
		if (pos_player->y < ray_pos->y)
			res = 1 - res;
	}
	else
	{
		res = off_y;
		if (pos_player->x > ray_pos->x)
			res = 1 - res;
	}
	return (res);
}

int	calc_x_y(float a, float b)
{
	if (a > b)
		return (ceilf(b - 1));
	else
		return (floorf(b));
}

float	img_x_percent(const t_cub *cub, const t_position *ray_pos)
{
	const float	off_x = ray_pos->x - floorf(ray_pos->x);
	const float	off_y = ray_pos->y - floorf(ray_pos->y);
	int			x;
	int			y;
	int			i;

	x = calc_x_y(cub->player.pos.x, ray_pos->x);
	y = calc_x_y(cub->player.pos.y, ray_pos->y);
	i = -1;
	if (get_map_char2(cub, ray_pos, &cub->player.pos) == 'p')
	{
		while (++i < cub->nb_doors)
			if (cub->doors[i].pos.x == x && cub->doors[i].pos.y == y)
				return (1 - cub->doors[i].percent_closed + off_y);
	}
	else if (get_map_char2(cub, ray_pos, &cub->player.pos) == 'P')
	{
		while (++i < cub->nb_doors)
			if (cub->doors[i].pos.x == x && cub->doors[i].pos.y == y)
				return (1 - cub->doors[i].percent_closed + off_x);
	}
	return (calc_res(off_x, off_y, &cub->player.pos, ray_pos));
}

float	ceiling_x_percent(const t_cub *cub, int x)
{
	const float	p_x = (float) x / cub->screen.width;
	const float	p_a = cub->player.angle / (2 * M_PI);
	const float	res = (p_a + p_x * 0.25);

	return (res - floorf(res));
}
