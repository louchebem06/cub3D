/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:45:43 by bledda            #+#    #+#             */
/*   Updated: 2021/10/13 17:23:49 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minimap_bonus.h"

void	minimap(t_cub *cub)
{
	t_img	minimap;
	t_img	rose;
	t_img	blue;
	t_img	green;
	int		y;
	int		x;

	x = 0;
	y = 0;
	minimap.img = mlx_new_image(cub->win.mlx, cub->map.width * 10,
			cub->map.height * 10);
	rose.img = mlx_xpm_file_to_image(cub->win.mlx,
			"texture/Minimap/10px_rose.xpm", &rose.width, &rose.height);
	green.img = mlx_xpm_file_to_image(cub->win.mlx,
			"texture/Minimap/10px_green.xpm", &green.width, &green.height);
	blue.img = mlx_xpm_file_to_image(cub->win.mlx,
			"texture/Minimap/10px_blue.xpm", &blue.width, &blue.height);
	while (cub->map.map[y])
	{
		x = 0;
		while (cub->map.map[y][x])
		{
			if (cub->map.map[y][x] == '1')
				mlx_put_img_to_img(&minimap, &rose, x * 10, y * 10);
			else
				mlx_put_img_to_img(&minimap, &blue, x * 10, y * 10);
			x++;
		}
		y++;
	}
	// Player pos voir avec mathieu
	mlx_put_img_to_img(&minimap, &green, cub->player.pos.x * 10, cub->player.pos.y * 10);
	mlx_put_image_to_window(cub->win.mlx, cub->win.win, minimap.img,
		WINDOWS_WIDTH / 2 - (cub->map.width * 10 / 2), 15);
	mlx_destroy_image(cub->win.mlx, minimap.img);
	mlx_destroy_image(cub->win.mlx, rose.img);
	mlx_destroy_image(cub->win.mlx, blue.img);
	mlx_destroy_image(cub->win.mlx, green.img);
}
