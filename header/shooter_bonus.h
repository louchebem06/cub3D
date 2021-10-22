/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shooter_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 04:35:49 by bledda            #+#    #+#             */
/*   Updated: 2021/10/22 18:50:13 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHOOTER_BONUS_H
# define SHOOTER_BONUS_H

# include "cub3d.h"

void	shooter(t_cub *cub);
int		mouse_hook(int button, int x, int y, t_cub *cub);

#endif
