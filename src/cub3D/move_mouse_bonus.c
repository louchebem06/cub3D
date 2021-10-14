/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_mouse_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 03:19:38 by bledda            #+#    #+#             */
/*   Updated: 2021/10/14 03:58:51 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/mouse_bonus.h"

#ifdef __APPLE__

int	move_mouse(int x, int y, t_cub *cub)
{
	if (x < 0 || y < 0 || y > WINDOWS_HEIGHT || x > WINDOWS_WIDTH)
	{
		mlx_mouse_show();
		return (0);
	}
	if (x < WINDOWS_WIDTH / 2)
		cub->player.angle -= M_PI / 30;
	else if (x > WINDOWS_WIDTH / 2)
		cub->player.angle += M_PI / 30;
	mlx_mouse_move(cub->win.win, WINDOWS_WIDTH / 2, WINDOWS_HEIGHT / 2);
	mlx_mouse_hide();
	return (0);
}
#elif __linux__

void	move_mouse(t_cub *cub)
{
	int	x;
	int	y;

	mlx_mouse_get_pos(cub->win.mlx, cub->win.win, &x, &y);
	if (x < 0 || y < 0 || y > WINDOWS_HEIGHT || x > WINDOWS_WIDTH)
	{
		mlx_mouse_show(cub->win.mlx, cub->win.win);
		return ;
	}
	if (x < WINDOWS_WIDTH / 2)
		cub->player.angle -= M_PI / 25;
	else if (x > WINDOWS_WIDTH / 2)
		cub->player.angle += M_PI / 25;
	mlx_mouse_move(cub->win.mlx, cub->win.win,
		WINDOWS_WIDTH / 2, WINDOWS_HEIGHT / 2);
	mlx_mouse_hide(ub->win.mlx, cub->win.win);
}
#endif
