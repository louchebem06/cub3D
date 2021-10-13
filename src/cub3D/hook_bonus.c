/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 13:12:38 by bledda            #+#    #+#             */
/*   Updated: 2021/10/13 14:14:18 by bledda           ###   ########.fr       */
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
	{
		free_cub(cub);
		close_click(0, cub);
	}
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

static int	move_mouse(int x, int y, t_cub *cub)
{
	static int xx = WINDOWS_WIDTH/2;
	static int yy = WINDOWS_HEIGHT / 2;
	printf("x:%d\ny:%d\n", x, y);
	(void)yy;
	if (xx >= 0 && xx <= WINDOWS_WIDTH)
	{
		if (xx < WINDOWS_WIDTH / 2)
		{
			cub->keys.arrow_r = true;
			cub->keys.arrow_l = false;
		}
		else
		{
			cub->keys.arrow_l = true;
			cub->keys.arrow_r = false;
		}
	}
	else
	{
		cub->keys.arrow_l = false;
		cub->keys.arrow_r = false;
	}
	return (0);
}

static int	click_mouse(int button, int x, int y, t_cub *cub)
{
	(void)cub;
	printf("button:%d\nx:%d\ny:%d\n", button, x, y);
	return (0);
}

void	hook(t_cub *cub)
{
	mlx_hook(cub->win.win, 2, 1, key_press, cub);
	mlx_hook(cub->win.win, 3, 2, key_release, cub);
	mlx_hook(cub->win.win, 17, 0, close_click, cub);
	mlx_hook(cub->win.win, 6, 0, move_mouse, cub);
	mlx_mouse_hook(cub->win.win, click_mouse, cub);
	mlx_loop_hook(cub->win.mlx, render_next_frame, cub);
	mlx_loop(cub->win.mlx);
}
