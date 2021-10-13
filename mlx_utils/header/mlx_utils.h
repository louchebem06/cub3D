/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 19:32:01 by bledda            #+#    #+#             */
/*   Updated: 2021/10/13 16:44:52 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_UTILS_H
# define MLX_UTILS_H

# include <mlx.h>
# include "mlx_keycode.h"

typedef struct s_data_img
{
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data_img;

typedef struct s_img
{
	void		*img;
	t_data_img	data;
	int			width;
	int			height;
}			t_img;

void			mlx_put_img_to_img(t_img *dest, t_img *src, int x, int y);
int				create_trgb(int t, int r, int g, int b);
void			mlx_put_pixel_to_img(t_img *dest, int x, int y, int color);
unsigned int	mlx_get_pixel_img(const t_img *img, int x, int y);

#endif
