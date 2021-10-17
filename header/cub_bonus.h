/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 01:56:25 by bledda            #+#    #+#             */
/*   Updated: 2021/10/16 04:51:36 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_BONUS_H
# define CUB_BONUS_H

# include "cub3d.h"
# include "struct_bonus.h"

typedef struct s_minimap
{
	t_img	tmp;
	t_img	minimap;
}			t_minimap;

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
	t_minimap	minimap;
}				t_cub;

char	get_map_char(const t_map *map, const t_position *ray,
			const t_position *p);
void	generate_img_bonus(t_cub *c);

#endif
