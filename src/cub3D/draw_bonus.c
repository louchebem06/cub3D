/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 00:23:37 by mmehran           #+#    #+#             */
/*   Updated: 2021/11/01 18:32:12 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub_bonus.h"

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

static unsigned int	panorama(t_cub *cub, int x, int y)
{
	const t_img	*ceiling = get_fc_texture(cub, &cub->player.pos, false);

	if (!ceiling)
		return (0);
	return (mlx_get_pixel_img(ceiling,
			ceiling_x_percent(cub, x) * ceiling->width,
			(float) ceiling->height * y / (cub->screen.height / 2)));
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
	while (++y < cub->screen.height)
	{
		if (y < am)
		{
			if (ft_isset_tab(get_map_char(
						&cub->map, &cub->player.pos, &cub->player.pos), "!`$"))
				color = panorama(cub, x, y);
			else
				color = get_fc(cub, y, &dir, false);
		}
		else if (y < am + junk.x)
			color = mlx_get_pixel_img(texture, img_x_percent(cub, ray_pos)
					* texture->width, texture->height * (y - am) / junk.x);
		else
			color = get_fc(cub, y, &dir, true);
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

	x = -1;
	while (++x < cub->screen.width)
	{
		angle = atan2f((float) x / cub->screen.width - 0.5, 0.6);
		ray = ray_cast(&cub->player.pos, cub->player.angle + angle, &cub->map);
		cray = ray;
		cray.x -= cub->player.pos.x;
		cray.y -= cub->player.pos.y;
		size = hypotf(cray.x, cray.y);
		cub->z[x] = size;
		size *= cosf(angle);
		if (size == 0)
			size = 1;
		draw_col(cub, x, &ray, (t_position){cub->screen.height / size, angle});
	}
}
