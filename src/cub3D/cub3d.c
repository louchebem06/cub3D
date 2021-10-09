/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 12:37:02 by bledda            #+#    #+#             */
/*   Updated: 2021/10/09 22:46:40 by mmehran          ###   ########.fr       */
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

void	clear_screen(t_img *img)
{
	int	x;
	int	y;

	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
			mlx_put_pixel_to_img(img, x++, y, 0);
		y++;
	}
}

bool	is_in_air(t_map *map, t_position *pos)
{
	int	x;
	int	y;

	x = floor(pos->x);
	y = floor(pos->y);
	if (x >= map->width || x < 0 || y >= map->height || y < 0)
		return (false);
	if (map->map[y][x] == '0')
		return (true);
	return (false);
}

t_position	scale_pos(t_position *pos, float scale_x, float scale_y)
{
	t_position	screen_pos;

	screen_pos.x = scale_x * pos->x;
	screen_pos.y = scale_y * pos->y;
	return (screen_pos);
}

t_position	ray_cast(t_player *p, float angle, t_map *map)
{
	const float	delta_x = 0.05 * cos(M_PI * angle / 180);
	const float	delta_y = 0.05 * sin(M_PI * angle / 180);
	t_position	ray_pos;

	ray_pos = p->pos;
	while (is_in_air(map, &ray_pos))
	{
		ray_pos.x += delta_x;
		ray_pos.y += delta_y;
	}
	return (ray_pos);
}

void	draw_col(t_cub *cub, int x, int size, t_position *pos)
{
	const int	am = (cub->screen.height - size) / 2;
	unsigned int	color;
	const float off_x = fabs(pos->x - round(pos->x));
	const float off_y = fabs(pos->y - round(pos->y));
	const float xx = cub->texture.no.width * (off_x > off_y ? off_x : off_y);

	for (int y = 0; y < cub->screen.height; y++)
	{
		color = 0;
		if (y < am)
			color = 0x000000FF;
		else if (y < am + size)
		{
			color = mlx_get_pixel_img(&cub->texture.no, xx, cub->texture.no.height * (y - am) / size);
		}
		mlx_put_pixel_to_img(&cub->screen, x, y, color);
	}
}

void	draw_shit(t_cub *cub)
{
	float size, flen;

	size = 0;
	for (int x = 0; x < cub->screen.width; x++)
	{
		float lol = (float) x / cub->screen.width - 0.5;
		float angle = atan2(lol, 0.5) * 180 / M_PI;
		t_position ray = ray_cast(&cub->player, cub->player.angle + angle, &cub->map);
		t_position cray = ray;
		cray.x -= cub->player.pos.x;
		cray.y -= cub->player.pos.y;
		size = sqrt(cray.x * cray.x + cray.y * cray.y);
		size *= cos(angle * M_PI / 180);
		if (size == 0)
			size = 1;
		//t_position raymdr = scale_pos(&ray, (float) WINDOWS_WIDTH / cub->map.width, (float) WINDOWS_HEIGHT / cub->map.height);
		//mlx_put_pixel_to_img(&cub->screen, raymdr.x, raymdr.y, 0x00FF0000);
		draw_col(cub, x, WINDOWS_HEIGHT / size, &ray);
	}
}

static void	put_img(t_cub *cub)
{
	mlx_put_image_to_window(cub->win.mlx, cub->win.win, cub->screen.img, 0, 0);
}

static int	key_press(int keycode, t_cub *cub)
{
	if (keycode == KEY_W)
	{
		cub->player.pos.x += 0.2 * cos(M_PI * cub->player.angle / 180);
		cub->player.pos.y += 0.2 * sin(M_PI * cub->player.angle / 180);
	}
	else if (keycode == KEY_S)
	{
		cub->player.pos.x -= 0.2 * cos(M_PI * cub->player.angle / 180);
		cub->player.pos.y -= 0.2 * sin(M_PI * cub->player.angle / 180);
	}
	else if (keycode == KEY_A)
	{
		cub->player.pos.x += 0.2 * cos(M_PI * (cub->player.angle - 90) / 180);
		cub->player.pos.y += 0.2 * sin(M_PI * (cub->player.angle - 90) / 180);
	}
	else if (keycode == KEY_D)
	{
		cub->player.pos.x += 0.2 * cos(M_PI * (cub->player.angle + 90) / 180);
		cub->player.pos.y += 0.2 * sin(M_PI * (cub->player.angle + 90) / 180);
	}
	else if (keycode == KEY_ARROW_LEFT)
		cub->player.angle -= 10;
	else if (keycode == KEY_ARROW_RIGHT)
		cub->player.angle += 10;
	else if (keycode == KEY_ECHAP)
		close_click(0, cub);
	if (cub->player.angle < 0)
		cub->player.angle += 360;
	else if (cub->player.angle >= 360)
		cub->player.angle -= 360;
	printf("Player Y : %f\n Player X : %f\n Angle : %f\n",
		cub->player.pos.y, cub->player.pos.x, cub->player.angle);
	printf("%d %d\n", cub->screen.width, cub->screen.height);
	clear_screen(&cub->screen);
	draw_shit(cub);
	t_position pos = scale_pos(&cub->player.pos, WINDOWS_WIDTH / cub->map.width, WINDOWS_HEIGHT / cub->map.height);
	for (int i = 0; i < 10; i++)
		mlx_put_pixel_to_img(&cub->screen, pos.x + i * cos(M_PI * cub->player.angle / 180), pos.y + i * sin(M_PI * cub->player.angle / 180), 0x00FF0000);
	put_img(cub);
	return (0);
}

static void	setup(t_cub *cub)
{
	cub->win.mlx = mlx_init();
	cub->win.win = mlx_new_window(cub->win.mlx, WINDOWS_WIDTH, WINDOWS_HEIGHT,
			 "cub3D");
}

static void	create_img(t_img *img, void *mlx_img)
{
	img->img = mlx_img;
	img->data.addr = mlx_get_data_addr(mlx_img, &img->data.bits_per_pixel,
			&img->data.line_length, &img->data.endian);
}

static void	generate_img(t_cub *cub)
{
	//cub->texture.no.img = mlx_xpm_file_to_image(cub->win.mlx, cub->config.path_no,
	//	&cub->texture.no.height, &cub->texture.no.width);
	//cub->texture.so.img = mlx_xpm_file_to_image(cub->win.mlx, cub->config.path_so,
	//	&cub->texture.so.height, &cub->texture.so.width);
	//cub->texture.we.img = mlx_xpm_file_to_image(cub->win.mlx, cub->config.path_we,
	//	&cub->texture.we.height, &cub->texture.we.width);
	//cub->texture.ea.img = mlx_xpm_file_to_image(cub->win.mlx, cub->config.path_ea,
	//	&cub->texture.ea.height, &cub->texture.ea.width);


	cub->texture.no.img = mlx_xpm_file_to_image(cub->win.mlx, cub->config.path_no,
		&cub->texture.no.height, &cub->texture.no.width);
	create_img(&cub->texture.no, cub->texture.no.img);

	create_img(&cub->screen, mlx_new_image(cub->win.mlx, WINDOWS_WIDTH, WINDOWS_HEIGHT));
	cub->screen.width = WINDOWS_WIDTH;
	cub->screen.height = WINDOWS_HEIGHT;
}

static void hook(t_cub *cub)
{
	mlx_hook(cub->win.win, 2, 1L << 0, key_press, cub);
	mlx_hook(cub->win.win, 17, 0, close_click, cub);
	mlx_loop(cub->win.mlx);
}

void	print_map(const t_map *map)
{
	int	i;

	i = -1;
	while (map->map[++i])
		printf("%s\n", map->map[i]);
}

void	cub3d(t_cub *cub)
{
	cub->map.map = cub->config.map;
	cub->map.width = cub->config.map_x;
	cub->map.height = cub->config.map_y;
	printf("Player Y : %f\n Player X : %f\n Angle : %f\n",
		cub->player.pos.y, cub->player.pos.x, cub->player.angle);
	setup(cub);
	generate_img(cub);
	put_img(cub);
	print_map(&cub->map);
	hook(cub);
}
