/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shooter_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 04:35:52 by bledda            #+#    #+#             */
/*   Updated: 2021/10/15 23:44:12 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/shooter_bonus.h"

void	shooter(t_cub *cub)
{
	t_img	shooter;

	shooter.img = mlx_xpm_file_to_image(cub->win.mlx, "texture/Gun/first.xpm",
			&shooter.width, &shooter.height);
	create_img(&shooter, shooter.img);
	mlx_put_img_to_img(&cub->screen, &shooter,
		WINDOWS_WIDTH / 1.5, WINDOWS_HEIGHT - shooter.height);
	mlx_destroy_image(cub->win.mlx, shooter.img);
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (hypotf(i - 5, j - 5) <= 4)
				mlx_put_pixel_to_img(&cub->screen,
					WINDOWS_WIDTH / 2 + i,
					WINDOWS_HEIGHT / 2 + j,
					create_trgb(0, 255, 255, 255));
		}
	}
}
