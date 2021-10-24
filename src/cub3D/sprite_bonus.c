/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 23:59:13 by bledda            #+#    #+#             */
/*   Updated: 2021/10/25 01:15:27 by bledda           ###   ########.fr       */
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

static float ft_dot(t_position a, t_position b)
{
	return (a.x * b.x + a.y * b.y);
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
	float diff_angle = fmaxf(s_angle, p_angle) - fminf(s_angle, p_angle);
	float dot = (dir.x * dsprite.x + dir.y * dsprite.y) / dist;
	float cam_dist = dist * cosf(s_angle + M_PI / 2);
	t_position udsprite =  {dsprite.x / dist, dsprite.y / dist};
	t_position plane = {dir.x * cosf(M_PI / 2) - dir.y * sinf(M_PI / 2),
						dir.x * sinf(M_PI / 2) + dir.y * cosf(M_PI / 2)};

	printf("dist : %f\n", dist);
	printf("dir X : %f\ndir Y : %f\n", dir.x, dir.y);
	printf("Sprite angle : %f\n", s_angle);
	printf("Player angle : %f\n", p_angle);
	printf("Diff angle : %f\n", diff_angle);
	printf("Cam Dist : %f\n", cam_dist);
	printf("Dot : %f\n", dot);
	printf("SINF diff angle : %f\n", sinf(diff_angle));
	printf("TANF diff angle : %f\n", tanf(diff_angle));
	printf("PLANE X : %f\n", plane.x);
	printf("PLANE y : %f\n", plane.y);
	printf("dir X : %f\n", dir.x);
	printf("dir y : %f\n", dir.y);
	printf("\n");

	if (cosf(diff_angle) < 0)
		return ;
	//float x = WW / 2;
//	printf("%f\n%f\n", tanf(diff_angle) * dist, sinf());
	float W = WW / 2;
	float S = ft_dot(plane, udsprite);
	//float x = W - ((W * S) * ( tanf(diff_angle) * dist) );
	// float x = udsprite.x * cosf(-p_angle) - udsprite.y * sinf(-p_angle);
	//float x = ft_dot(plane, udsprite);
	printf("%f\n", S);
	float x = W + ((W * S));
	float y = WH / 2;
	put_img(&cub->screen, &cub->sprite.woman, (t_position){x, y},
				(1 / dist));
}
