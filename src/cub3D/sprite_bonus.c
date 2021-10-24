/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 23:59:13 by bledda            #+#    #+#             */
/*   Updated: 2021/10/24 22:54:50 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/sprite_bonus.h"

static void	put_img(t_img *dest, t_img *src, t_position center, float scale)
{
	float px,py;
	float y,x;

	px = 0;
	py = 0;
	y = 0;
	while (y < src->height)
	{
		x = 0;
		while (x < src->width)
		{
			px = (x / src->width) * scale;
			unsigned int color = mlx_get_pixel_img(src, x, y);
			for (int i = 0; i <= ceilf(scale); i++)
				for (int j = 0; j <= ceilf(scale); j++)
					mlx_put_pixel_to_img(dest, px * src->width + center.x - (src->width / 2) * scale + i, py * src->height - (src->height / 2) * scale + center.y + j, color);
			x++;
		}
		y++;
		py = (y / src->height) * scale;
	}
}

void	sprite(t_cub *cub)
{
	t_player *p = &cub->player;
	t_position sprite_pos = {4.5, 4.5};
	t_position dsprite =  {sprite_pos.x - p->pos.x, sprite_pos.y - p->pos.y};
	float dist = hypotf(dsprite.x, dsprite.y);
	t_position dir =  {cosf(cub->player.angle), sinf(cub->player.angle)};
	float s_angle = atan2f(dsprite.y, dsprite.x);
	float p_angle = p->angle;
	float diff_angle = s_angle - p_angle;
	if (cosf(diff_angle) < 0)
		return ;
	put_img(&cub->screen, &cub->sprite.doll, (t_position){WW / 2, WH / 2}, 2);
}
