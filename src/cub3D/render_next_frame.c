/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_next_frame.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 00:30:13 by mmehran           #+#    #+#             */
/*   Updated: 2021/10/13 17:27:41 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

static void	update_pos(t_cub *cub, float angle, float dist)
{
	cub->player.pos.x += dist * cosf(cub->player.angle + angle);
	cub->player.pos.y += dist * sinf(cub->player.angle + angle);
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
}

int	render_next_frame(t_cub *cub)
{
	if (cub->tick++ < 200)
		return (0);
	move(cub);
	draw(cub);
	mlx_put_image_to_window(cub->win.mlx, cub->win.win, cub->screen.img, 0, 0);
	cub->tick = 0;
	return (0);
}
