/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 06:39:17 by bledda            #+#    #+#             */
/*   Updated: 2021/11/11 13:46:10 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"
#include "../../header/sound_bonus.h"
#include "../../header/cub_bonus.h"
#include "../../header/shooter_bonus.h"

void	cub3d(t_cub *cub)
{
	cub->last_f = ft_get_current_time();
	cub->shooter.balle = VAL_CHAR;
	cub->shooter.reserve = VAL_RESERVE;
	cub->map.map = cub->config.map;
	cub->map.width = cub->config.map_x;
	cub->map.height = cub->config.map_y;
	cub->win.mlx = mlx_init();
	if (!cub->win.mlx)
	{
		free_cub(cub);
		ft_error("Error:\n\t-Couldn't init MLX\n", RED);
		exit(1);
	}
	generate_img(cub);
	generate_img_bonus(cub);
	init_sound(cub);
	BASS_ChannelPlay(cub->sound.main.file, 0);
	if (!cub->no_intro)
		generate_img_intro(cub);
	cub->win.win = mlx_new_window(cub->win.mlx, WINDOWS_WIDTH, WINDOWS_HEIGHT,
			"cub3D");
	hook(cub);
}
