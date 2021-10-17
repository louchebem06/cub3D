/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_img_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 00:28:05 by mmehran           #+#    #+#             */
/*   Updated: 2021/10/17 21:26:27 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub_bonus.h"

static void	generate_i(t_cub *cub, t_img *img, char *file)
{
	img->img = mlx_xpm_file_to_image(cub->win.mlx, file,
			&img->width, &img->height);
	if (!img->img)
	{
		ft_error("Error:\n", RED);
		ft_error("\t-Impossible to load bonus textures\n", RED);
		free_cub(cub);
		exit(1);
	}
	create_img(img, img->img);
}

static void	generate_img_shooter(t_cub *cub)
{
	generate_i(cub, &cub->shooter.first, "texture/Gun/first.xpm");
	generate_i(cub, &cub->shooter.recharge3, "texture/Gun/recharg3.xpm");
	generate_i(cub, &cub->shooter.recharge1, "texture/Gun/recharg1.xpm");
	generate_i(cub, &cub->shooter.recharge2, "texture/Gun/recharg2.xpm");
	generate_i(cub, &cub->shooter.viser, "texture/Gun/viser.xpm");
	generate_i(cub, &cub->shooter.viser_tirer, "texture/Gun/viser_tirer.xpm");
	generate_i(cub, &cub->shooter.tirer, "texture/Gun/tirer.xpm");
}

static void	generate_img_wall(t_cub *cub)
{
	generate_i(cub, &cub->texture.two, "texture/Wall/123 Soleil.xpm");
	generate_i(cub, &cub->texture.three, "texture/Wall/Dalgona.xpm");
	generate_i(cub, &cub->texture.four, "texture/Wall/Tir a la corde.xpm");
	generate_i(cub, &cub->texture.five, "texture/Wall/Jeux des billes.xpm");
	generate_i(cub, &cub->texture.six, "texture/Wall/Pierre de gue.xpm");
	generate_i(cub, &cub->texture.seven, "texture/Wall/Ojingeo.xpm");
	generate_i(cub, &cub->texture.eight, "texture/Wall/Ddakji.xpm");
	generate_i(cub, &cub->texture.nine, "texture/Wall/Wall 1 2 3 Soleil.xpm");
	generate_i(cub, &cub->texture.beton, "texture/Wall/Beton.xpm");
	generate_i(cub, &cub->texture.ceiling, "texture/Floor_Ceil/sky.xpm");
	generate_i(cub, &cub->texture.floor, "texture/Floor_Ceil/terre.xpm");
	generate_i(cub, &cub->texture.redline, "texture/Floor_Ceil/redline.xpm");
	generate_i(cub, &cub->texture.stairs,
		"texture/Floor_Ceil/squid_game_escaliers.xpm");
	generate_i(cub, &cub->texture.bet, "texture/Floor_Ceil/Beton.xpm");
}

void	generate_img_bonus(t_cub *cub)
{
	generate_img_shooter(cub);
	generate_img_wall(cub);
}
