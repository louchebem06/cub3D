/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 23:59:13 by bledda            #+#    #+#             */
/*   Updated: 2021/11/02 17:31:24 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/sprite_bonus.h"

static bool	calc_value(t_cub *cub, t_calc_sprite *var)
{
	var->p = &cub->player;
	var->sprite_pos = cub->sprite.config[var->i].pos;
	var->dsprite = (t_position){
		var->sprite_pos.x - var->p->pos.x, var->sprite_pos.y - var->p->pos.y};
	var->dist = hypotf(var->dsprite.x, var->dsprite.y);
	var->dir = (t_position){
		cosf(cub->player.angle), sinf(cub->player.angle)};
	var->dot = \
		(var->dir.x * var->dsprite.x + var->dir.y * var->dsprite.y) / var->dist;
	var->s_angle = atan2f(var->dsprite.y, var->dsprite.x);
	var->p_angle = var->p->angle;
	var->diff_angle = var->s_angle + 2 * M_PI - var->p_angle;
	var->udsprite = (t_position){
		var->dsprite.x / var->dist, var->dsprite.y / var->dist};
	var->toast_p = (0.6 * tanf(var->diff_angle)) + 0.5;
	if (var->dot <= 0)
		return (true);
	if (var->toast_p <= -0.1 || var->toast_p >= 1.1)
		return (true);
	return (false);
}

static void	anim_doll(unsigned long long *time,
							const unsigned long long diff_time,
							int *img, bool *move)
{
	if (!*time
		|| (*img == 5 && diff_time > 1000)
		|| (*img != 5 && diff_time > 150))
	{
		*time = ft_get_current_time();
		if (!*move)
			*img += 2;
		if (--*img == 0)
			*move = false;
		else if (*img == 5)
			*move = true;
	}
}

static inline float	calc_scale(const t_calc_sprite var)
{
	return (((WW / 1.69f) / var.s->width)
		/ (var.dist * ft_dot(var.dir, var.udsprite)));
}

static inline t_position	calc_center(const t_calc_sprite var)
{
	return ((t_position){
		(WW) * var.toast_p,
		(WH / 2) - (var.send.scale * var.s->height) / 2
		+ (WH / 2) / (var.dist * ft_dot(var.dir, var.udsprite))});
}

void	sprite(t_cub *cub)
{
	static unsigned long long	time = 0;
	const unsigned long long	diff_time = ft_get_current_time() - time;
	static int					img = 0;
	static bool					move = false;
	t_calc_sprite				var;

	update_sprites_dist(&cub->player.pos, cub->sprite.config, cub->sprite.item);
	sort_sprite(cub->sprite.config, cub->sprite.item);
	var = (t_calc_sprite){0};
	var.i = -1;
	while (++var.i < cub->sprite.item)
	{
		if (calc_value(cub, &var))
			continue ;
		var.s = cub->sprite.config[var.i].s;
		if (!var.s)
		{
			anim_doll(&time, diff_time, &img, &move);
			var.s = cub->sprite.config[var.i].s_anim[img];
		}
		var.send.scale = calc_scale(var);
		var.send.center = calc_center(var);
		var.send.dist = var.dist;
		put_sprite(cub, var.s, var.send);
	}
}
