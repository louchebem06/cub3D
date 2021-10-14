/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_next_frame_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:26:08 by bledda            #+#    #+#             */
/*   Updated: 2021/10/14 00:04:18 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"
#include "../../header/minimap_bonus.h"

static float	distance(t_position *p1, t_position *p2)
{
	return (hypotf(p1->x - p2->x, p1->y - p2->y));
}

static void	update_pos(t_cub *cub, float angle, float dist)
{
	const float	cos = cosf(cub->player.angle + angle);
	const float	sin = sinf(cub->player.angle + angle);
	t_position	ray;

	ray = ray_cast(&cub->player.pos, cub->player.angle + angle, &cub->map);
	if (distance(&cub->player.pos, &ray) > dist)
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
}

int	render_next_frame(t_cub *cub)
{
	if (cub->tick++ < 200)
		return (0);
	move(cub);
	draw(cub);
	minimap(cub);
	mlx_put_image_to_window(cub->win.mlx, cub->win.win, cub->screen.img, 0, 0);
	cub->tick = 0;
	return (0);
}
