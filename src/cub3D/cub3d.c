/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 12:37:02 by bledda            #+#    #+#             */
/*   Updated: 2021/10/12 00:15:26 by mmehran          ###   ########.fr       */
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

t_position	scale_pos(t_position *pos, float scale_x, float scale_y)
{
	t_position	screen_pos;

	screen_pos.x = scale_x * pos->x;
	screen_pos.y = scale_y * pos->y;
	return (screen_pos);
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
	const int		am = (cub->screen.height - size) / 2;
	const t_img		*texture = get_texture_direction(cub, ray_pos);
	float			xx;
	unsigned int	color;
	int				y;

	y = -1;
	xx = texture->width;
	if (ray_pos->x - floorf(ray_pos->x) > ray_pos->y - floorf(ray_pos->y))
		xx *= ray_pos->x - floorf(ray_pos->x);
	else
		xx *= ray_pos->y - floorf(ray_pos->y);
	while (++y < cub->screen.height)
	{
		color = anti_rgb(cub->config.floor);
		if (y < am)
			color = anti_rgb(cub->config.ceiling);
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
		angle = atan2f((float) x / cub->screen.width - 0.5, 0.6);
		ray = ray_cast(&cub->player, cub->player.angle + angle, &cub->map);
		cray = ray;
		cray.x -= cub->player.pos.x;
		cray.y -= cub->player.pos.y;
		size = hypotf(cray.x, cray.y);
		size *= cosf(angle);
		if (size == 0)
			size = 1;
		draw_col(cub, x, cub->screen.height / size, &ray);
	}
}

void	update_pos(t_cub *cub, float angle, float dist)
{
	cub->player.pos.x += dist * cosf(cub->player.angle + angle);
	cub->player.pos.y += dist * sinf(cub->player.angle + angle);
}

void	move(t_cub *cub)
{
	if (cub->keys.up)
		update_pos(cub, 0, 0.2);
	if (cub->keys.down)
		update_pos(cub, M_PI, 0.1);
	if (cub->keys.left)
		update_pos(cub, -M_PI / 2, 0.15);
	if (cub->keys.right)
		update_pos(cub, M_PI / 2, 0.15);
	if (cub->keys.arrow_l)
		cub->player.angle -= M_PI / 30;
	if (cub->keys.arrow_r)
		cub->player.angle += M_PI / 30;
	if (cub->player.angle < 0)
		cub->player.angle += 2 * M_PI;
	else if (cub->player.angle >= 2 * M_PI)
		cub->player.angle -= 2 * M_PI;
}

int	render_next_frame(t_cub *cub)
{
	if (cub->tick++ < 200)
		return (0);
	draw_shit(cub);
	mlx_put_image_to_window(cub->win.mlx, cub->win.win, cub->screen.img, 0, 0);
	cub->tick = 0;
	move(cub);
	return (0);
}

static int	key_press(int keycode, t_cub *cub)
{
	if (keycode == KEY_W)
		cub->keys.up = true;
	if (keycode == KEY_S)
		cub->keys.down = true;
	if (keycode == KEY_A)
		cub->keys.left = true;
	if (keycode == KEY_D)
		cub->keys.right = true;
	if (keycode == KEY_ARROW_LEFT)
		cub->keys.arrow_l = true;
	if (keycode == KEY_ARROW_RIGHT)
		cub->keys.arrow_r = true;
	if (keycode == KEY_ECHAP)
		close_click(0, cub);
	return (0);
}

static int	key_release(int keycode, t_cub *cub)
{
	if (keycode == KEY_W)
		cub->keys.up = false;
	if (keycode == KEY_S)
		cub->keys.down = false;
	if (keycode == KEY_A)
		cub->keys.left = false;
	if (keycode == KEY_D)
		cub->keys.right = false;
	if (keycode == KEY_ARROW_LEFT)
		cub->keys.arrow_l = false;
	if (keycode == KEY_ARROW_RIGHT)
		cub->keys.arrow_r = false;
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

static void	generate_img(t_cub *c)
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
		close_click(0, c);
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

static void	hook(t_cub *cub)
{
	mlx_hook(cub->win.win, 2, 1, key_press, cub);
	mlx_hook(cub->win.win, 3, 2, key_release, cub);
	mlx_hook(cub->win.win, 17, 0, close_click, cub);
	mlx_loop_hook(cub->win.mlx, render_next_frame, cub);
	mlx_loop(cub->win.mlx);
}

void	cub3d(t_cub *cub)
{
	cub->map.map = cub->config.map;
	cub->map.width = cub->config.map_x;
	cub->map.height = cub->config.map_y;
	setup(cub);
	generate_img(cub);
	hook(cub);
}
