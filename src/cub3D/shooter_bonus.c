/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shooter_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 04:35:52 by bledda            #+#    #+#             */
/*   Updated: 2021/10/15 16:45:09 by bledda           ###   ########.fr       */
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
		WINDOWS_WIDTH / 2, WINDOWS_HEIGHT - shooter.height);
}
