/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shooter_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 04:35:52 by bledda            #+#    #+#             */
/*   Updated: 2021/10/22 02:38:18 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/shooter_bonus.h"
#include "../../header/sound_bonus.h"

#ifdef __APPLE__

const int	g_btn = 2;
#elif __linux__

const int	g_btn = 3;
#endif

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

static t_img	*get_anim(t_cub *cub)
{
	static long int	first = 0;
	static int		anim = 0;
	long int		cmp;

	if (!cub->keys.r)
		return (NULL);
	cmp = ft_get_current_time();
	if (anim == 0)
		toggle(&cub->sound.recharge, true);
	if (cmp - first > 400 && anim++)
		first = ft_get_current_time();
	if (anim == 1)
		return (&cub->shooter.recharge1);
	else if (anim == 2)
		return (&cub->shooter.recharge2);
	else if (anim == 3)
		return (&cub->shooter.recharge3);
	else if (anim == 4)
		return (&cub->shooter.recharge2);
	else if (anim == 5)
		return (&cub->shooter.recharge1);
	anim = 0;
	cub->keys.r = false;
	return (NULL);
}

static t_img	*get_shooter(t_cub *cub, int img)
{
	t_img	*anim;

	anim = get_anim(cub);
	if (anim)
		return (anim);
	if (img == 1)
		return (&cub->shooter.viser);
	else if (img == 2)
	{
		toggle(&cub->sound.tir, true);
		return (&cub->shooter.tirer);
	}
	else if (img == 3)
	{
		toggle(&cub->sound.tir, true);
		return (&cub->shooter.viser_tirer);
	}
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
	if (button == g_btn)
		btn2 = state;
	return (0);
}

void	shooter(t_cub *cub)
{
	const int		img = toggle_mouse(0, 0, 0);
	const t_img		*s = get_shooter(cub, img);
	static long int	first = 0;
	const long int	cmp = ft_get_current_time();
	static bool		move = false;

	print_pointer(cub, create_trgb(0, 89, 150, 189));
	if (!cub->keys.r && (img == 3 || img == 1))
	{
		mlx_put_img_to_img(&cub->screen, s,
			WW / 2 - (s->width - 47) / 2, WH - s->height);
		toggle_mouse(cub, 1, false);
		return ;
	}
	else if ((ismove(cub) && cmp - first >= 200)
		|| (!ismove(cub) && cmp - first >= 500) || first == 0)
	{
		first = ft_get_current_time();
		move = !move;
	}
	if (move && ismove(cub))
		mlx_put_img_to_img(&cub->screen, s, WW / 1.55, WH - s->height + 47);
	else if (move)
		mlx_put_img_to_img(&cub->screen, s, WW / 1.5, WH - s->height + 57);
	else
		mlx_put_img_to_img(&cub->screen, s, WW / 1.5, WH - s->height + 47);
	toggle_mouse(cub, 1, false);
}
