/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sound_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 16:04:09 by bledda            #+#    #+#             */
/*   Updated: 2021/11/05 16:26:59 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"
#include "../../header/cub_bonus.h"
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
		cub->sound.sun.file = BASS_StreamCreateFile(FALSE,
				"sound/123Soleil.mp3", 0, 0, BASS_SAMPLE_LOOP);
		cub->sound.door.file = BASS_StreamCreateFile(FALSE,
				"sound/door.mp3", 0, 0, 0);
		cub->sound.step_classic.state = false;
		cub->sound.tir.state = false;
		cub->sound.recharge.state = false;
		cub->sound.door.state = false;
	}
}

void	toggle(t_music *music, bool restart)
{
	const QWORD	end = BASS_StreamGetFilePosition(music->file, BASS_FILEPOS_END);
	const QWORD	cur = BASS_StreamGetFilePosition(music->file,
													BASS_FILEPOS_CURRENT);

	if (cur < end && cur > 0)
		return ;
	if (!music->state || cur == end)
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
	BASS_StreamFree(cub->sound.sun.file);
	BASS_StreamFree(cub->sound.door.file);
	BASS_Free();
}

void	sound_dolls(t_cub *cub)
{
	const char	c = cub->map.map
		[(int)cub->player.pos.y][(int)cub->player.pos.x];

	if (ft_isset_tab(c, "!`"))
		BASS_ChannelPlay(cub->sound.sun.file, false);
	else
		BASS_ChannelPause(cub->sound.sun.file);
}
