/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_put_pixel_to_img.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 10:49:46 by bledda            #+#    #+#             */
/*   Updated: 2021/10/11 23:50:59 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/mlx_utils.h"

void	mlx_put_pixel_to_img(t_img *dest, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= dest->width || y < 0 || y >= dest->height)
		return ;
	if (color >> 24 == 0xFF)
		return ;
	dst = dest->data.addr + (y * dest->data.line_length
			+ x * (dest->data.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
