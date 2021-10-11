/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 00:23:37 by mmehran           #+#    #+#             */
/*   Updated: 2021/10/12 01:39:24 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

static t_img	*get_texture_direction(t_cub *cub, const t_position *ray_pos)
{
	const float	off_x = ray_pos->x - floorf(ray_pos->x);
	const float	off_y = ray_pos->y - floorf(ray_pos->y);

	if (off_x > off_y)
	{
		if (cub->player.pos.y > ray_pos->y)
			return (&cub->texture.so);
		return (&cub->texture.no);
	}
	else
	{
		if (cub->player.pos.x > ray_pos->x)
			return (&cub->texture.ea);
		return (&cub->texture.we);
	}
	return (0);
}

static void	draw_col(t_cub *cub, int x, int size, const t_position *ray_pos)
{
	const int		am = (cub->screen.height - size) / 2;
	const t_img		*texture = get_texture_direction(cub, ray_pos);
	float			xx;
	unsigned int	color;
	int				y;

	y = -1;
	if (ray_pos->x - floorf(ray_pos->x) > ray_pos->y - floorf(ray_pos->y))
	{
		xx = ray_pos->x - floorf(ray_pos->x);
		if (cub->player.pos.y < ray_pos->y)
			xx = 1 - xx;
	}
	else
	{
		xx = ray_pos->y - floorf(ray_pos->y);
		if (cub->player.pos.x > ray_pos->x)
			xx = 1 - xx;
	}
	xx *= texture->width;
	while (++y < cub->screen.height)
	{
		color = anti_rgb(cub->config.floor);
		if (y < am)
			color = anti_rgb(cub->config.ceiling);
		else if (y < am + size)
			color = mlx_get_pixel_img(texture, xx,
					texture->height * (y - am) / size);
		mlx_put_pixel_to_img(&cub->screen, x, y, color);
	}
}

void	draw(t_cub *cub)
{
	float		size;
	t_position	ray;
	t_position	cray;
	int			x;
	float		angle;

	size = 0;
	x = -1;
	while (++x < cub->screen.width)
	{
		angle = atan2f((float) x / cub->screen.width - 0.5, 0.6);
		ray = ray_cast(&cub->player, cub->player.angle + angle, &cub->map);
		cray = ray;
		cray.x -= cub->player.pos.x;
		cray.y -= cub->player.pos.y;
		size = hypotf(cray.x, cray.y);
		size *= cosf(angle);
		if (size == 0)
			size = 1;
		draw_col(cub, x, cub->screen.height / size, &ray);
	}
}
