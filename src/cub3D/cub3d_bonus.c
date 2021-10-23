/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 06:39:17 by bledda            #+#    #+#             */
/*   Updated: 2021/10/23 17:46:03 by mmehran          ###   ########.fr       */
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
	cub->win.win = mlx_new_window(cub->win.mlx, WINDOWS_WIDTH, WINDOWS_HEIGHT,
			"cub3D");
	cub->screen2.img = mlx_new_image(cub->win.mlx, WINDOWS_WIDTH, WINDOWS_HEIGHT);
	create_img(&cub->screen2, cub->screen2.img);
	cub->screen2.width = WINDOWS_WIDTH;
	cub->screen2.height = WINDOWS_HEIGHT;
	generate_img(cub);
	generate_img_bonus(cub);
	hook(cub);
}
