/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 17:35:58 by bledda            #+#    #+#             */
/*   Updated: 2021/10/17 17:42:00 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	free_image(t_cub *cub)
{
	mlx_destroy_image(cub->win.mlx, cub->texture.no.img);
	mlx_destroy_image(cub->win.mlx, cub->texture.so.img);
	mlx_destroy_image(cub->win.mlx, cub->texture.we.img);
	mlx_destroy_image(cub->win.mlx, cub->texture.ea.img);
}
