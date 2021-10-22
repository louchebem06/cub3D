/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 03:25:08 by bledda            #+#    #+#             */
/*   Updated: 2021/10/22 03:17:33 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minimap_bonus.h"

static void	update_color(t_rgb *color)
{
	if (color->r == 255 && color->g < 255 && color->b == 0)
		color->g++;
	else if (color->r > 0 && color->g == 255 && color->b == 0)
		color->r--;
	else if (color->g == 255 && color->b < 255 && color->r == 0)
		color->b++;
	else if (color->g > 0 && color->b == 255 && color->r == 0)
		color->g--;
	else if (color->b == 255 && color->r < 255 && color->g == 0)
		color->r++;
	else if (color->b > 0 && color->r == 255 && color->g == 0)
		color->b--;
}

void	print_border(t_cub *cub, t_position screen)
{
	t_position		map;
	float			tmp;
	static t_rgb	color = {255, 0, 0};
	const int		size = 5;

	map.x = screen.x - size - 1;
	while (++map.x < 200 + (size * 2) + screen.x - size)
	{
		map.y = screen.y - size - 1;
		while (++map.y < 200 + (size * 2) + screen.y - size)
		{
			tmp = hypotf(map.x - (100 + screen.x), map.y - (100 + screen.y));
			if (tmp >= 100 && tmp < 100 + size)
			{
				mlx_put_pixel_to_img(&cub->screen, map.x, map.y,
					create_trgb(0, color.r, color.g, color.b));
				update_color(&color);
			}
		}
	}
}

static t_position	direction(t_position ray, t_position pos, float value)
{
	const t_position	direction = {
		pos.x * cos(value) + pos.y * sin(value) + ray.x,
		-pos.x * sin(value) + pos.y * cos(value) + ray.y
	};

	return (direction);
}

void	print_nsew(t_cub *cub, int const x, int const y)
{
	const int			color = create_trgb(0, 255, 255, 255);
	const t_position	ray = {x + 95, y + 105};
	const t_position	pos = {x + 95 - ray.x, y + 5 - ray.y};
	const t_position	dir[8] = {
		direction(ray, pos, cub->player.angle + M_PI / 2),
		direction(ray, pos, cub->player.angle - M_PI / 2),
		direction(ray, pos, cub->player.angle - M_PI),
		direction(ray, pos, cub->player.angle),
		direction(ray, pos, cub->player.angle + M_PI / 4),
		direction(ray, pos, cub->player.angle - M_PI / 4),
		direction(ray, pos, cub->player.angle - M_PI / 1.33),
		direction(ray, pos, cub->player.angle + M_PI / 1.33)
	};

	mlx_string_put(cub->win.mlx, cub->win.win, dir[0].x, dir[0].y, color, "N");
	mlx_string_put(cub->win.mlx, cub->win.win, dir[1].x, dir[1].y, color, "S");
	mlx_string_put(cub->win.mlx, cub->win.win, dir[2].x, dir[2].y, color, "W");
	mlx_string_put(cub->win.mlx, cub->win.win, dir[3].x, dir[3].y, color, "E");
	mlx_string_put(cub->win.mlx, cub->win.win, dir[4].x, dir[4].y, color, "NE");
	mlx_string_put(cub->win.mlx, cub->win.win, dir[5].x, dir[5].y, color, "SE");
	mlx_string_put(cub->win.mlx, cub->win.win, dir[6].x, dir[6].y, color, "SW");
	mlx_string_put(cub->win.mlx, cub->win.win, dir[7].x, dir[7].y, color, "NW");
}
