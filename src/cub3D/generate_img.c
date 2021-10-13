/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_img.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 00:28:05 by mmehran           #+#    #+#             */
/*   Updated: 2021/10/13 18:28:08 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	generate_img(t_cub *c)
{
	c->texture.no.img = mlx_xpm_file_to_image(c->win.mlx,
			c->config.path_no, &c->texture.no.width, &c->texture.no.height);
	c->texture.so.img = mlx_xpm_file_to_image(c->win.mlx,
			c->config.path_so, &c->texture.so.width, &c->texture.so.height);
	c->texture.we.img = mlx_xpm_file_to_image(c->win.mlx,
			c->config.path_we, &c->texture.we.width, &c->texture.we.height);
	c->texture.ea.img = mlx_xpm_file_to_image(c->win.mlx,
			c->config.path_ea, &c->texture.ea.width, &c->texture.ea.height);
	if (!c->texture.no.img || !c->texture.so.img
		|| !c->texture.we.img || !c->texture.ea.img)
	{
		ft_error("Error:\n", RED);
		ft_error("\t-Impossible to load textures\n", RED);
		free_cub(c);
		exit(1);
	}
	create_img(&c->texture.no, c->texture.no.img);
	create_img(&c->texture.so, c->texture.so.img);
	create_img(&c->texture.we, c->texture.we.img);
	create_img(&c->texture.ea, c->texture.ea.img);
	create_img(&c->screen,
		mlx_new_image(c->win.mlx, WINDOWS_WIDTH, WINDOWS_HEIGHT));
	c->screen.width = WINDOWS_WIDTH;
	c->screen.height = WINDOWS_HEIGHT;
}
