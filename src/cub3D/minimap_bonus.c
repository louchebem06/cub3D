/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:45:43 by bledda            #+#    #+#             */
/*   Updated: 2021/10/17 13:17:34 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minimap_bonus.h"

static t_rgb	uitorgb(unsigned int value)
{
	t_rgb	result;

	result.r = ((value & 0x00FF0000) >> 16);
	result.g = ((value & 0x0000FF00) >> 8);
	result.b = ((value & 0x000000FF));
	return (result);
}

void	minimap(t_cub *cub)
{
	t_rgb	color;
	int xx = (WINDOWS_WIDTH) - 215;
	int yy = (WINDOWS_HEIGHT) - 215;

	for (int y = yy; y < 200 + yy; y++)
	{
		for (int x = xx; x < 200 + xx; x++)
		{
			if (hypotf(x - (100 + xx), y - (100 + yy)) <= 100)
			{
				color = uitorgb(mlx_get_pixel_img(&cub->screen, x, y));
				color.r *= 0.5;
				color.g *= 0.5;
				color.b *= 0.5;
				mlx_put_pixel_to_img(&cub->screen, x, y, create_trgb(0,color.r ,color.g ,color.b));
			}
		}		
	}

	for (int y = 0; y < 20; y++)
	{
		for (int x = 0; x < 20; x++)
		{
			if ((int)(cub->player.pos.y) - 10 + y < 0
				|| (int)(cub->player.pos.x) - 10 + x < 0
				|| (int)(cub->player.pos.x) - 10 + x >= cub->map.width
				|| (int)(cub->player.pos.y) - 10 + y >= cub->map.height)
				continue ;
			else if (cub->map.map[(int)(cub->player.pos.y) - 10 + y][(int)(cub->player.pos.x) - 10 + x] == '1')
			{
				for (int i = 0; i < 10; i++)
				{
					for (int j = 0; j < 10; j++)
					{
						int xxx = j + xx + (x * 10);
						int yyy = i + yy + (y * 10);
						float xxxx, yyyy;
						xxxx = cosf(-cub->player.angle - M_PI / 2) * (xxx - ((xx + 100))) - sinf(-cub->player.angle- M_PI / 2) * (yyy - ((yy + 100)));
						yyyy = sinf(-cub->player.angle - M_PI / 2) * (xxx - ((xx + 100))) + cosf(-cub->player.angle - M_PI / 2) * (yyy - ((yy + 100)));
						xxxx += xx + 100;
						yyyy += yy + 100;
						if (hypotf(xxxx - (100 + xx), yyyy - (100 + yy)) <= 100)
						{
							mlx_put_pixel_to_img(&cub->screen, xxxx, yyyy, create_trgb(0,255,0,0));
						}
					}
				}
			}
			if (x == 10 && y == 10)
			{
				for (int i = 0; i < 10; i++)
				{
					for (int j = 0; j < 10; j++)
					{
						int xxx = j + xx + (x * 10);
						int yyy = i + yy + (y * 10);
						float xxxx, yyyy;
						xxxx = cosf(-cub->player.angle - M_PI / 2) * (xxx - ((xx + 100))) - sinf(-cub->player.angle- M_PI / 2) * (yyy - ((yy + 100)));
						yyyy = sinf(-cub->player.angle - M_PI / 2) * (xxx - ((xx + 100))) + cosf(-cub->player.angle - M_PI / 2) * (yyy - ((yy + 100)));
						xxxx += xx + 100;
						yyyy += yy + 100;
						
						//int middle_x = xx + 100;
						//int middle_y = yy + 100;
						mlx_put_pixel_to_img(&cub->screen, xxxx, yyyy, create_trgb(0,0,255,0));
					}
				}
			}
		}
	}
}
