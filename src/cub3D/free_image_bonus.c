/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_image_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 17:35:58 by bledda            #+#    #+#             */
/*   Updated: 2021/10/17 18:02:18 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	free_image(t_cub *cub)
{
	mlx_destroy_image(cub->win.mlx, cub->texture.no.img);
	mlx_destroy_image(cub->win.mlx, cub->texture.so.img);
	mlx_destroy_image(cub->win.mlx, cub->texture.we.img);
	mlx_destroy_image(cub->win.mlx, cub->texture.ea.img);
	mlx_destroy_image(cub->win.mlx, cub->texture.two.img);
	mlx_destroy_image(cub->win.mlx, cub->texture.three.img);
	mlx_destroy_image(cub->win.mlx, cub->texture.four.img);
	mlx_destroy_image(cub->win.mlx, cub->texture.five.img);
	mlx_destroy_image(cub->win.mlx, cub->texture.six.img);
	mlx_destroy_image(cub->win.mlx, cub->texture.seven.img);
	mlx_destroy_image(cub->win.mlx, cub->texture.eight.img);
	mlx_destroy_image(cub->win.mlx, cub->texture.nine.img);
	mlx_destroy_image(cub->win.mlx, cub->texture.beton.img);
	mlx_destroy_image(cub->win.mlx, cub->texture.ceiling.img);
	mlx_destroy_image(cub->win.mlx, cub->texture.floor.img);
	mlx_destroy_image(cub->win.mlx, cub->texture.redline.img);
	mlx_destroy_image(cub->win.mlx, cub->texture.stairs.img);
	mlx_destroy_image(cub->win.mlx, cub->texture.bet.img);
	mlx_destroy_image(cub->win.mlx, cub->shooter.first.img);
	mlx_destroy_image(cub->win.mlx, cub->shooter.second.img);
	mlx_destroy_image(cub->win.mlx, cub->shooter.recharge1.img);
	mlx_destroy_image(cub->win.mlx, cub->shooter.recharge2.img);
	mlx_destroy_image(cub->win.mlx, cub->shooter.viser.img);
	mlx_destroy_image(cub->win.mlx, cub->shooter.viser_tirer.img);
	mlx_destroy_image(cub->win.mlx, cub->shooter.tirer.img);
}
