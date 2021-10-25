/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 23:59:13 by bledda            #+#    #+#             */
/*   Updated: 2021/10/25 05:19:34 by bledda           ###   ########.fr       */
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
	if (scale * src->width > 2500)
		scale = 2500 / src->width ;
	while (y < src->height)
	{
		x = 0;
		if (py > WH)
			continue ;
		while (x < src->width)
		{
			px = (x / src->width) * scale;
			if (px > WW)
				continue ;
			unsigned int color = mlx_get_pixel_img(src, x, y);
			for (int i = 0; i <= ceilf(scale); i++)
				for (int j = 0; j <= ceilf(scale); j++)
				{
					int xx = px * src->width + center.x - (src->width / 2) * scale + i;
					int yy = py * src->height - (src->height / 2) * scale + center.y + j;
					if (xx > WW || yy > WH)
						continue;
					mlx_put_pixel_to_img(dest, xx, yy, color);
				}
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

static float moyen(t_position point)
{
	return (point.x + point.y / 2);
}

void	sprite(t_cub *cub)
{
	static unsigned long long	time = 0;
	const unsigned long long	diff_time = ft_get_current_time() - time;
	static int img = 0;
	static bool move = false;

	for (int i = 0; i < cub->sprite.item; i++)
	{
		t_player *p = &cub->player;
		t_position sprite_pos = cub->sprite.config[i].pos;
		t_position dsprite =  {sprite_pos.x - p->pos.x, sprite_pos.y - p->pos.y};
		float dist = hypotf(dsprite.x, dsprite.y);
		t_position dir =  {cosf(cub->player.angle), sinf(cub->player.angle)};
		float dot = (dir.x * dsprite.x + dir.y * dsprite.y) / dist;
		
		if (dot < 0.5)
			continue ;

		float s_angle = atan2f(dsprite.y, dsprite.x);
		float p_angle = p->angle;
		float diff_angle = fmaxf(s_angle, p_angle) - fminf(s_angle, p_angle);
		//float cam_dist = dist * cosf(s_angle + M_PI / 2);
		t_position udsprite =  {dsprite.x / dist, dsprite.y / dist};
		t_position plane = {dir.x * cosf(M_PI / 2) - dir.y * sinf(M_PI / 2),
							dir.x * sinf(M_PI / 2) + dir.y * cosf(M_PI / 2)};

		// printf("dist : %f\n", dist);
		// printf("dir X : %f\ndir Y : %f\n", dir.x, dir.y);
		// printf("Sprite angle : %f\n", s_angle);
		// printf("Player angle : %f\n", p_angle);
		// printf("Diff angle : %f\n", diff_angle);
		// printf("Cam Dist : %f\n", cam_dist);
		// printf("Dot : %f\n", dot);
		// printf("SINF diff angle : %f\n", sinf(diff_angle));
		// printf("TANF diff angle : %f\n", tanf(diff_angle));
		// printf("PLANE X : %f\n", plane.x);
		// printf("PLANE y : %f\n", plane.y);
		// printf("dir X : %f\n", dir.x);
		// printf("dir y : %f\n", dir.y);
		// printf("\n");


		double invDet = 1.0 / (plane.x * dir.y - dir.y * plane.y); //required for correct matrix multiplication

		double transformX = invDet * (dir.y * dsprite.x - dir.x * dsprite.y);
		double transformY = invDet * (-plane.y * dsprite.x + plane.x * dsprite.y); //this is actually the depth inside the screen, that what Z is in 3D

		int spriteScreenX = (int)((WW / 2) * (1 + transformX / transformY));

		if (cosf(diff_angle) < 0.1)
			continue ;
		//float x = WW / 2;
	//	printf("%f\n%f\n", tanf(diff_angle) * dist, sinf());
		//float W = WW / 2;
		//float S = ft_dot(plane, udsprite);
		//float x = W - ((W * S) * ( tanf(diff_angle) * dist) );
		// float x = udsprite.x * cosf(-p_angle) - udsprite.y * sinf(-p_angle);
		//float x = ft_dot(plane, udsprite);
		//printf("%f\n", S);
		//float x = W + ((W * S));
		//float y = WH / 2;
		t_img *s = cub->sprite.config[i].s;
		if (!s)
		{
			if (!time || (img == 5 && diff_time > 1000) || (img != 5 && diff_time > 150))
			{
				time = ft_get_current_time();
				if (!move)
					img += 2;
				if (--img == 0)
					move = false;
				else if (img == 5)
					move = true;
			}
			s = cub->sprite.config[i].s_anim[img];
		}
		float scal = ((WW / 2.0f) / s->width);
		//int sh = (int)((WH / transformY)*scal);
		//int spriteScreenY = (int)((WH - sh) / 2);
		int y = WH / 2;
		put_img(&cub->screen, s, (t_position){spriteScreenX, y},
					(scal / (dist * ft_dot(dir, udsprite))));
	}
}
