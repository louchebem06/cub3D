/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shooter_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 04:35:49 by bledda            #+#    #+#             */
/*   Updated: 2021/10/22 15:44:06 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHOOTER_BONUS_H
# define SHOOTER_BONUS_H

# define BTN1 1
# ifdef __APPLE__
#  define BTN2 2
# elif __linux__
#  define BTN2 3
# endif

# include "cub3d.h"

void	shooter(t_cub *cub);
int		mouse_hook(int button, int x, int y, t_cub *cub);
int		toggle_mouse(t_cub *cub, int button, bool state);

#endif
