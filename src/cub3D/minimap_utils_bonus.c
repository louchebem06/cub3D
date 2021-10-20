/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 03:25:08 by bledda            #+#    #+#             */
/*   Updated: 2021/10/20 04:04:23 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minimap_bonus.h"

static void	print_dir(t_cub *cub, const t_position dir[4],
						const t_position dir2[4], const int color)
{
	mlx_string_put(cub->win.mlx, cub->win.win, dir[0].x, dir[0].y, color, "N");
	mlx_string_put(cub->win.mlx, cub->win.win, dir[1].x, dir[1].y, color, "S");
	mlx_string_put(cub->win.mlx, cub->win.win, dir[2].x, dir[2].y, color, "W");
	mlx_string_put(cub->win.mlx, cub->win.win, dir[3].x, dir[3].y, color, "E");
	mlx_string_put(cub->win.mlx, cub->win.win,
		dir2[0].x, dir2[0].y, color, "NE");
	mlx_string_put(cub->win.mlx, cub->win.win,
		dir2[1].x, dir2[1].y, color, "SE");
	mlx_string_put(cub->win.mlx, cub->win.win,
		dir2[2].x, dir2[2].y, color, "SW");
	mlx_string_put(cub->win.mlx, cub->win.win,
		dir2[3].x, dir2[3].y, color, "NW");
}

/*
	NE
	SE
	SW
	NW
*/
static void	const2(t_cub *cub, const t_position ray, const t_position pos,
						const t_position dir[4])
{
	const int			color = create_trgb(0, 255, 255, 255);
	const t_position	dir2[4] = {
		{pos.x * cos(cub->player.angle + M_PI / 4)
			+ pos.y * sin(cub->player.angle + M_PI / 4) + ray.x,
		-pos.x * sin(cub->player.angle + M_PI / 4)
			+ pos.y * cos(cub->player.angle + M_PI / 4) + ray.y},

		{pos.x * cos(cub->player.angle - M_PI / 4)
			+ pos.y * sin(cub->player.angle - M_PI / 4) + ray.x,
		-pos.x * sin(cub->player.angle - M_PI / 4)
			+ pos.y * cos(cub->player.angle - M_PI / 4) + ray.y},

		{pos.x * cos(cub->player.angle - M_PI / 1.33)
			+ pos.y * sin(cub->player.angle - M_PI / 1.33) + ray.x,
		-pos.x * sin(cub->player.angle - M_PI / 1.33)
			+ pos.y * cos(cub->player.angle - M_PI / 1.33) + ray.y},

		{pos.x * cos(cub->player.angle + M_PI / 1.33)
			+ pos.y * sin(cub->player.angle + M_PI / 1.33) + ray.x,
		-pos.x * sin(cub->player.angle + M_PI / 1.33)
			+ pos.y * cos(cub->player.angle + M_PI / 1.33) + ray.y}};

	print_dir(cub, dir, dir2, color);
}

/*
	N
	S
	W
	E
*/
void	print_nsew(t_cub *cub, int const x, int const y)
{
	const t_position	ray = {x + 95, y + 105};
	const t_position	pos = {x + 95 - ray.x, y + 5 - ray.y};
	const t_position	dir[4] = {
		{pos.x * cos(cub->player.angle + M_PI / 2)
			+ pos.y * sin(cub->player.angle + M_PI / 2) + ray.x,
		-pos.x * sin(cub->player.angle + M_PI / 2)
			+ pos.y * cos(cub->player.angle + M_PI / 2) + ray.y},

		{pos.x * cos(cub->player.angle - M_PI / 2)
			+ pos.y * sin(cub->player.angle - M_PI / 2) + ray.x,
		-pos.x * sin(cub->player.angle - M_PI / 2)
			+ pos.y * cos(cub->player.angle - M_PI / 2) + ray.y},

		{pos.x * cos(cub->player.angle - M_PI)
			+ pos.y * sin(cub->player.angle - M_PI) + ray.x,
		-pos.x * sin(cub->player.angle - M_PI)
			+ pos.y * cos(cub->player.angle - M_PI) + ray.y},

		{pos.x * cos(cub->player.angle)
			+ pos.y * sin(cub->player.angle) + ray.x,
		-pos.x * sin(cub->player.angle)
			+ pos.y * cos(cub->player.angle) + ray.y}};

	const2(cub, ray, pos, dir);
}
