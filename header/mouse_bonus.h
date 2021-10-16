/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 03:20:12 by bledda            #+#    #+#             */
/*   Updated: 2021/10/16 02:26:34 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOUSE_BONUS_H
# define MOUSE_BONUS_H

# include "cub3d.h"

# ifdef __APPLE__

int		move_mouse(int x, int y, t_cub *cub);
# elif __linux__

void	move_mouse(t_cub *cub);
# endif

#endif
