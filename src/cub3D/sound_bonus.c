/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sound_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 16:04:09 by bledda            #+#    #+#             */
/*   Updated: 2021/10/17 22:41:37 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"
#include "../../header/sound_bonus.h"

void	init_sound(t_cub *cub)
{
	static bool		init = false;

	if (!init)
	{
		BASS_Init(-1, 44100, 0, 0, NULL);
		init = true;
		cub->sound.main.file = BASS_StreamCreateFile(FALSE,
				"sound/main.mp3", 0, 0, BASS_SAMPLE_LOOP);
		cub->sound.step_classic.file = BASS_StreamCreateFile(FALSE,
				"sound/pas.mp3", 0, 0, 0);
		cub->sound.tir.file = BASS_StreamCreateFile(FALSE,
				"sound/tir.mp3", 0, 0, 0);
		cub->sound.recharge.file = BASS_StreamCreateFile(FALSE,
				"sound/recharge.mp3", 0, 0, 0);
		cub->sound.step_classic.state = false;
	}
}

void	toggle(t_music *music, bool restart)
{
	QWORD end = BASS_StreamGetFilePosition(music->file, BASS_FILEPOS_END);
	QWORD cur = BASS_StreamGetFilePosition(music->file, BASS_FILEPOS_CURRENT);
	if (cur < end && cur != 0)
		return ;
	if (!music->state)
	{
		BASS_ChannelPlay(music->file, restart);
		music->state = true;
		return ;
	}
	BASS_ChannelPause(music->file);
	music->state = false;
}

void	free_sound(t_cub *cub)
{
	BASS_StreamFree(cub->sound.main.file);
	BASS_StreamFree(cub->sound.step_classic.file);
	BASS_StreamFree(cub->sound.tir.file);
	BASS_StreamFree(cub->sound.recharge.file);
	BASS_Free();
}
