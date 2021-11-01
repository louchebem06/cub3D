/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 01:56:25 by bledda            #+#    #+#             */
/*   Updated: 2021/11/01 18:25:37 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_BONUS_H
# define CUB_BONUS_H

# include "cub3d.h"
# include "utils_bonus.h"
# include "struct_bonus.h"
# ifdef __APPLE__
#  include "../base24-osx/bass.h"
#  define THREAD_IMG_INTRO 5
# elif __linux__
#  include "../base24-linux/bass.h"
#  define THREAD_IMG_INTRO 1
# endif

# define IMG_INTRO 134

typedef struct s_music
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
	t_music	sun;
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

typedef struct s_item_sprite
{
	t_position	pos;
	t_img		*s;
	t_img		**s_anim;
	char		c;
	float		dist;
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

typedef struct s_thread
{
	void	*main;
	int		id_thread;
	int		nb_thread;
}		t_thread;

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
	t_img				intro[IMG_INTRO];
	float				z[1280];
	bool				no_intro;
}				t_cub;

char		get_map_char(const t_map *map, const t_position *ray,
				const t_position *p);
void		generate_img_bonus(t_cub *c);
void		generate_i(t_cub *cub, t_img *img, char *file);
void		fps(t_cub *cub);
void		print_balle(t_cub *cub);
void		generate_img_intro(t_cub *cub);
t_img		*get_wall_texture(t_cub *cub, const t_position *ray_pos);
t_img		*get_fc_texture(t_cub *cub, const t_position *ray_pos, bool floor);
float		img_x_percent(const t_cub *cub, const t_position *ray_pos);
float		ceiling_x_percent(const t_cub *cub, int x);

#endif
