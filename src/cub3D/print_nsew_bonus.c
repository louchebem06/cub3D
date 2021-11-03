/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nsew_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 17:07:05 by bledda            #+#    #+#             */
/*   Updated: 2021/11/03 17:16:48 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minimap_bonus.h"

static void	ft_step1(float *inertia, bool *move, bool *step1, bool *step2)
{
	if (!*move && *inertia < 0.5f)
		*inertia += 0.1f;
	else if (*move && *inertia > -0.5f)
		*inertia -= 0.1f;
	else
	{
		*step1 = false;
		*step2 = true;
	}
}

static void	ft_step2(float *inertia, bool *step2)
{
	if (*inertia > 0.09f)
		*inertia -= 0.1f;
	else if (*inertia < -0.09f)
		*inertia += 0.1f;
	else
		*step2 = false;
}

static float	ft_inertia(float player_angle)
{
	static float	angle = -1;
	static float	inertia = 0;
	static bool		move = false;
	static bool		step1 = false;
	static bool		step2 = false;

	if (angle == -1)
		angle = player_angle;
	if (!step1 && !step2 && angle != player_angle)
	{
		step1 = true;
		move = (angle > player_angle);
	}
	else if (angle == player_angle && step1 && !step2)
		ft_step1(&inertia, &move, &step1, &step2);
	else if (angle == player_angle && !step1 && step2)
		ft_step2(&inertia, &step2);
	angle = player_angle;
	return (inertia);
}

static inline t_position	direction(t_position ray,
										t_position pos, float value)
{
	return ((t_position){
		pos.x * cosf(value) + pos.y * sinf(value) + ray.x,
		-pos.x * sinf(value) + pos.y * cosf(value) + ray.y});
}

void	print_nsew(t_cub *cub, int const x, int const y)
{
	const int			color = create_trgb(0, 255, 255, 255);
	const t_position	ray = {x + 95, y + 105};
	const t_position	pos = {x + 95 - ray.x, y + 5 - ray.y};
	const float			inertia = ft_inertia(cub->player.angle);
	const t_position	dir[8] = {
		direction(ray, pos, cub->player.angle + inertia + M_PI / 2),
		direction(ray, pos, cub->player.angle + inertia - M_PI / 2),
		direction(ray, pos, cub->player.angle + inertia - M_PI),
		direction(ray, pos, cub->player.angle + inertia),
		direction(ray, pos, cub->player.angle + inertia + M_PI / 4),
		direction(ray, pos, cub->player.angle + inertia - M_PI / 4),
		direction(ray, pos, cub->player.angle + inertia - M_PI * 0.75),
		direction(ray, pos, cub->player.angle + inertia + M_PI * 0.75)
	};

	mlx_string_put(cub->win.mlx, cub->win.win, dir[0].x, dir[0].y, color, "N");
	mlx_string_put(cub->win.mlx, cub->win.win, dir[1].x, dir[1].y, color, "S");
	mlx_string_put(cub->win.mlx, cub->win.win, dir[2].x, dir[2].y, color, "W");
	mlx_string_put(cub->win.mlx, cub->win.win, dir[3].x, dir[3].y, color, "E");
	mlx_string_put(cub->win.mlx, cub->win.win, dir[4].x, dir[4].y, color, "NE");
	mlx_string_put(cub->win.mlx, cub->win.win, dir[5].x, dir[5].y, color, "SE");
	mlx_string_put(cub->win.mlx, cub->win.win, dir[6].x, dir[6].y, color, "SW");
	mlx_string_put(cub->win.mlx, cub->win.win, dir[7].x, dir[7].y, color, "NW");
}
