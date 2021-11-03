/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_sprite_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 17:31:34 by bledda            #+#    #+#             */
/*   Updated: 2021/11/03 17:40:50 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/sprite_bonus.h"
#include <pthread.h>

#define THREAD_SPRITE 4

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

static void	*put_sprite_multithread(void *curr_thread)
{
	t_draw_sprite_thread *const	thread = (t_draw_sprite_thread *)curr_thread;
	const int					pixel = thread->src->width / thread->nb_thread;

	thread->x = pixel * thread->id_thread;
	while (++thread->x <= pixel * thread->id_thread + pixel)
	{
		thread->y = -1;
		while (++thread->y < thread->src->height)
		{
			thread->py += (thread->value.scale / thread->src->height);
			thread->color = \
				mlx_get_pixel_img(thread->src, thread->x, thread->y);
			if (thread->color == 0)
				continue ;
			thread->xx = calc_xx(thread)
				+ (pixel * thread->id_thread) * thread->value.scale;
			thread->yy = calc_yy(thread);
			thread->i = -1;
			fill(thread);
		}
		thread->py = 0;
		thread->px += (thread->value.scale / thread->src->width);
	}
	pthread_exit(0);
}

void	put_sprite(t_cub *cub, t_img *src, t_draw_sprite value)
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
		pthread_create(&thread[i], NULL, put_sprite_multithread, &t[i]);
	}
	i = -1;
	while (++i < THREAD_SPRITE)
		pthread_join(thread[i], NULL);
}
