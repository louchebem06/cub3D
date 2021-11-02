/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 03:49:21 by bledda            #+#    #+#             */
/*   Updated: 2021/11/02 13:14:23 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"
#include "../../header/mouse_bonus.h"
#include "../../header/sound_bonus.h"
#include "../../header/shooter_bonus.h"
#include "../../header/cub_bonus.h"

static int	close_click(int keycode, t_cub *cub)
{
	(void) cub;
	(void) keycode;
	exit(0);
	return (0);
}

static int	key_press(int keycode, t_cub *cub)
{
	if (!cub->no_intro)
		return (0);
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
	if (keycode == KEY_R)
		cub->keys.r = true;
	if (keycode == KEY_ECHAP)
	{
		free_image(cub);
		free_sound(cub);
		free_cub(cub);
		fps(NULL);
		close_click(0, cub);
	}
	return (0);
}

static int	key_release(int keycode, t_cub *cub)
{
	if (!cub->no_intro)
		return (0);
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

#ifdef __APPLE__

void	hook(t_cub *cub)
{
	mlx_hook(cub->win.win, 2, 1, key_press, cub);
	mlx_hook(cub->win.win, 3, 2, key_release, cub);
	mlx_hook(cub->win.win, 17, 0, close_click, cub);
	mlx_hook(cub->win.win, 6, 0, move_mouse, cub);
	mlx_hook(cub->win.win, 5, 0, mouse_unclick, cub);
	mlx_mouse_hook(cub->win.win, mouse_hook, cub);
	mlx_loop_hook(cub->win.mlx, render_next_frame, cub);
	mlx_loop(cub->win.mlx);
}

#elif __linux__

void	hook(t_cub *cub)
{
	mlx_hook(cub->win.win, 2, 1, key_press, cub);
	mlx_hook(cub->win.win, 3, 2, key_release, cub);
	mlx_hook(cub->win.win, 7, 1l << 4, enter_mouse_windows, cub);
	mlx_hook(cub->win.win, 8, 1l << 5, leave_mouse_windows, cub);
	mlx_hook(cub->win.win, 17, 0, close_click, cub);
	mlx_hook(cub->win.win, 5, 1l << 3, mouse_unclick, cub);
	mlx_mouse_hook(cub->win.win, mouse_hook, cub);
	mlx_loop_hook(cub->win.mlx, render_next_frame, cub);
	mlx_loop(cub->win.mlx);
}
#endif
