/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 12:37:02 by bledda            #+#    #+#             */
/*   Updated: 2021/10/11 18:41:42 by mmehran          ###   ########.fr       */
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

bool	is_in_air(const t_map *map, const t_position *ray, const t_position *p)
{
	int	x;
	int	y;

	if (p->x > ray->x)
		x = ceilf(ray->x - 1);
	else
		x = floorf(ray->x);
	if (p->y > ray->y)
		y = ceilf(ray->y - 1);
	else
		y = floorf(ray->y);
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

void	next(t_position *pos, const t_position *direction)
{
	float		slope;
	t_position	next_x;
	t_position	next_y;

	slope = 1;
	if (direction->x != 0)
		slope = direction->y / direction->x;
	next_x = (t_position){0};
	next_y = (t_position){0};
	const float dx = (direction->x > 0) ? floorf(pos->x + 1) - pos->x : ceilf(pos->x - 1) - pos->x;
	const float dy = (direction->y > 0) ? floorf(pos->y + 1) - pos->y : ceilf(pos->y - 1) - pos->y;
	next_x.x = dx;
	next_x.y = dx * slope;
	next_y.x = dy / slope;
	next_y.y = dy;
	if (next_x.x * next_x.x + next_x.y * next_x.y
		< next_y.x * next_y.x + next_y.y * next_y.y)
	{
		pos->x += next_x.x;
		pos->y += next_x.y;
	}
	else
	{
		pos->x += next_y.x;
		pos->y += next_y.y;
	}
}

t_position	ray_cast(const t_player *p, const float angle, const t_map *map)
{
	t_position	dir;
	t_position	ray_pos;

	dir.x = cosf(M_PI * angle / 180);
	dir.y = sinf(M_PI * angle / 180);
	ray_pos = p->pos;
	while (is_in_air(map, &ray_pos, &p->pos))
		next(&ray_pos, &dir);
	return (ray_pos);
}

unsigned int	antirgb(t_rgb rgb)
{
	return rgb.r << 16 | rgb.g << 8 | rgb.b;
}

static t_img	*get_texture_direction(t_cub *cub, const t_position *ray_pos)
{
	const float	off_x = ray_pos->x - floorf(ray_pos->x);
	const float	off_y = ray_pos->y - floorf(ray_pos->y);

	if (off_x > off_y)
	{
		if (cub->player.pos.y > ray_pos->y)
			return (&cub->texture.so);
		return (&cub->texture.no);
	}
	else
	{
		if (cub->player.pos.x > ray_pos->x)
			return (&cub->texture.ea);
		return (&cub->texture.we);
	}
	return (0);
}

void	draw_col(t_cub *cub, int x, int size, const t_position *ray_pos)
{
	const int	am = (cub->screen.height - size) / 2;
	const float	off_x = ray_pos->x - floorf(ray_pos->x);
	const float	off_y = ray_pos->y - floorf(ray_pos->y);
	const t_img	*texture = get_texture_direction(cub, ray_pos);
	const float	xx = texture->width * (off_x > off_y ? off_x : off_y);
	unsigned int	color;
	int	y;

	y = -1;
	while (++y < cub->screen.height)
	{
		color = antirgb(cub->config.floor);
		if (y < am)
			color = antirgb(cub->config.ceiling);
		else if (y < am + size)
			color = mlx_get_pixel_img(texture, xx,
					texture->height * (y - am) / size);
		mlx_put_pixel_to_img(&cub->screen, x, y, color);
	}
}

void	draw_shit(t_cub *cub)
{
	float		size;
	t_position	ray;
	t_position	cray;
	int			x;
	float		angle;

	size = 0;
	x = -1;
	while (++x < cub->screen.width)
	{
		angle = atan2f((float) x / cub->screen.width - 0.5, 0.6) * 180 / M_PI;
		ray = ray_cast(&cub->player, cub->player.angle + angle, &cub->map);
		cray = ray;
		cray.x -= cub->player.pos.x;
		cray.y -= cub->player.pos.y;
		size = hypotf(cray.x, cray.y);
		size *= cosf(angle * M_PI / 180);
		if (size == 0)
			size = 1;
		draw_col(cub, x, cub->screen.height / size, &ray);
	}
}

static void	put_img(t_cub *cub)
{
	mlx_put_image_to_window(cub->win.mlx, cub->win.win, cub->screen.img, 0, 0);
}

static int	key_press(int keycode, t_cub *cub)
{
	if (cub->up_to_date)
		return (0);
	cub->up_to_date = true;
	if (keycode == KEY_W)
	{
		cub->player.pos.x += 0.2 * cosf(M_PI * cub->player.angle / 180);
		cub->player.pos.y += 0.2 * sinf(M_PI * cub->player.angle / 180);
	}
	else if (keycode == KEY_S)
	{
		cub->player.pos.x -= 0.1 * cosf(M_PI * cub->player.angle / 180);
		cub->player.pos.y -= 0.1 * sinf(M_PI * cub->player.angle / 180);
	}
	else if (keycode == KEY_A)
	{
		cub->player.pos.x += 0.15 * cosf(M_PI * (cub->player.angle - 90) / 180);
		cub->player.pos.y += 0.15 * sinf(M_PI * (cub->player.angle - 90) / 180);
	}
	else if (keycode == KEY_D)
	{
		cub->player.pos.x += 0.15 * cosf(M_PI * (cub->player.angle + 90) / 180);
		cub->player.pos.y += 0.15 * sinf(M_PI * (cub->player.angle + 90) / 180);
	}
	else if (keycode == KEY_ARROW_LEFT)
		cub->player.angle -= 5;
	else if (keycode == KEY_ARROW_RIGHT)
		cub->player.angle += 5;
	else if (keycode == KEY_ECHAP)
		close_click(0, cub);
	if (cub->player.angle < 0)
		cub->player.angle += 360;
	else if (cub->player.angle >= 360)
		cub->player.angle -= 360;
	printf("Player Y : %f\n Player X : %f\n Angle : %f\n",
		cub->player.pos.y, cub->player.pos.x, cub->player.angle);
	printf("%d %d\n", cub->screen.width, cub->screen.height);
	//clear_screen(&cub->screen);
	draw_shit(cub);
	t_position pos = scale_pos(&cub->player.pos, WINDOWS_WIDTH / cub->map.width, WINDOWS_HEIGHT / cub->map.height);
	for (int i = 0; i < 10; i++)
		mlx_put_pixel_to_img(&cub->screen, pos.x + i * cosf(M_PI * cub->player.angle / 180), pos.y + i * sinf(M_PI * cub->player.angle / 180), 0x00FF0000);
	put_img(cub);
	cub->up_to_date = false;
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

	cub->texture.no.img = mlx_xpm_file_to_image(cub->win.mlx, cub->config.path_no,
		&cub->texture.no.width, &cub->texture.no.height);
	create_img(&cub->texture.no, cub->texture.no.img);

	cub->texture.so.img = mlx_xpm_file_to_image(cub->win.mlx, cub->config.path_so,
		&cub->texture.so.width, &cub->texture.so.height);
	create_img(&cub->texture.so, cub->texture.so.img);

	cub->texture.we.img = mlx_xpm_file_to_image(cub->win.mlx, cub->config.path_we,
		&cub->texture.we.width, &cub->texture.we.height);
	create_img(&cub->texture.we, cub->texture.we.img);

	cub->texture.ea.img = mlx_xpm_file_to_image(cub->win.mlx, cub->config.path_ea,
		&cub->texture.ea.width, &cub->texture.ea.height);
	create_img(&cub->texture.ea, cub->texture.ea.img);

	create_img(&cub->screen, mlx_new_image(cub->win.mlx, WINDOWS_WIDTH, WINDOWS_HEIGHT));
	cub->screen.width = WINDOWS_WIDTH;
	cub->screen.height = WINDOWS_HEIGHT;
}

static void	hook(t_cub *cub)
{
	mlx_hook(cub->win.win, 2, 1, key_press, cub);
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
	cub->up_to_date = false;
	printf("Player Y : %f\n Player X : %f\n Angle : %f\n",
		cub->player.pos.y, cub->player.pos.x, cub->player.angle);
	setup(cub);
	generate_img(cub);
	draw_shit(cub);
	put_img(cub);
	print_map(&cub->map);
	hook(cub);
}
