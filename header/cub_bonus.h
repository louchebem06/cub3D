/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 01:56:25 by bledda            #+#    #+#             */
/*   Updated: 2021/10/17 21:26:42 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_BONUS_H
# define CUB_BONUS_H

# include "cub3d.h"
# include "utils_bonus.h"
# include "struct_bonus.h"
# ifdef __APPLE__
#  include "../base24-osx/bass.h"
# elif __linux__
#  include "../base24-linux/bass.h"
# endif

typedef struct t_music
{
	bool	state;
	HSTREAM	file;
}			t_music;

typedef struct s_sound
{
	t_music	main;
	t_music	step_classic;
}			t_sound;

typedef struct s_shooter
{
	t_img	first;
	t_img	recharge3;
	t_img	recharge1;
	t_img	recharge2;
	t_img	viser;
	t_img	viser_tirer;
	t_img	tirer;
}			t_shooter;

typedef struct s_cub
{
	t_vars		win;
	t_config	config;
	t_map		map;
	t_player	player;
	t_texture	texture;
	t_img		screen;
	int			tick;
	t_keys		keys;
	t_sound		sound;
	t_shooter	shooter;
}				t_cub;

char	get_map_char(const t_map *map, const t_position *ray,
			const t_position *p);
void	generate_img_bonus(t_cub *c);

#endif
