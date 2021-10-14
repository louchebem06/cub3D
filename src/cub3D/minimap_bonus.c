/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:45:43 by bledda            #+#    #+#             */
/*   Updated: 2021/10/14 04:04:46 by bledda           ###   ########.fr       */
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

static void print_background(t_cub *cub, t_img *minimap)
{
	t_rgb	color;

	for (int y = 15; y < 215; y++)
	{
		for (int x = 15; x < 215; x++)
		{
			color = uitorgb(mlx_get_pixel_img(&cub->screen, x, y));
			color.r *= 0.5;
			color.g *= 0.5;
			color.b *= 0.5;
			mlx_put_pixel_to_img(minimap, x-15, y-15, create_trgb(0,color.r ,color.g ,color.b));
		}		
	}
}

static void	print_minimap(t_cub *cub, t_img *minimap)
{
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
						mlx_put_pixel_to_img(minimap, i + (x * 10), j + (y * 10), create_trgb(0,255,0,0));
					}
				}
			}
		}
	}
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			mlx_put_pixel_to_img(minimap, 100 + i, j + 100, create_trgb(0,0,255,0));
		}
	}
}

static void crop_cicle(t_cub *cub, t_img *minimap)
{
	for (int y = 0; y < 200; y++)
	{
		for (int x = 0; x < 200; x++)
		{
			if (hypotf(x - 100, y - 100) <= 100)
				continue ;
			mlx_put_pixel_to_img(minimap, x, y, mlx_get_pixel_img(&cub->screen, x + 15, y + 15));
		}
	}
}

void	minimap(t_cub *cub)
{
	t_img	minimap;

	t_img	temp;
	temp.img = mlx_new_image(cub->win.mlx, 200, 200);
	temp.height = 200;
	temp.width = 200;
	create_img(&temp, temp.img);
	minimap.img = mlx_new_image(cub->win.mlx, 200, 200);
	minimap.height = 200;
	minimap.width = 200;
	create_img(&minimap, minimap.img);

	print_background(cub, &temp);
	print_minimap(cub, &temp);
	for (int y = 0; y < 200; y++)
	{
		for (int x = 0; x < 200; x++)
		{
			float xx, yy;
			unsigned int color = mlx_get_pixel_img(&temp, x, y);
			xx =x;
			yy=y;
			if (color == 0x00FF0000 || color == 0x00FF00)
			{
				xx = cosf(-cub->player.angle - M_PI / 2) * (x - 100) - sinf(-cub->player.angle- M_PI / 2) * (y - 100);
				yy = sinf(-cub->player.angle - M_PI / 2) * (x - 100) + cosf(-cub->player.angle - M_PI / 2) * (y - 100);
				xx += 100;
				yy += 100;
			}
			mlx_put_pixel_to_img(&minimap, xx, yy, color);
		}
	}
	crop_cicle(cub, &minimap);
	mlx_put_img_to_img(&cub->screen, &minimap, 15, 15);
	mlx_destroy_image(cub->win.mlx, temp.img);
	mlx_destroy_image(cub->win.mlx, minimap.img);
}
