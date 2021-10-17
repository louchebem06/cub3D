/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_img_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 00:28:05 by mmehran           #+#    #+#             */
/*   Updated: 2021/10/17 10:27:00 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub_bonus.h"

void	generate_img_bonus(t_cub *c)
{
	c->texture.two.img = mlx_xpm_file_to_image(c->win.mlx,
			"texture/Wall/123 Soleil.xpm", &c->texture.two.width, &c->texture.two.height);
	c->texture.three.img = mlx_xpm_file_to_image(c->win.mlx,
			"texture/Wall/Dalgona.xpm", &c->texture.three.width, &c->texture.three.height);
	c->texture.four.img = mlx_xpm_file_to_image(c->win.mlx,
			"texture/Wall/Tir a la corde.xpm", &c->texture.four.width, &c->texture.four.height);
	c->texture.five.img = mlx_xpm_file_to_image(c->win.mlx,
			"texture/Wall/Jeux des billes.xpm", &c->texture.five.width, &c->texture.five.height);
	c->texture.six.img = mlx_xpm_file_to_image(c->win.mlx,
			"texture/Wall/Pierre de gue.xpm", &c->texture.six.width, &c->texture.six.height);
	c->texture.seven.img = mlx_xpm_file_to_image(c->win.mlx,
			"texture/Wall/Ojingeo.xpm", &c->texture.seven.width, &c->texture.seven.height);
	c->texture.eight.img = mlx_xpm_file_to_image(c->win.mlx,
			"texture/Wall/Ddakji.xpm", &c->texture.eight.width, &c->texture.eight.height);
	c->texture.nine.img = mlx_xpm_file_to_image(c->win.mlx,
			"texture/Wall/Wall 1 2 3 Soleil.xpm", &c->texture.nine.width, &c->texture.nine.height);
	c->texture.beton.img = mlx_xpm_file_to_image(c->win.mlx,
			"texture/Wall/Beton.xpm", &c->texture.beton.width, &c->texture.beton.height);
	c->texture.ceiling.img = mlx_xpm_file_to_image(c->win.mlx,
			"texture/Floor_Ceil/sky.xpm", &c->texture.ceiling.width, &c->texture.ceiling.height);
	c->texture.floor.img = mlx_xpm_file_to_image(c->win.mlx,
			"texture/Floor_Ceil/terre.xpm", &c->texture.floor.width, &c->texture.floor.height);
	c->texture.redline.img = mlx_xpm_file_to_image(c->win.mlx,
			"texture/Floor_Ceil/redline.xpm", &c->texture.redline.width, &c->texture.redline.height);
	c->texture.stairs.img = mlx_xpm_file_to_image(c->win.mlx,
			"texture/Floor_Ceil/squid_game_escaliers.xpm", &c->texture.stairs.width, &c->texture.stairs.height);
	c->texture.bet.img = mlx_xpm_file_to_image(c->win.mlx,
			"texture/Floor_Ceil/Beton.xpm", &c->texture.bet.width, &c->texture.bet.height);
	if (!c->texture.nine.img)
	{
		ft_error("Error:\n", RED);
		ft_error("\t-Impossible to load bonus textures\n", RED);
		free_cub(c);
		exit(1);
	}
	create_img(&c->texture.two, c->texture.two.img);
	create_img(&c->texture.three, c->texture.three.img);
	create_img(&c->texture.four, c->texture.four.img);
	create_img(&c->texture.five, c->texture.five.img);
	create_img(&c->texture.six, c->texture.six.img);
	create_img(&c->texture.seven, c->texture.seven.img);
	create_img(&c->texture.eight, c->texture.eight.img);
	create_img(&c->texture.nine, c->texture.nine.img);
	create_img(&c->texture.beton, c->texture.beton.img);
	create_img(&c->texture.ceiling, c->texture.ceiling.img);
	create_img(&c->texture.floor, c->texture.floor.img);
	create_img(&c->texture.redline, c->texture.redline.img);
	create_img(&c->texture.stairs, c->texture.stairs.img);
	create_img(&c->texture.bet, c->texture.bet.img);
}
