/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 03:25:08 by bledda            #+#    #+#             */
/*   Updated: 2021/10/25 05:34:27 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minimap_bonus.h"

static void	update_color(t_rgb *color)
{
	static bool	inter = false;

	inter = !inter;
	if (inter)
		return ;
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
		pos.x * cosf(value) + pos.y * sinf(value) + ray.x,
		-pos.x * sinf(value) + pos.y * cosf(value) + ray.y
	};

	return (direction);
}

static void	update_slow(float angle, float *slow)
{
	static float	angle_s = -10;
	static bool		move = false;
	static bool		first = false;
	static bool		dir = false;

	if (angle_s == -10)
		angle_s = angle;
	if (!move && angle == angle_s)
	{
		first = true;
		move = true;
	}
	if (move)
	{
		if ((int)*slow == 1 || (int)*slow == -1)
			first = false;
		if (dir)
		{
			if (first && *slow > -1.0f)
				*slow -= 0.1f;
			else if (!first && *slow < 0)
				*slow += 0.1f;
		}
		else
		{
			if (first && *slow < 1.0f)
				*slow += 0.1f;
			else if (!first && *slow > 0)
				*slow -= 0.1f;	
		}
	}
	if (*slow <= 0 && angle != angle_s)
	{
		dir = (angle > angle_s) ? true : false;
		move = false;
	}
	angle_s = angle;
}

void	print_nsew(t_cub *cub, int const x, int const y)
{
	const int			color = create_trgb(0, 255, 255, 255);
	const t_position	ray = {x + 95, y + 105};
	const t_position	pos = {x + 95 - ray.x, y + 5 - ray.y};
	static float		slow = 0;
	const t_position	dir[8] = {
		direction(ray, pos, cub->player.angle + slow + M_PI / 2),
		direction(ray, pos, cub->player.angle + slow - M_PI / 2),
		direction(ray, pos, cub->player.angle + slow - M_PI),
		direction(ray, pos, cub->player.angle + slow),
		direction(ray, pos, cub->player.angle + slow + M_PI / 4),
		direction(ray, pos, cub->player.angle + slow - M_PI / 4),
		direction(ray, pos, cub->player.angle + slow - M_PI * 0.75),
		direction(ray, pos, cub->player.angle + slow + M_PI * 0.75)
	};

	update_slow(cub->player.angle, &slow);
	mlx_string_put(cub->win.mlx, cub->win.win, dir[0].x, dir[0].y, color, "N");
	mlx_string_put(cub->win.mlx, cub->win.win, dir[1].x, dir[1].y, color, "S");
	mlx_string_put(cub->win.mlx, cub->win.win, dir[2].x, dir[2].y, color, "W");
	mlx_string_put(cub->win.mlx, cub->win.win, dir[3].x, dir[3].y, color, "E");
	mlx_string_put(cub->win.mlx, cub->win.win, dir[4].x, dir[4].y, color, "NE");
	mlx_string_put(cub->win.mlx, cub->win.win, dir[5].x, dir[5].y, color, "SE");
	mlx_string_put(cub->win.mlx, cub->win.win, dir[6].x, dir[6].y, color, "SW");
	mlx_string_put(cub->win.mlx, cub->win.win, dir[7].x, dir[7].y, color, "NW");
}
