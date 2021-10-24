/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 00:23:37 by mmehran           #+#    #+#             */
/*   Updated: 2021/10/24 05:24:23 by bledda           ###   ########.fr       */
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

float	fix_angle(float angle)
{
	bool	cont;

	cont = true;
	while (cont)
	{
		if (angle < 0)
			angle += 2 * M_PI;
		else if (angle >= 2 * M_PI)
			angle -= 2 * M_PI;
		else
			cont = false;
	}
	return (angle);
}

float	angle_diff(float a1, float a2)
{
	const float	diff = a1 - a2;

	return (fix_angle(diff));
}

static t_img	*get_sprite(t_cub *cub, const t_position *ray_pos)
{
	static int	i = -1;
	static bool	move = false;
	const char	c = get_map_char(&cub->map, ray_pos, &cub->player.pos);
	static unsigned long long time = 0;

	if (time == 0)
		time = ft_get_current_time();
	if (c == 'F')
		return (&cub->sprite.woman);
	else if (c == 'O')
		return (&cub->sprite.circle);
	else if (c == 'L')
		return (&cub->sprite.lit);
	else if (c == 'P')
		return (&cub->sprite.door);
	else if (c == 'I')
		return (&cub->sprite.intel);
	else if (c == 'H')
		return (&cub->sprite.man);
	else if (c == 'A')
		return (&cub->sprite.tree);
	else if (c == '|')
	{
		if ((i == 5 && ft_get_current_time()- time > 1000)
			|| (ft_get_current_time()- time > 150 && i != 5))
		{
			time = ft_get_current_time();
			if (!move)
				i++;
			else
				i--;
			if (i == 5)
				move = true;
			else if (i == 0)
				move = false;
		}
		return (&cub->sprite.doll[i]);
	}
	return (NULL);
}

void	draw(t_cub *cub)
{
	float		size;
	t_position	ray;
	t_position	cray;
	int			x;
	float		angle;
	unsigned int color;

	size = 0;
	x = -1;
	while (++x < cub->screen.width)
	{
		angle = atan2f((float) x / cub->screen.width - 0.5, 0.6);
		ray = ray_cast(&cub->player.pos, cub->player.angle + angle, &cub->map);
		cray = ray;
		cray.x -= cub->player.pos.x;
		cray.y -= cub->player.pos.y;
		size = hypotf(cray.x, cray.y) * cosf(angle);
		if (size == 0)
			size = 1;
		draw_col_mdr(cub, x, cub->screen.height / size, &ray, angle);
		ray = ray_cast_sprite(&cub->player.pos, cub->player.angle + angle,
		 		&cub->map);
		if (ray.x == -1)
			continue ;
		t_position rray = ray;
		if (cub->player.pos.x > ray.x)
			rray.x = ceilf(rray.x - 1);
		else
			rray.x = floorf(rray.x);
		if (cub->player.pos.y > ray.y)
			rray.y = ceilf(rray.y - 1);
		else
			rray.y = floorf(rray.y);
		rray.x += 0.5;
		rray.y += 0.5;
		t_position cray2 = (t_position) {rray.x - cub->player.pos.x, rray.y - cub->player.pos.y};
		//float sangle = angle_diff(atan2f(cray2.y, cray2.x), cub->player.angle + angle);
		//printf("diff angle %f\n", sangle * 180 / M_PI);
		float size2 = hypotf(cray2.x, cray2.y);
		if (size2 == 0)
			size2 = 1;
		int lol = cub->screen.height / size2;
		int		am = (cub->screen.height - lol) / 2;
		t_img *s = get_sprite(cub, &rray);
		for (int y = am; y < cub->screen.height - am; y++)
		{
			color = mlx_get_pixel_img(s,
					(x - (WW / 2) + (s->width / 2)) % s->width,
					(y - am));
			if (color != 0)
				mlx_put_pixel_to_img(&cub->screen, x, y, color);
		}
	}
}
