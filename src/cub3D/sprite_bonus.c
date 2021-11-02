/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 23:59:13 by bledda            #+#    #+#             */
/*   Updated: 2021/11/02 17:22:53 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/sprite_bonus.h"
#include <pthread.h>

static void	fill(t_draw_sprite_thread *thread)
{
	thread->i = -1;
	while (++thread->i <= ceilf(thread->value.scale))
	{
		if (thread->xx + thread->i >= 0
			&& thread->xx + thread->i < 1280
			&& thread->cub->z[thread->xx + thread->i] < thread->value.dist)
			continue ;
		thread->j = -1;
		while (++thread->j <= ceilf(thread->value.scale))
			mlx_put_pixel_to_img(&thread->cub->screen,
				thread->xx + thread->i, thread->yy + thread->j,
				thread->color);
	}
}

static inline int	calc_xx(const t_draw_sprite_thread *thread)
{
	return (thread->px
		* thread->src->width
		+ thread->value.center.x
		- (thread->src->width / 2)
		* thread->value.scale);
}

static inline int	calc_yy(const t_draw_sprite_thread *thread)
{
	return (thread->py
		* thread->src->height
		- (thread->src->height / 2)
		* thread->value.scale
		+ thread->value.center.y);
}


static void	*put_img_multithread(void *curr_thread)
{
	t_draw_sprite_thread *const	thread = (t_draw_sprite_thread *)curr_thread;
	const int					pixel = thread->src->width / thread->nb_thread;

	thread->x = pixel * thread->id_thread;
	while (++thread->x < pixel * thread->id_thread + pixel)
	{
		thread->y = -1;
		while (++thread->y < thread->src->height)
		{
			thread->py += (thread->value.scale / thread->src->height);
			thread->color = \
				mlx_get_pixel_img(thread->src, thread->x, thread->y);
			thread->xx = calc_xx(thread);
			thread->yy = calc_yy(thread);
			thread->i = -1;
			fill(thread);
		}
		thread->py = 0;
		thread->px += (thread->value.scale / thread->src->width);
	}
	pthread_exit(0);
}

#define THREAD_SPRITE 1

static void	put_img(t_cub *cub, t_img *src, t_draw_sprite value)
{
	t_draw_sprite_thread	t[THREAD_SPRITE];
	pthread_t				thread[THREAD_SPRITE];
	int						i;

	if (value.scale * src->width > 2500)
		value.scale = 2500 / src->width;
	i = -1;
	while (++i < THREAD_SPRITE)
	{
		t[i] = (t_draw_sprite_thread){0};
		t[i].cub = cub;
		t[i].id_thread = i;
		t[i].nb_thread = THREAD_SPRITE;
		t[i].src = src;
		t[i].value = value;
		pthread_create(&thread[i], NULL, put_img_multithread, &t[i]);
	}
	i = -1;
	while (++i < THREAD_SPRITE)
		pthread_join(thread[i], NULL);
}

static bool	calc_value(t_cub *cub, t_calc_sprite *var)
{
	var->p = &cub->player;
	var->sprite_pos = cub->sprite.config[var->i].pos;
	var->dsprite = (t_position){
		var->sprite_pos.x - var->p->pos.x, var->sprite_pos.y - var->p->pos.y};
	var->dist = hypotf(var->dsprite.x, var->dsprite.y);
	var->dir = (t_position){
		cosf(cub->player.angle), sinf(cub->player.angle)};
	var->dot = \
		(var->dir.x * var->dsprite.x + var->dir.y * var->dsprite.y) / var->dist;
	var->s_angle = atan2f(var->dsprite.y, var->dsprite.x);
	var->p_angle = var->p->angle;
	var->diff_angle = var->s_angle + 2 * M_PI - var->p_angle;
	var->udsprite = (t_position){
		var->dsprite.x / var->dist, var->dsprite.y / var->dist};
	var->toast_p = (0.6 * tanf(var->diff_angle)) + 0.5;
	if (var->dot <= 0)
		return (true);
	if (var->toast_p <= -0.1 || var->toast_p >= 1.1)
		return (true);
	return (false);
}

static void	anim_doll(unsigned long long *time,
							const unsigned long long diff_time,
							int *img, bool *move)
{
	if (!*time
		|| (*img == 5 && diff_time > 1000)
		|| (*img != 5 && diff_time > 150))
	{
		*time = ft_get_current_time();
		if (!*move)
			*img += 2;
		if (--*img == 0)
			*move = false;
		else if (*img == 5)
			*move = true;
	}
}

static inline float	calc_scale(const t_calc_sprite var)
{
	return (((WW / 1.69f) / var.s->width)
		/ (var.dist * ft_dot(var.dir, var.udsprite)));
}

static inline t_position	calc_center(const t_calc_sprite var)
{
	return ((t_position){
		(WW) * var.toast_p,
		(WH / 2) - (var.send.scale * var.s->height) / 2
		+ (WH / 2) / (var.dist * ft_dot(var.dir, var.udsprite))});
}

void	sprite(t_cub *cub)
{
	static unsigned long long	time = 0;
	const unsigned long long	diff_time = ft_get_current_time() - time;
	static int					img = 0;
	static bool					move = false;
	t_calc_sprite				var;

	update_sprites_dist(&cub->player.pos, cub->sprite.config, cub->sprite.item);
	sort_sprite(cub->sprite.config, cub->sprite.item);
	var = (t_calc_sprite){0};
	var.i = -1;
	while (++var.i < cub->sprite.item)
	{
		if (calc_value(cub, &var))
			continue ;
		var.s = cub->sprite.config[var.i].s;
		if (!var.s)
		{
			anim_doll(&time, diff_time, &img, &move);
			var.s = cub->sprite.config[var.i].s_anim[img];
		}
		var.send.scale = calc_scale(var);
		var.send.center = calc_center(var);
		var.send.dist = var.dist;
		put_img(cub, var.s, var.send);
	}
}

// ORIGINAL PUT_IMG FT

// static void	put_img(t_img *dest, t_img *src, t_position center, float scale, float fill, float dist, t_cub *cub)
// {
// 	float px,py;
// 	float y,x;
// 	unsigned int color;

// 	px = 0;
// 	py = 0;
// 	x = -1;
// 	if (scale * src->width > 2500)
// 		scale = 2500 / src->width ;
// 	while (++x < src->width)
// 	{
// 		y = -1;
// 		while (++y < src->height)
// 		{
// 			py += (scale / src->height);
// 			color = mlx_get_pixel_img(src, x, y);
// 			int xx = px * src->width + center.x - (src->width / 2) * scale;
// 			int yy = py * src->height - (src->height / 2) * scale + center.y;
// 			for (int i = 0; i <= ceilf(scale * fill); i++)
// 			{
// 				if (xx + i >= 0 && xx + i < 1280 && cub->z[xx + i] < dist)
// 					continue ;
// 				for (int j = 0; j <= ceilf(scale * fill); j++)
// 				{
// 					mlx_put_pixel_to_img(dest, xx + i, yy + j, color);
// 				}
// 			}
// 		}
// 		py = 0;
// 		px += (scale / src->width);
// 	}
// }

// ORIGINAL SPRITE FT

// void	sprite(t_cub *cub)
// {
// 	static unsigned long long	time = 0;
// 	const unsigned long long	diff_time = ft_get_current_time() - time;
// 	static int img = 0;
// 	static bool move = false;

// 	update_sprites_dist(&cub->player.pos, cub->sprite.config, cub->sprite.item);
// 	sort_sprite(cub->sprite.config, cub->sprite.item);
// 	for (int i = 0; i < cub->sprite.item; i++)
// 	{
// 		t_player *p = &cub->player;
// 		t_position sprite_pos = cub->sprite.config[i].pos;
// 		t_position dsprite =  {sprite_pos.x - p->pos.x, sprite_pos.y - p->pos.y};
// 		float dist = hypotf(dsprite.x, dsprite.y);
// 		t_position dir =  {cosf(cub->player.angle), sinf(cub->player.angle)};
// 		float dot = (dir.x * dsprite.x + dir.y * dsprite.y) / dist;

// 		float s_angle = atan2f(dsprite.y, dsprite.x);
// 		float p_angle = p->angle;
// 		float diff_angle = s_angle + 2 * M_PI - p_angle;
// 		t_position udsprite =  {dsprite.x / dist, dsprite.y / dist};

// 		float toast_p = (0.6 * tanf(diff_angle)) + 0.5;

// 		if (dot <= 0)
// 			continue ;
// 		if (toast_p <= -0.1 || toast_p >= 1.1)
// 			continue ;
// 		t_img *s = cub->sprite.config[i].s;
// 		if (!s)
// 		{
// 			if (!time || (img == 5 && diff_time > 1000) || (img != 5 && diff_time > 150))
// 			{
// 				time = ft_get_current_time();
// 				if (!move)
// 					img += 2;
// 				if (--img == 0)
// 					move = false;
// 				else if (img == 5)
// 					move = true;
// 			}
// 			s = cub->sprite.config[i].s_anim[img];
// 		}
// 		float scale = ((WW / 1.69f) / s->width);
// 		float mdr = scale / (dist * ft_dot(dir, udsprite));
// 		float tt = (dist) / 10;
// 		put_img(&cub->screen, s, (t_position){(WW) * toast_p, (WH / 2) - (mdr * s->height) / 2 + (WH / 2) / (dist * ft_dot(dir, udsprite)) },
// 					scale / (dist * ft_dot(dir, udsprite)), (cub->sprite.config[i].c == 'P') ? fminf(tt, 1) : 1, dist, cub);
	
// 	}
// }
