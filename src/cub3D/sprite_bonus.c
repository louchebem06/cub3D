/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 23:59:13 by bledda            #+#    #+#             */
/*   Updated: 2021/10/30 20:35:58 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/sprite_bonus.h"

static void	put_img(t_img *dest, t_img *src, t_position center, float scale, float fill, float dist, t_cub *cub)
{
	float px,py;
	float y,x;
	unsigned int color;

	px = 0;
	py = 0;
	x = -1;
	if (scale * src->width > 2500)
		scale = 2500 / src->width ;
	while (++x < src->width)
	{
		y = -1;
		while (++y < src->height)
		{
			py += (scale / src->height);
			color = mlx_get_pixel_img(src, x, y);
			int xx = px * src->width + center.x - (src->width / 2) * scale;
			int yy = py * src->height - (src->height / 2) * scale + center.y;
			for (int i = 0; i <= ceilf(scale * fill); i++)
			{
				if (xx + i >= 0 && xx + i < 1280 && cub->z[xx + i] < dist)
					continue ;
				for (int j = 0; j <= ceilf(scale * fill); j++)
				{
					mlx_put_pixel_to_img(dest, xx + i, yy + j, color);
				}
			}
		}
		py = 0;
		px += (scale / src->width);
	}
}

static float	ft_dot(t_position a, t_position b)
{
	return (a.x * b.x + a.y * b.y);
}

static void	update_sprites_dist(t_position *p, t_item_sprite *config, int item)
{
	int	i;

	i = -1;
	while (++i < item)
	{
		config[i].dist = hypotf(p->x - config[i].pos.x,
				p->y - config[i].pos.y);
	}
}

static void	sort_sprite(t_item_sprite *config, int item)
{
	t_item_sprite	temp;
	int				i;
	int				j;

	j = -1;
	while (++j + 1 < item)
	{
		i = -1;
		while (++i + j + 1 < item)
		{
			if (config[i + 1].dist > config[i].dist)
			{
				temp = config[i + 1];
				config[i + 1] = config[i];
				config[i] = temp;
			}
		}
	}
}

void	sprite(t_cub *cub)
{
	static unsigned long long	time = 0;
	const unsigned long long	diff_time = ft_get_current_time() - time;
	static int img = 0;
	static bool move = false;

	update_sprites_dist(&cub->player.pos, cub->sprite.config, cub->sprite.item);
	sort_sprite(cub->sprite.config, cub->sprite.item);
	for (int i = 0; i < cub->sprite.item; i++)
	{
		t_player *p = &cub->player;
		t_position sprite_pos = cub->sprite.config[i].pos;
		t_position dsprite =  {sprite_pos.x - p->pos.x, sprite_pos.y - p->pos.y};
		float dist = hypotf(dsprite.x, dsprite.y);
		t_position dir =  {cosf(cub->player.angle), sinf(cub->player.angle)};
		float dot = (dir.x * dsprite.x + dir.y * dsprite.y) / dist;

		float s_angle = atan2f(dsprite.y, dsprite.x);
		float p_angle = p->angle;
		float diff_angle = s_angle + 2 * M_PI - p_angle;
		t_position udsprite =  {dsprite.x / dist, dsprite.y / dist};

		float toast_p = (0.6 * tanf(diff_angle)) + 0.5;

		if (dot <= 0)
			continue ;
		if (toast_p <= -0.1 || toast_p >= 1.1)
			continue ;
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
		float scale = ((WW / 1.69f) / s->width);
		float mdr = scale / (dist * ft_dot(dir, udsprite));
		float tt = (dist) / 10;
		put_img(&cub->screen, s, (t_position){(WW) * toast_p, (WH / 2) - (mdr * s->height) / 2 + (WH / 2) / (dist * ft_dot(dir, udsprite)) },
					scale / (dist * ft_dot(dir, udsprite)), (cub->sprite.config[i].c == 'P') ? fminf(tt, 1) : 1, dist, cub);
	}
}
