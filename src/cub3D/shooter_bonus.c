/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shooter_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 04:35:52 by bledda            #+#    #+#             */
/*   Updated: 2021/10/17 19:37:40 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/shooter_bonus.h"

static void	print_pointer(t_cub *cub, int color)
{
	int	x;
	int	y;

	y = -1;
	while (++y < 10)
	{
		x = -1;
		while (++x < 10)
			if (hypotf(x - 5, y - 5) <= 4)
				mlx_put_pixel_to_img(&cub->screen, WINDOWS_WIDTH / 2 + x,
					WINDOWS_HEIGHT / 2 + y, color);
	}
}

static t_img	*get_shooter(t_cub *cub, int img)
{
	if (img == 1)
		return (&cub->shooter.viser);
	else if (img == 2)
		return (&cub->shooter.tirer);
	else if (img == 3)
		return (&cub->shooter.viser_tirer);
	return (&cub->shooter.first);
}

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
	if (button == 1)
		btn1 = state;
	if (button == 2)
		btn2 = state;
	return (0);
}

void	shooter(t_cub *cub)
{
	const int	img = toggle_mouse(0, 0, 0);
	const t_img	*shooter = get_shooter(cub, img);

	print_pointer(cub, create_trgb(0, 255, 0, 0));
	if (img == 3 || img == 1)
		mlx_put_img_to_img(&cub->screen, shooter,
			(WINDOWS_WIDTH / 2) - (shooter->width / 2),
			WINDOWS_HEIGHT - shooter->height);
	else
		mlx_put_img_to_img(&cub->screen, shooter,
			WINDOWS_WIDTH / 1.5, WINDOWS_HEIGHT - shooter->height);
	toggle_mouse(cub, 1, false);
}
