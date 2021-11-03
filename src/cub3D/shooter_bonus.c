/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shooter_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 04:35:52 by bledda            #+#    #+#             */
/*   Updated: 2021/11/03 14:39:14 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/shooter_bonus.h"
#include "../../header/sound_bonus.h"
#include "../../header/cub_bonus.h"
#include "../../header/mouse_bonus.h"

static void	print_pointer(t_cub *cub, int color)
{
	int	x;
	int	y;

	y = -1;
	while (++y < 10)
	{
		x = -1;
		while (++x < 10)
			if (hypotf(x - 5, y - 5) < 5)
				mlx_put_pixel_to_img(&cub->screen, WINDOWS_WIDTH / 2 + x,
					WINDOWS_HEIGHT / 2 + y, color);
	}
}

static bool	update_balle(t_cub *cub, bool recharge, int img)
{
	if (!recharge)
		return (false);
	else if (cub->shooter.reserve == 0)
	{
		cub->keys.r = false;
		return (false);
	}
	while (img == 0 && cub->shooter.balle != VAL_CHAR
		&& cub->shooter.reserve != 0)
	{
		cub->shooter.reserve--;
		cub->shooter.balle++;
	}
	return (true);
}

static t_img	*get_anim(t_cub *cub)
{
	static long int	first = 0;
	static int		anim = 0;
	long int		cmp;

	if (!update_balle(cub, cub->keys.r, anim))
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
	else if (img == 2 && cub->shooter.balle > 0)
	{
		cub->shooter.balle--;
		toggle(&cub->sound.tir, true);
		return (&cub->shooter.tirer);
	}
	else if (img == 3 && cub->shooter.balle > 0)
	{
		cub->shooter.balle--;
		toggle(&cub->sound.tir, true);
		return (&cub->shooter.viser_tirer);
	}
	if (img == 3 || img == 1)
		return (&cub->shooter.viser);
	return (&cub->shooter.first);
}

void	shooter(t_cub *cub)
{
	const int		img = toggle_mouse(0, 0, 0);
	const t_img		*s = get_shooter(cub, img);
	static long int	f = 0;
	const long int	c = ft_get_current_time();
	static bool		move = false;

	print_pointer(cub, create_trgb(0, 89, 150, 189));
	if (!f || (ismove(cub) && c - f >= 200) || (!ismove(cub) && c - f >= 500))
	{
		f = ft_get_current_time();
		move = !move;
	}
	if (!cub->keys.r && (img == 3 || img == 1))
		mlx_put_img_to_img(&cub->screen, s,
			WW / 2 - (s->width - 47) / 2, WH - s->height);
	else if (move && ismove(cub))
		mlx_put_img_to_img(&cub->screen, s,
			WW - s->height - (s->height / 2) - 20, WH - s->height + 47);
	else if (move)
		mlx_put_img_to_img(&cub->screen, s,
			WW - s->height - (s->height / 2), WH - s->height + 57);
	else
		mlx_put_img_to_img(&cub->screen, s,
			WW - s->height - (s->height / 2), WH - s->height + 47);
	toggle_mouse(cub, 1, false);
}
