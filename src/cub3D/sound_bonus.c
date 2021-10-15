/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sound_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 16:04:09 by bledda            #+#    #+#             */
/*   Updated: 2021/10/15 16:46:09 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/header/libft.h"
#include "../../header/sound_bonus.h"

HSTREAM	init_sound(char const *file)
{
	static bool		init = false;
	static HSTREAM	main;
	static HSTREAM	pas;
	static HSTREAM	s;

	if (!init)
	{
		BASS_Init(-1, 44100, 0, 0, NULL);
		init = true;
	}
	if (!main)
	{
		main = BASS_StreamCreateFile(FALSE, "sound/main.mp3", 0, 0,
				BASS_SAMPLE_LOOP);
		pas = BASS_StreamCreateFile(FALSE, "sound/pas.mp3", 0, 0, 0);
	}
	if (!ft_strncmp(file, "main", 4))
		return (main);
	if (!ft_strncmp(file, "pas", 3))
		return (pas);
	return (s);
}

void	free_sound(void)
{
	BASS_StreamFree(init_sound("main"));
	BASS_StreamFree(init_sound("pas"));
	BASS_Free();
}
