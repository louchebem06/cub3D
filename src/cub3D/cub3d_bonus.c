/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 06:39:17 by bledda            #+#    #+#             */
/*   Updated: 2021/10/15 08:05:26 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"
#include "../../header/sound_bonus.h"

void	cub3d(t_cub *cub)
{
	BASS_Init(-1, 44100, 0, 0, NULL);
	HSTREAM s = BASS_StreamCreateFile(FALSE, "sound/main.mp3", 0, 0, 0);
	BASS_ChannelPlay(s, 1);
	// sleep(1);
	// BASS_ChannelPause(s);
	// sleep(1);
	// BASS_ChannelPlay(s, 0);
	//BASS_Free();
	
	cub->map.map = cub->config.map;
	cub->map.width = cub->config.map_x;
	cub->map.height = cub->config.map_y;
	cub->win.mlx = mlx_init();
	cub->win.win = mlx_new_window(cub->win.mlx, WINDOWS_WIDTH, WINDOWS_HEIGHT,
			"cub3D");
	generate_img(cub);
	hook(cub);
}