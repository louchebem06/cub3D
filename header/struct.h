/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 02:02:20 by bledda            #+#    #+#             */
/*   Updated: 2021/10/16 02:02:41 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "cub3d.h"

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}			t_vars;

typedef struct s_rgb
{
	int		r;
	int		g;
	int		b;
}			t_rgb;

typedef struct s_map
{
	char	**map;
	int		width;
	int		height;
}		t_map;

typedef struct s_config
{
	char	*path_no;
	char	*path_so;
	char	*path_we;
	char	*path_ea;
	t_rgb	floor;
	t_rgb	ceiling;
	char	**map;
	int		map_x;
	int		map_y;
}			t_config;

typedef struct s_position
{
	float	x;
	float	y;
}			t_position;

typedef struct s_player
{
	t_position	pos;
	float		angle;
}				t_player;

typedef struct s_texture
{
	t_img		no;
	t_img		so;
	t_img		we;
	t_img		ea;
}				t_texture;

typedef struct s_keys
{
	bool	up;
	bool	down;
	bool	left;
	bool	right;
	bool	arrow_l;
	bool	arrow_r;
}	t_keys;

#endif
