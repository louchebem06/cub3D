/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 01:56:25 by bledda            #+#    #+#             */
/*   Updated: 2021/11/05 16:11:34 by bledda           ###   ########.fr       */
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
	t_music	door;
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

typedef struct s_thread_draw
{
	t_cub		*cub;
	int			x_start;
	int			x_end;
	float		size;
	t_position	ray;
	float		angle;
	t_position	cray;
}		t_thread_draw;

typedef struct s_draw_sprite
{
	t_position	center;
	float		scale;
	float		dist;
}	t_draw_sprite;

typedef struct s_calc_sprite
{
	t_player		*p;
	t_position		sprite_pos;
	t_position		dsprite;
	float			dist;
	t_position		dir;
	float			dot;
	float			s_angle;
	float			p_angle;
	float			diff_angle;
	t_position		udsprite;
	float			toast_p;
	t_img			*s;
	t_draw_sprite	send;
	int				i;
}	t_calc_sprite;

typedef struct s_draw_sprite_thread
{
	t_cub			*cub;
	int				id_thread;
	int				nb_thread;
	t_img			*src;
	t_draw_sprite	value;
	float			px;
	float			py;
	float			y;
	float			x;
	unsigned int	color;
	int				xx;
	int				yy;
	int				i;
	int				j;
}	t_draw_sprite_thread;

typedef struct s_door
{
	t_position	pos;
	float		percent_closed;
	bool		closed;
	char		c;
}	t_door;

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
	t_door				*doors;
	int					nb_doors;
	t_img				intro[IMG_INTRO];
	float				z[1280];
	bool				no_intro;
	bool				mouse_in_windows;
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
char		get_map_char2(const t_cub *cub, const t_position *ray,
				const t_position *p);
void		state_door(t_cub *cub);
int			calc_x_y(float a, float b);
void		next(t_position *pos, const t_position *direction);
void		next_d(t_position *pos, const t_position *dir, float percent);
void		next_d2(t_position *pos, const t_position *dir, float percent);

#endif
