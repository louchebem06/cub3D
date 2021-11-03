/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 03:25:08 by bledda            #+#    #+#             */
/*   Updated: 2021/11/03 17:07:18 by bledda           ###   ########.fr       */
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
