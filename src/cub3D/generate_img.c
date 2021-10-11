/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_img.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 00:28:05 by mmehran           #+#    #+#             */
/*   Updated: 2021/10/12 00:33:56 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

static void	create_img(t_img *img, void *mlx_img)
{
	img->img = mlx_img;
	img->data.addr = mlx_get_data_addr(mlx_img, &img->data.bits_per_pixel,
			&img->data.line_length, &img->data.endian);
}

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
