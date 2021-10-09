/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_put_img_to_img.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 19:29:14 by bledda            #+#    #+#             */
/*   Updated: 2021/10/09 22:01:51 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/mlx_utils.h"

void	mlx_put_img_to_img(t_img *dest, t_img *src, int x, int y)
{
	int			current_x;
	int			current_y;

	current_y = 0;
	current_x = 0;
	while (current_y < src->height)
	{
		current_x = 0;
		while (current_x < src->width)
		{
			mlx_put_pixel_to_img(dest, current_x + x, current_y + y,
				mlx_get_pixel_img(src, current_x, current_y));
			current_x++;
		}
		current_y++;
	}
}
