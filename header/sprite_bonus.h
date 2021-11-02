/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 23:58:11 by bledda            #+#    #+#             */
/*   Updated: 2021/11/02 13:48:16 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITE_BONUS_H
# define SPRITE_BONUS_H

# include "cub3d.h"
# include "cub_bonus.h"

void	sprite(t_cub *cub);

float	ft_dot(t_position a, t_position b);
void	update_sprites_dist(t_position *p, t_item_sprite *config, int item);
void	sort_sprite(t_item_sprite *config, int item);

#endif
