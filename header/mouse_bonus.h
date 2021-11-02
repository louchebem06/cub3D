/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 03:20:12 by bledda            #+#    #+#             */
/*   Updated: 2021/11/02 13:16:38 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOUSE_BONUS_H
# define MOUSE_BONUS_H

# define BTN1 1
# ifdef __APPLE__
#  define BTN2 2
# elif __linux__
#  define BTN2 3
# endif

# include "cub3d.h"

int		mouse_unclick(int button, t_cub *cub);
int		mouse_click(int button, t_cub *cub);
int		toggle_mouse(t_cub *cub, int button, bool state);

# ifdef __APPLE__

int		move_mouse(int x, int y, t_cub *cub);
# elif __linux__

void	move_mouse(t_cub *cub);
int		enter_mouse_windows(t_cub *cub);
int		leave_mouse_windows(t_cub *cub);
# endif

#endif
