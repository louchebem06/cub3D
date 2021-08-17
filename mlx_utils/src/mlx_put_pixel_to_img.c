/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_put_pixel_to_img.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 10:49:46 by bledda            #+#    #+#             */
/*   Updated: 2021/08/17 17:09:12 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/mlx_utils.h"


void	mlx_put_pixel_to_img(t_img *dest, int x, int y, int color)
{
	t_data_img	img_dst;
	int			*pixel;

	pixel = (int *)mlx_get_data_addr(dest->img, &img_dst.bits_per_pixel,
			&img_dst.line_length, &img_dst.endian);
	//dst = data->addr + y * data->line_length + x * (data->bits_per_pixel / 8);
	pixel[y * img_dst.line_length/4 + x] = color;
	//pixel[y * img_dst.line_length + x * img_dst.bits_per_pixel / 8] = color;
}
