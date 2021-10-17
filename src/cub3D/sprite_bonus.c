/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 23:59:13 by bledda            #+#    #+#             */
/*   Updated: 2021/10/18 00:55:06 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/sprite_bonus.h"

void	sprite(t_cub *cub)
{
	//printf("%f\n", cub->player.angle);
	for (int y = 0; y < cub->sprite.woman.height; y++)
	{
		for (int x = 0; x < cub->sprite.woman.width; x++)
		{
			mlx_put_pixel_to_img(&cub->screen, x, y, mlx_get_pixel_img(&cub->sprite.woman, x, y));
		}
	}
}
