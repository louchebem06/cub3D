/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intro_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 01:44:44 by bledda            #+#    #+#             */
/*   Updated: 2021/10/24 01:51:35 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"
#include "../../header/cub_bonus.h"
#include "../../header/utils_bonus.h"

void	intro(t_cub *cub)
{
	for (int i = 0; i < 465; i++)
	{
		unsigned long long time = ft_get_current_time();
		while (ft_get_current_time() - time < 34)
			;
		mlx_put_image_to_window(cub->win.mlx, cub->win.win, cub->intro[i].img, 0, 0);
	}
}
