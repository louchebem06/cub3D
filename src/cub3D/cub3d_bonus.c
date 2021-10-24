/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 06:39:17 by bledda            #+#    #+#             */
/*   Updated: 2021/10/24 04:36:00 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"
#include "../../header/sound_bonus.h"
#include "../../header/cub_bonus.h"
#include "../../header/shooter_bonus.h"

void	cub3d(t_cub *cub)
{
	init_sound(cub);
	BASS_ChannelPlay(cub->sound.main.file, 0);
	cub->last_f = ft_get_current_time();
	cub->shooter.balle = VAL_CHAR;
	cub->shooter.reserve = VAL_RESERVE;
	cub->map.map = cub->config.map;
	cub->map.width = cub->config.map_x;
	cub->map.height = cub->config.map_y;
	cub->win.mlx = mlx_init();
	generate_img(cub);
	generate_img_bonus(cub);
	cub->win.win = mlx_new_window(cub->win.mlx, WINDOWS_WIDTH, WINDOWS_HEIGHT,
			"cub3D");
	hook(cub);
}
