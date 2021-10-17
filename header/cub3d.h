/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 18:15:35 by bledda            #+#    #+#             */
/*   Updated: 2021/10/16 04:42:13 by mmehran          ###   ########.fr       */
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
# include <stdbool.h>
# ifdef CUB_BONUS
#  include "cub_bonus.h"
#  include "struct_bonus.h"
# else
#  include "cub.h"
#  include "struct.h"
# endif

# define WINDOWS_WIDTH 1280
# define WINDOWS_HEIGHT 720

void		cub3d(t_cub *cub);
bool		is_in_air(const t_map *map, const t_position *ray,
				const t_position *p);
t_position	ray_cast(const t_position *p, const float angle, const t_map *map);
t_position	scale_pos(t_position *pos, float scale_x, float scale_y);
void		draw(t_cub *cub);
void		generate_img(t_cub *c);
int			render_next_frame(t_cub *cub);
void		hook(t_cub *cub);

#endif
