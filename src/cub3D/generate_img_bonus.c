/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_img_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 00:28:05 by mmehran           #+#    #+#             */
/*   Updated: 2021/10/24 01:42:19 by bledda           ###   ########.fr       */
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
	generate_i(cub, &cub->shooter.first, "texture/Gun/normal.xpm");
	generate_i(cub, &cub->shooter.recharge3, "texture/Gun/recharge3.xpm");
	generate_i(cub, &cub->shooter.recharge1, "texture/Gun/recharge1.xpm");
	generate_i(cub, &cub->shooter.recharge2, "texture/Gun/recharge2.xpm");
	generate_i(cub, &cub->shooter.viser, "texture/Gun/viser.xpm");
	generate_i(cub, &cub->shooter.viser_tirer, "texture/Gun/viser_tirer.xpm");
	generate_i(cub, &cub->shooter.tirer, "texture/Gun/tir.xpm");
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

static void	generate_img_sprite(t_cub *cub)
{
	generate_i(cub, &cub->sprite.woman, "texture/Sprite/067.xpm");
	generate_i(cub, &cub->sprite.man, "texture/Sprite/456.xpm");
	generate_i(cub, &cub->sprite.intel, "texture/Sprite/218.xpm");
	generate_i(cub, &cub->sprite.door, "texture/Sprite/door.xpm");
	generate_i(cub, &cub->sprite.circle, "texture/Sprite/circle.xpm");
	generate_i(cub, &cub->sprite.lit, "texture/Sprite/lit.xpm");
	generate_i(cub, &cub->sprite.tree, "texture/Sprite/tree.xpm");
}

static void	generate_img_intro(t_cub *cub)
{
	const char	ch_intro[] = "texture/intro29s/intro";
	char		*file;
	char		*tmp[2];
	char		*nb;
	int			i;

	i = -1;
	printf("Loading intro\n");
	while (++i < 465)
	{
		printf("Loading intro %d/464\r", i + 1);
		nb = ft_itoa(i);
		if (i < 10)
		{
			tmp[1] = ft_strjoin(ch_intro, "00");
			tmp[0] = ft_strjoin(tmp[1], nb);
			free(tmp[1]);
		}
		else if (i < 100)
		{
			tmp[1] = ft_strjoin(ch_intro, "0");
			tmp[0] = ft_strjoin(tmp[1], nb);
			free(tmp[1]);
		}
		else
			tmp[0] = ft_strjoin(ch_intro, nb);
		file = ft_strjoin(tmp[0], ".xpm");
		generate_i(cub, &cub->intro[i], file);
		free(nb);
		free(tmp[0]);
		free(file);
	}
}

void	generate_img_bonus(t_cub *cub)
{
	const char	ch_doll[] = "texture/Sprite/Doll/";
	char		*file;
	char		*tmp;
	char		*nb;
	int			i;

	i = -1;
	while (++i < 6)
	{
		nb = ft_itoa(i + 1);
		tmp = ft_strjoin(ch_doll, nb);
		file = ft_strjoin(tmp, ".xpm");
		generate_i(cub, &cub->sprite.doll[i], file);
		free(nb);
		free(tmp);
		free(file);
	}
	generate_img_shooter(cub);
	generate_img_wall(cub);
	generate_img_sprite(cub);
	generate_img_intro(cub);
}
