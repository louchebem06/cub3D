/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 01:56:25 by bledda            #+#    #+#             */
/*   Updated: 2021/10/17 11:00:56 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "cub3d.h"
# include "struct.h"

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
}				t_cub;

#endif
