/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 00:23:37 by mmehran           #+#    #+#             */
/*   Updated: 2021/10/23 01:26:30 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"
#include "../../header/cub_bonus.h"

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

static float	img_x_percent(const t_cub *cub, const t_position *ray_pos)
{
	const float	off_x = ray_pos->x - floorf(ray_pos->x);
	const float	off_y = ray_pos->y - floorf(ray_pos->y);
	float		res;

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

//static void	draw_col(t_cub *cub, int x, int size, const t_position *ray_pos)
//{
//	const int		am = (cub->screen.height - size) / 2;
//	const t_img		*texture = get_texture_direction(cub, ray_pos);
//	const int		xx = img_x_percent(cub, ray_pos) * texture->width;
//	unsigned int	color;
//	int				y;

//	y = -1;
//	while (++y < cub->screen.height)
//	{
//		color = anti_rgb(cub->config.floor);
//		if (y < am)
//			color = anti_rgb(cub->config.ceiling);
//		else if (y < am + size)
//			color = mlx_get_pixel_img(texture, xx,
//					texture->height * (y - am) / size);
//		mlx_put_pixel_to_img(&cub->screen, x, y, color);
//	}
//}

static t_img	*blabla(t_cub *cub, const t_position *ray_pos)
{
	const char	c = get_map_char(&cub->map, ray_pos, &cub->player.pos);

	if (c == '2')
		return (&cub->texture.two);
	if (c == '3')
		return (&cub->texture.three);
	if (c == '4')
		return (&cub->texture.four);
	if (c == '5')
		return (&cub->texture.five);
	if (c == '6')
		return (&cub->texture.six);
	if (c == '7')
		return (&cub->texture.seven);
	if (c == '8')
		return (&cub->texture.eight);
	if (c == '9')
		return (&cub->texture.nine);
	if (c == ']')
		return (&cub->texture.beton);
	return (0);
}

static t_img	*blabla2(t_cub *cub, const t_position *ray_pos, bool floor)
{
	const char	c = get_map_char(&cub->map, ray_pos, &cub->player.pos);

	if (c == '!')
	{
		if (floor)
			return (&cub->texture.floor);
		return (&cub->texture.ceiling);
	}
	else if (c == '`')
	{
		if (floor)
			return (&cub->texture.redline);
		return (&cub->texture.ceiling);
	}
	else if (c == '@')
		return (&cub->texture.bet);
	else if (c == '$')
	{
		if (floor)
			return (&cub->texture.bet);
		return (&cub->texture.stairs);
	}
	return (&cub->texture.bet);
}

static float	ceiling_x_percent(t_cub *cub, int x)
{
	const float	p_x = (float) x / cub->screen.width;
	const float	p_a = cub->player.angle / (2 * M_PI);
	const float	res = (p_a + p_x * 0.25);

	return (res - floorf(res));
}

static void	draw_col_mdr(t_cub *cub, int x, int size, const t_position *ray_pos, float angle)
{
	const int		am = (cub->screen.height - size) / 2;
	const t_img		*testure = blabla(cub, ray_pos);
	const t_img		*texture = testure ? testure : get_texture_direction(cub, ray_pos);
	const int		xx = img_x_percent(cub, ray_pos) * texture->width;
	unsigned int	color;
	int				y;


	const float cos_a = cosf(angle), cos_r = cosf(cub->player.angle + angle) / cos_a, sin_r = sinf(cub->player.angle + angle) / cos_a;
	y = -1;
	while (++y < cub->screen.height)
	{
		color = 0;
		if (y < am)
		{
			if (get_map_char(&cub->map, &cub->player.pos, &cub->player.pos) != '@')
			{
				t_img *ceiling = blabla2(cub, &cub->player.pos, false);
				color = mlx_get_pixel_img(ceiling, ceiling_x_percent(cub, x) * ceiling->width,
						(float) ceiling->height * y / (cub->screen.height / 2));
			}
			else
			{
				t_position lol = cub->player.pos;
				const int yy = (cub->screen.height / 2) - y;
				const float D = ((cub->screen.height / 2.0f) / yy);
				lol.x += D * cos_r;
				lol.y += D * sin_r;
				t_img *ceiling = blabla2(cub, &lol, false);
				color = mlx_get_pixel_img(ceiling, (lol.x - floorf(lol.x)) * ceiling->width,
						(lol.y - floorf(lol.y)) * ceiling->height);
			}
		}
		else if (y < am + size)
			color = mlx_get_pixel_img(texture, xx,
					texture->height * (y - am) / size);
		else
		{
			t_position lol = cub->player.pos;
			const int yy = y - (cub->screen.height / 2);
			const float D = ((cub->screen.height / 2.0f) / yy);
			lol.x += D * cos_r;
			lol.y += D * sin_r;
			t_img *floor = blabla2(cub, &lol, true);
			color = mlx_get_pixel_img(floor, (lol.x - floorf(lol.x)) * floor->width,
					(lol.y - floorf(lol.y)) * floor->height);
		}
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
		ray = ray_cast(&cub->player.pos, cub->player.angle + angle, &cub->map);
		cray = ray;
		cray.x -= cub->player.pos.x;
		cray.y -= cub->player.pos.y;
		size = hypotf(cray.x, cray.y);
		size *= cosf(angle);
		if (size == 0)
			size = 1;
		//if (get_map_char(&cub->map, &ray, &cub->player.pos) == '1')
		//	draw_col(cub, x, cub->screen.height / size, &ray);
		//else
		//	draw_col_lol(cub, x, cub->screen.height / size, &ray);
		draw_col_mdr(cub, x, cub->screen.height / size, &ray, angle);
	}
}
