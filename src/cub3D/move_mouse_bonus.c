/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_mouse_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 03:19:38 by bledda            #+#    #+#             */
/*   Updated: 2021/11/04 22:54:53 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/mouse_bonus.h"
#include "../../header/cub_bonus.h"

int	toggle_mouse(t_cub *cub, int button, bool state)
{
	static bool	btn1 = false;
	static bool	btn2 = false;

	if (!cub)
	{
		if (btn1 && btn2)
			return (3);
		else if (btn1)
			return (2);
		else if (btn2)
			return (1);
	}
	if (button == BTN1)
		btn1 = state;
	else if (button == BTN2)
		btn2 = state;
	return (0);
}

int	mouse_hook(int button, int x, int y, t_cub *cub)
{
	(void)x;
	(void)y;
	toggle_mouse(cub, button, true);
	return (0);
}

int	mouse_unclick(int button, t_cub *cub)
{
	toggle_mouse(cub, button, false);
	return (0);
}

#ifdef __APPLE__

int	move_mouse(int x, int y, t_cub *cub)
{
	const float	move = (fmaxf((float)(x), (float)(WW / 2))
		- fminf((float)(x), (float)(WW / 2))) / 500.0f;

	if (!cub->no_intro || y < 100
		|| x <= 100 || y >= WINDOWS_HEIGHT - 100 || x >= WINDOWS_WIDTH - 100)
	{
		mlx_mouse_show();
		return (0);
	}
	if (x < WINDOWS_WIDTH / 2)
		cub->player.angle -= move;
	else if (x > WINDOWS_WIDTH / 2)
		cub->player.angle += move;
	mlx_mouse_move(cub->win.win, WINDOWS_WIDTH / 2, WINDOWS_HEIGHT / 2);
	mlx_mouse_hide();
	return (0);
}
#elif __linux__

void	move_mouse(t_cub *cub)
{
	int		x;
	int		y;
	float	move;

	if (!cub->mouse_in_windows)
		return ;
	mlx_mouse_get_pos(cub->win.mlx, cub->win.win, &x, &y);
	move = (fmaxf((float)(x), (float)(WW / 2))
			- fminf((float)(x), (float)(WW / 2))) / 500.0f;
	if (!cub->no_intro || y < 0)
		return ;
	if (x < WINDOWS_WIDTH / 2)
		cub->player.angle -= move;
	else if (x > WINDOWS_WIDTH / 2)
		cub->player.angle += move;
	mlx_mouse_move(cub->win.mlx, cub->win.win,
		WINDOWS_WIDTH / 2, WINDOWS_HEIGHT / 2);
	mlx_mouse_hide(cub->win.mlx, cub->win.win);
}
#endif
