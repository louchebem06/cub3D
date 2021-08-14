/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 18:15:35 by bledda            #+#    #+#             */
/*   Updated: 2021/08/14 16:25:21 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <stdio.h>
# include "../libft/header/libft.h"
# include "../mlx_utils/header/mlx_keycode.h"
# include "../mlx_utils/header/mlx_put_img_to_img.h"
# include <fcntl.h>
# include "ft_config.h"
# include "utils.h"

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

typedef struct s_cub
{
	t_vars		win;
	t_config	config;
	t_player	player;
}				t_cub;

#endif
