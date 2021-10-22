/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:31:40 by bledda            #+#    #+#             */
/*   Updated: 2021/10/22 16:21:47 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_BONUS_H
# define MINIMAP_BONUS_H

# include "cub3d.h"

void	minimap(t_cub *cub, const int x, const int y);
void	print_nsew(t_cub *cub, const int x, const int y);
void	print_border(t_cub *cub, t_position screen);

#endif
