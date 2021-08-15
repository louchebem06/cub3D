/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 18:13:22 by bledda            #+#    #+#             */
/*   Updated: 2021/08/15 12:28:09 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

static int	close_click(int keycode, t_cub *cub)
{
	(void) cub;
	(void) keycode;
	exit(0);
	return (0);
}

static void	trace_minimap(t_cub *cub)
{
	for (int y = 0; cub->config.map[y]; y++)
		for (int x = 0; cub->config.map[y][x]; x++)
		{
			if (cub->config.map[y][x] == ' ')
				mlx_put_image_to_window(cub->win.mlx, cub->win.win, cub->mini_data.yellow.img,
					x * 10, (y * 10) + WINDOWS_HEIGHT - (cub->config.map_y * 10));
			else if (cub->config.map[y][x] == '1')
				mlx_put_image_to_window(cub->win.mlx, cub->win.win, cub->mini_data.red.img,
					x * 10, (y * 10) + WINDOWS_HEIGHT - (cub->config.map_y * 10));
			else if (cub->config.map[y][x] == '0')
				mlx_put_image_to_window(cub->win.mlx, cub->win.win, cub->mini_data.white.img,
					x * 10, (y * 10) + WINDOWS_HEIGHT - (cub->config.map_y * 10));
		}
	mlx_put_image_to_window(cub->win.mlx, cub->win.win, cub->mini_data.green.img,
			 		cub->player.pos.x * 10, (cub->player.pos.y * 10) + WINDOWS_HEIGHT - (cub->config.map_y * 10));
	mlx_put_image_to_window(cub->win.mlx, cub->win.win, cub->mini_data.direction.img,
			 		cub->player.pos.x * 10, (cub->player.pos.y * 10 + 10) + WINDOWS_HEIGHT - (cub->config.map_y * 10));
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
	if (keycode == KEY_W || keycode == KEY_S || keycode == KEY_A || keycode == KEY_D
		|| keycode == KEY_ARROW_LEFT || keycode == KEY_ARROW_RIGHT)
	{
		printf("Player Y : %f\n Player X : %f\n Angle : %f\n",
			cub->player.pos.y, cub->player.pos.x, cub->player.angle);
		mlx_put_image_to_window(cub->win.mlx, cub->win.win, cub->screen.img, 0, 0);
		trace_minimap(cub);
	}
	return (0);
}

static void setup(t_cub *cub)
{
	cub->win.mlx = mlx_init();
	cub->win.win = mlx_new_window(cub->win.mlx, WINDOWS_WIDTH, WINDOWS_HEIGHT,
		"cub3D");
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
	cub->screen.img = mlx_new_image(cub->win.mlx, WINDOWS_WIDTH,
		WINDOWS_HEIGHT);
	cub->minimap.img = mlx_new_image(cub->win.mlx, cub->config.map_x * 10,
		cub->config.map_y * 10);
	cub->mini_data.red.img = mlx_new_image(cub->win.mlx, 10, 10);
	cub->mini_data.white.img = mlx_new_image(cub->win.mlx, 10, 10);
	cub->mini_data.green.img = mlx_new_image(cub->win.mlx, 10, 10);
	cub->mini_data.yellow.img = mlx_new_image(cub->win.mlx, 10, 10);
	cub->mini_data.player.img = mlx_new_image(cub->win.mlx, 10, 10);
	cub->mini_data.direction.img = mlx_new_image(cub->win.mlx, 5, 10);

	for (int y = 0; y < 10; y++)
		for (int x = 0; x < 10; x++)
		{
			mlx_put_pixel_to_img(&cub->mini_data.red, x, y, create_trgb(0, 255, 0, 0));
			mlx_put_pixel_to_img(&cub->mini_data.white, x, y, create_trgb(0, 255, 255, 255));
			mlx_put_pixel_to_img(&cub->mini_data.green, x, y, create_trgb(0, 0, 255, 0));
			mlx_put_pixel_to_img(&cub->mini_data.direction, x, y, create_trgb(0, 0, 255, 0));
			mlx_put_pixel_to_img(&cub->mini_data.yellow, x, y, create_trgb(0, 255, 251, 0));
		}
}

static void hook(t_cub *cub)
{
	mlx_hook(cub->win.win, 2, 1L << 0, key_press, cub);
	mlx_hook(cub->win.win, 17, 0, close_click, cub);
	mlx_loop(cub->win.mlx);
}

static void	put_img(t_cub *cub)
{
	mlx_put_img_to_img(&cub->screen, &cub->texture.no, 0, 0);
	mlx_put_img_to_img(&cub->screen, &cub->texture.so, 64, 0);
	mlx_put_img_to_img(&cub->screen, &cub->texture.we, 128, 0);
	mlx_put_img_to_img(&cub->screen, &cub->texture.ea, 192, 0);
}

int	main(int ac, const char **av)
{
	t_cub	cub;

	if (ac == 2 && ft_config(&cub, av[1]))
	{
		printf("Player Y : %f\n Player X : %f\n Angle : %f\n",
			cub.player.pos.y, cub.player.pos.x, cub.player.angle);
		setup(&cub);
		generate_img(&cub);
		put_img(&cub);
		mlx_put_image_to_window(cub.win.mlx, cub.win.win, cub.screen.img, 0, 0);
		trace_minimap(&cub);
		hook(&cub);
	}
	else if (ac == 1)
		ft_error("Error:\n\t-Please specify a map\n", RED);
	else if (ac > 2)
		ft_error("Error:\n\t-Too many arguments\n", RED);
	return (0);
}
