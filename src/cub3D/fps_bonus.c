/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 05:50:00 by bledda            #+#    #+#             */
/*   Updated: 2021/10/23 17:10:36 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub_bonus.h"

void	fps(t_cub *cub)
{
	static int					fps = 0;
	static unsigned long long	time = 0;
	static char					*ptr_fps;

	if (!cub)
	{
		free(ptr_fps);
		return ;
	}
	fps++;
	if (ft_get_current_time() - time >= 1000 || time == 0)
	{
		if (ptr_fps)
			free(ptr_fps);
		ptr_fps = ft_itoa(fps);
		fps = 0;
		time = ft_get_current_time();
	}
	mlx_string_put(cub->win.mlx, cub->win.win, 10, 20,
		create_trgb(0, 0, 255, 0), "FPS : ");
	mlx_string_put(cub->win.mlx, cub->win.win, 50, 20,
		create_trgb(0, 0, 255, 0), ptr_fps);
}
