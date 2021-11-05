/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:45:43 by bledda            #+#    #+#             */
/*   Updated: 2021/11/05 12:05:04 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minimap_bonus.h"
#include "../../header/cub_bonus.h"

static void	print_background(t_cub *cub, const int x, const int y)
{
	t_rgb		color;
	t_position	map;

	map.y = y - 1;
	while (++map.y < 200 + y)
	{
		map.x = x - 1;
		while (++map.x < 200 + x)
		{
			if (hypotf(map.x - (100 + x), map.y - (100 + y)) < 100)
			{
				color = color_to_rgb(
						mlx_get_pixel_img(&cub->screen, map.x, map.y));
				color.r *= 0.5;
				color.g *= 0.5;
				color.b *= 0.5;
				mlx_put_pixel_to_img(&cub->screen, map.x, map.y,
					create_trgb(0, color.r, color.g, color.b));
			}
		}
	}
}

static void	print_map(t_cub *cub, t_position s, t_position *map, int color)
{
	t_position			m;
	t_position			r;
	t_position			i;
	const t_position	t = {cosf(-cub->player.angle - M_PI / 2),
								sinf(-cub->player.angle - M_PI / 2)};

	i.y = -1;
	while (++i.y < 10)
	{
		i.x = -1;
		while (++i.x < 10)
		{
			m.x = i.x + s.x + 100;
			m.y = i.y + s.y + 100;
			if (map)
			{
				m.x += -100 + (map->x * 10);
				m.y += -100 + (map->y * 10);
			}
			r.x = t.x * (m.x - s.x - 100) - t.y * (m.y - s.y - 100) + s.x + 100;
			r.y = t.y * (m.x - s.x - 100) + t.x * (m.y - s.y - 100) + s.y + 100;
			if (hypotf(r.x - 100 - s.x, r.y - 100 - s.y) < 100)
				mlx_put_pixel_to_img(&cub->screen, r.x, r.y, color);
		}
	}
}

static void	print_map_content(t_cub *cub, char c, t_position screen,
								t_position *map)
{
	if (ft_isset_tab(c, "123456789]"))
		print_map(cub, screen, map, create_trgb(0, 255, 0, 0));
	else if (ft_isset_tab(c, "PpLA"))
		print_map(cub, screen, map, create_trgb(0, 0, 0, 255));
	else if (ft_isset_tab(c, "HFI|O"))
		print_map(cub, screen, map, create_trgb(0, 0, 255, 255));
	else if (c == '0')
		print_map(cub, screen, map, anti_rgb(cub->config.floor));
	else if (ft_isset_tab(c, "!`"))
		print_map(cub, screen, map, create_trgb(0, 255, 255, 0));
	else if (ft_isset_tab(c, "@$"))
		print_map(cub, screen, map, create_trgb(0, 255, 0, 255));
}

void	minimap(t_cub *cub, const int x, const int y)
{
	const t_position	screen = {x, y};
	t_position			map;
	t_position			player;

	map.y = -1;
	print_background(cub, x, y);
	while (++map.y < 20)
	{
		map.x = -1;
		while (++map.x < 20)
		{
			player.x = (int)cub->player.pos.x + map.x - 10;
			player.y = (int)cub->player.pos.y + map.y - 10;
			if ((int)player.x < 0 || (int)player.y < 0
				|| (int)player.x >= cub->map.width
				|| (int)player.y >= cub->map.height)
				continue ;
			print_map_content(cub,
				cub->config.map_s[(int)player.y][(int)player.x],
				screen, &map);
			if (map.x == 10 && map.y == 10)
				print_map(cub, screen, 0, create_trgb(0, 0, 255, 0));
		}
	}
	print_border(cub, screen);
}
