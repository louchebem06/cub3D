/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 12:37:02 by bledda            #+#    #+#             */
/*   Updated: 2021/08/17 17:10:39 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

static int	close_click(int keycode, t_cub *cub)
{
	(void) cub;
	(void) keycode;
	exit(0);
	return (0);
}

static void print_sqare(t_cub *cub, int x, int y, int color)
{
	int save_x;
	int save_y;

	save_x = x;
	save_y = y;
	while (y < save_y * 10)
	{
		while (x < save_x * 10)
		{
			mlx_put_pixel_to_img(&cub->screen, x, y, color);
			x++;
		}
		y++;
	}
}

static void	trace(t_cub *cub)
{
	int y;
	int x;

	y = -1;
	while (cub->config.map[++y])
	{
		x = -1;
		while (cub->config.map[y][++x])
		{
			if (cub->config.map[y][x] == '1')
				print_sqare(cub, x, y, create_trgb(0, 255, 0, 0));
			else if (cub->config.map[y][x] == '0')
				print_sqare(cub, x, y, create_trgb(0, 0, 255, 0));
			else if (cub->config.map[y][x] == ' ')
				print_sqare(cub, x, y, create_trgb(0, 0, 0, 255));
		}
	}
	//mlx_put_pixel_to_img(&cub->screen, 300, 150, create_trgb(0, 255, 0, 255));
	mlx_put_image_to_window(cub->win.mlx, cub->win.win, cub->screen.img, 0, 0);
}

static int	key_press(int keycode, t_cub *cub)
{
	if (keycode == KEY_W
		&& cub->config.map[(int)(cub->player.pos.y - 0.5)][(int)cub->player.pos.x] != '1')
		cub->player.pos.y -= 0.5;
	else if (keycode == KEY_S
		&& cub->config.map[(int)cub->player.pos.y + 1][(int)cub->player.pos.x] != '1')
		cub->player.pos.y += 0.5;
	else if (keycode == KEY_A
		&& cub->config.map[(int)cub->player.pos.y][(int)(cub->player.pos.x - 0.5)] != '1')
		cub->player.pos.x -= 0.5;
	else if (keycode == KEY_D
		&& cub->config.map[(int)cub->player.pos.y][(int)cub->player.pos.x + 1] != '1')
		cub->player.pos.x += 0.5;
	else if (keycode == KEY_ARROW_LEFT)
		cub->player.angle--;
	else if (keycode == KEY_ARROW_RIGHT)
		cub->player.angle++;
	else if (keycode == KEY_ECHAP)
		close_click(0, cub);
	if (cub->player.angle < 0)
		cub->player.angle = 359;
	else if (cub->player.angle >= 360)
		cub->player.angle = 0;
	trace(cub);
	return (0);
}

static void setup(t_cub *cub)
{
	cub->win.mlx = mlx_init();
	cub->win.win = mlx_new_window(cub->win.mlx, WINDOWS_WIDTH, WINDOWS_HEIGHT, "cub3D");
}

static void generate_img(t_cub *cub)
{
	cub->texture.no.img = mlx_xpm_file_to_image(cub->win.mlx, cub->config.path_no,
		&cub->texture.no.height, &cub->texture.no.width);
	cub->texture.so.img = mlx_xpm_file_to_image(cub->win.mlx, cub->config.path_so,
		&cub->texture.so.height, &cub->texture.so.width);
	cub->texture.we.img = mlx_xpm_file_to_image(cub->win.mlx, cub->config.path_we,
		&cub->texture.we.height, &cub->texture.we.width);
	cub->texture.ea.img = mlx_xpm_file_to_image(cub->win.mlx, cub->config.path_ea,
		&cub->texture.ea.height, &cub->texture.ea.width);
	cub->screen.img = mlx_new_image(cub->win.mlx, WINDOWS_WIDTH, WINDOWS_HEIGHT);
}

static void hook(t_cub *cub)
{
	mlx_hook(cub->win.win, 2, 1L << 0, key_press, cub);
	mlx_hook(cub->win.win, 17, 0, close_click, cub);
	mlx_loop(cub->win.mlx);
}

static void	put_img(t_cub *cub)
{
	(void)cub;
	// mlx_put_img_to_img(&cub->screen, &cub->texture.no, 150, 0);
	// mlx_put_img_to_img(&cub->screen, &cub->texture.so, 150, 150);
	// mlx_put_img_to_img(&cub->screen, &cub->texture.we, 120, 120);
	// mlx_put_img_to_img(&cub->screen, &cub->texture.ea, 192, 0);
}

void	cub3d(t_cub *cub)
{
	printf("Player Y : %f\n Player X : %f\n Angle : %f\n",
		cub->player.pos.y, cub->player.pos.x, cub->player.angle);
	setup(cub);
	generate_img(cub);
	put_img(cub);
	trace(cub);
	hook(cub);
}
