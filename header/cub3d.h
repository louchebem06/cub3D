/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 18:15:35 by bledda            #+#    #+#             */
/*   Updated: 2021/08/14 00:22:18 by bledda           ###   ########.fr       */
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

# define WINDOWS_WIDTH 600
# define WINDOWS_HEIGHT 300

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}			t_vars;

typedef struct s_rgv
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
}			t_config;

typedef struct s_cub
{
	t_vars		win;
	t_config	config;
}				t_cub;

#endif