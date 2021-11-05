/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 00:23:37 by mmehran           #+#    #+#             */
/*   Updated: 2021/11/05 12:16:14 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub_bonus.h"
#include <pthread.h>

static unsigned int	get_fc(t_cub *cub, int y, const t_position *dir, bool floor)
{
	int			yy;
	t_position	lol;
	t_img		*texture;
	float		d;

	if (floor)
		yy = y - (cub->screen.height / 2);
	else
		yy = (cub->screen.height / 2) - y;
	d = ((cub->screen.height / 2.0f) / yy);
	lol = cub->player.pos;
	lol.x += d * dir->x;
	lol.y += d * dir->y;
	texture = get_fc_texture(cub, &lol, floor);
	if (!texture)
	{
		if (floor)
			return (anti_rgb(cub->config.floor));
		return (anti_rgb(cub->config.ceiling));
	}
	return (mlx_get_pixel_img(texture, (lol.x - floorf(lol.x)) * texture->width,
			(lol.y - floorf(lol.y)) * texture->height));
}

static unsigned int	get_ceiling(t_cub *cub, int x, int y, const t_position *dir)
{
	t_img	*ceiling;

	if (ft_isset_tab(get_map_char(
				&cub->map, &cub->player.pos, &cub->player.pos), "!`$"))
	{
		ceiling = get_fc_texture(cub, &cub->player.pos, false);
		if (!ceiling)
			return (0);
		return (mlx_get_pixel_img(ceiling,
				ceiling_x_percent(cub, x) * ceiling->width,
				(float) ceiling->height * y / (cub->screen.height / 2)));
	}
	else
		return (get_fc(cub, y, dir, false));
}

static void	draw_col(t_cub *cub, int x,
		const t_position *ray_pos, t_position junk)
{
	const int			am = (cub->screen.height - junk.x) / 2;
	const t_img			*texture = get_wall_texture(cub, ray_pos);
	unsigned int		color;
	int					y;
	const t_position	dir = {cosf(cub->player.angle + junk.y) / cosf(junk.y),
							sinf(cub->player.angle + junk.y) / cosf(junk.y)};

	y = -1;
	color = 0;
	while (++y < cub->screen.height)
	{
		if (y < am)
			color = get_ceiling(cub, x, y, &dir);
		else if (texture && y < am + junk.x)
			color = mlx_get_pixel_img(texture, img_x_percent(cub, ray_pos)
					* texture->width, texture->height * (y - am) / junk.x);
		else
			color = get_fc(cub, y, &dir, true);
		mlx_put_pixel_to_img(&cub->screen, x, y, color);
	}
}

static void	*draw_multithread(void *curr_thread)
{
	t_thread_draw	*thread;
	int				x;

	thread = (t_thread_draw *)curr_thread;
	x = thread->x_start - 1;
	while (++x <= thread->x_end)
	{
		thread->angle = atan2f(
				(float) x / thread->cub->screen.width - 0.5, 0.6);
		thread->ray = ray_cast(&thread->cub->player.pos,
				thread->cub->player.angle + thread->angle, thread->cub);
		thread->cray = thread->ray;
		thread->cray.x -= thread->cub->player.pos.x;
		thread->cray.y -= thread->cub->player.pos.y;
		thread->size = hypotf(thread->cray.x, thread->cray.y);
		thread->cub->z[x] = thread->size;
		thread->size *= cosf(thread->angle);
		if (thread->size == 0)
			thread->size = 1;
		draw_col(thread->cub, x, &thread->ray, (t_position)
		{thread->cub->screen.height / thread->size, thread->angle});
	}
	pthread_exit(0);
}

void	draw(t_cub *cub)
{
	t_thread_draw	t[4];
	pthread_t		thread[4];
	int				i;

	t[0].x_start = 0;
	t[0].x_end = 319;
	t[1].x_start = 320;
	t[1].x_end = 639;
	t[2].x_start = 640;
	t[2].x_end = 959;
	t[3].x_start = 960;
	t[3].x_end = 1279;
	i = -1;
	while (++i < 4)
	{
		t[i].cub = cub;
		pthread_create(&thread[i], NULL, draw_multithread, &t[i]);
	}
	i = -1;
	while (++i < 4)
		pthread_join(thread[i], NULL);
}
