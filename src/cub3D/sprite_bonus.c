/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 23:59:13 by bledda            #+#    #+#             */
/*   Updated: 2021/10/21 15:53:55 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/sprite_bonus.h"

void	sprite(t_cub *cub)
{
	unsigned int	color;
	static long int	first = 0;
	static int		i = 0;
	long int		cmp;

	cmp = ft_get_current_time();
	if (cmp - first > 10 && i++)
		first = ft_get_current_time();
	if (i == 35)
		i = 0;
	for (int y = 0; y  < cub->sprite.doll[i].height; y++)
	{
		for (int x = 0; x  < cub->sprite.doll[i].width; x++)
		{
			color = mlx_get_pixel_img(&cub->sprite.doll[i], x, y);
			mlx_put_pixel_to_img(&cub->screen, x, y, color);
		}
	}
}
