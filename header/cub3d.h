/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 18:15:35 by bledda            #+#    #+#             */
/*   Updated: 2021/08/15 11:33:54 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <stdio.h>
# include "../libft/header/libft.h"
# include "../mlx_utils/header/mlx_keycode.h"
# include "../mlx_utils/header/mlx_utils.h"
# include <fcntl.h>
# include "ft_config.h"
# include "utils.h"
# include "color.h"
# include <math.h>

# define WINDOWS_WIDTH 600
# define WINDOWS_HEIGHT 300

typedef struct s_data_img	t_data_img;
typedef struct s_img		t_img;

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

typedef struct s_minimap
{
	t_img 		red;
	t_img 		white;
	t_img 		yellow;
	t_img 		green;
	t_img		player;
	t_img 		direction;
}				t_minimap;

typedef struct s_cub
{
	t_vars		win;
	t_config	config;
	t_player	player;
	t_texture	texture;
	t_img		screen;
	t_img		minimap;
	t_minimap	mini_data;
}				t_cub;

#endif
