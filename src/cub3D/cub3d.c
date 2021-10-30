/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 12:37:02 by bledda            #+#    #+#             */
/*   Updated: 2021/10/31 00:10:40 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	cub3d(t_cub *cub)
{
	cub->tick = 0;
	cub->map.map = cub->config.map;
	cub->map.width = cub->config.map_x;
	cub->map.height = cub->config.map_y;
	cub->win.mlx = mlx_init();
	if (!cub->win.mlx)
	{
		free_cub(cub);
		ft_error("Error:\n\t-Env var is not found MLX init is bad\n", RED);
		exit(1);
	}
	cub->win.win = mlx_new_window(cub->win.mlx, WINDOWS_WIDTH, WINDOWS_HEIGHT,
			"cub3D");
	generate_img(cub);
	hook(cub);
}
