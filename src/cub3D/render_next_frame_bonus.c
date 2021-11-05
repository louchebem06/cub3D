/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_next_frame_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:26:08 by bledda            #+#    #+#             */
/*   Updated: 2021/11/05 14:27:48 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"
#include "../../header/minimap_bonus.h"
#include "../../header/mouse_bonus.h"
#include "../../header/shooter_bonus.h"
#include "../../header/sound_bonus.h"
#include "../../header/sprite_bonus.h"
#include "../../header/utils_bonus.h"
#include "../../header/cub_bonus.h"

static const int	g_minimap_x = 15;
static const int	g_minimap_y = WINDOWS_HEIGHT - 215;

static void	update_pos(t_cub *cub, float angle, float dist)
{
	const float	cos = cosf(cub->player.angle + angle);
	const float	sin = sinf(cub->player.angle + angle);
	t_position	ray;

	ray = ray_cast(&cub->player.pos, cub->player.angle + angle, cub);
	if (hypotf(cub->player.pos.x - ray.x, cub->player.pos.y - ray.y) > dist)
	{
		cub->player.pos.x += cos * dist;
		cub->player.pos.y += sin * dist;
	}
	else
	{
		cub->player.pos = ray;
		cub->player.pos.x -= cos * 0.01;
		cub->player.pos.y -= sin * 0.01;
	}
}

static void	move(t_cub *cub)
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
	if (cub->keys.up || cub->keys.down || cub->keys.left || cub->keys.right)
		toggle(&cub->sound.step_classic, false);
}

static void	play_intro(t_cub *cub, int i)
{
	mlx_put_image_to_window(cub->win.mlx, cub->win.win,
		cub->intro[i].img, 0, 0);
	mlx_destroy_image(cub->win.mlx, cub->intro[i].img);
	usleep((1000 / 15.0f) * 1000);
}

#ifdef __linux__

int	render_next_frame(t_cub *cub)
{
	static int	i = -1;

	if (cub->no_intro || i == IMG_INTRO)
	{
		cub->no_intro = true;
		if (ft_get_current_time() - cub->last_f < 1000.0 / 60.0)
			return (0);
		cub->last_f = ft_get_current_time();
		move(cub);
		draw(cub);
		state_door(cub);
		sprite(cub);
		move_mouse(cub);
		shooter(cub);
		minimap(cub, g_minimap_x, g_minimap_y);
		mlx_put_image_to_window(cub->win.mlx, cub->win.win,
			cub->screen.img, 0, 0);
		print_nsew(cub, g_minimap_x, g_minimap_y);
		fps(cub);
		print_balle(cub);
		sound_dolls(cub);
	}
	else if (++i < IMG_INTRO)
		play_intro(cub, i);
	return (0);
}
#elif __APPLE__

int	render_next_frame(t_cub *cub)
{
	static int	i = -1;

	if (cub->no_intro || i == IMG_INTRO)
	{
		cub->no_intro = true;
		if (ft_get_current_time() - cub->last_f < 1000.0 / 60.0)
			return (0);
		cub->last_f = ft_get_current_time();
		move(cub);
		draw(cub);
		state_door(cub);
		sprite(cub);
		shooter(cub);
		minimap(cub, g_minimap_x, g_minimap_y);
		mlx_put_image_to_window(cub->win.mlx,
			cub->win.win, cub->screen.img, 0, 0);
		print_nsew(cub, g_minimap_x, g_minimap_y);
		fps(cub);
		print_balle(cub);
		mlx_do_sync(cub->win.mlx);
		sound_dolls(cub);
	}
	else if (++i < IMG_INTRO)
		play_intro(cub, i);
	return (0);
}
#endif
