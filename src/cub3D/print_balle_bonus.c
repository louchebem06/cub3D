/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_balle_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 19:01:05 by bledda            #+#    #+#             */
/*   Updated: 2021/10/22 19:11:00 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub_bonus.h"

void	print_balle(t_cub *cub)
{
	char	*str;
	char	*balle;
	char	*reserve;
	char	*tmp;

	balle = ft_itoa(cub->shooter.balle);
	reserve = ft_itoa(cub->shooter.reserve);
	tmp = ft_strjoin(balle, "/");
	str = ft_strjoin(tmp, reserve);
	mlx_string_put(cub->win.mlx, cub->win.win, WW - 100, WH - 15,
		create_trgb(0, 255, 0, 0), str);
	free(balle);
	free(reserve);
	free(tmp);
	free(str);
}
