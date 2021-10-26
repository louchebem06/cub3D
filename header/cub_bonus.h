/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 01:56:25 by bledda            #+#    #+#             */
/*   Updated: 2021/10/24 22:05:58 by bledda           ###   ########.fr       */
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
	t_music	recharge;
	t_music	tir;
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
	int		balle;
	int		reserve;
}			t_shooter;

typedef struct t_item_sprite
{
	t_position	pos;
	t_img		*s;
	t_img		**s_anim;
}	t_item_sprite;


typedef struct s_sprite
{
	t_img			woman;
	t_img			man;
	t_img			intel;
	t_img			door;
	t_img			circle;
	t_img			lit;
	t_img			tree;
	t_img			doll[6];
	t_item_sprite	*config;
	int				item;
}		t_sprite;

typedef struct s_cub
{
	t_vars				win;
	t_config			config;
	t_map				map;
	t_player			player;
	t_texture			texture;
	t_img				screen;
	unsigned long long	last_f;
	t_keys				keys;
	t_sound				sound;
	t_shooter			shooter;
	t_sprite			sprite;
	t_img				intro[465];
}				t_cub;



#endif
