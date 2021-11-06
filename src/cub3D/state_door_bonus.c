/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_door_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 14:28:02 by bledda            #+#    #+#             */
/*   Updated: 2021/11/06 04:59:19 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub_bonus.h"
#include "../../header/sound_bonus.h"

static inline float	distance(const t_position *a, const t_position *b)
{
	return (hypotf(a->x - b->x, a->y - b->y));
}

void	state_door(t_cub *cub)
{
	int		i;
	bool	last_state;

	i = -1;
	while (++i < cub->nb_doors)
	{
		last_state = cub->doors[i].closed;
		if (distance(&cub->player.pos, &cub->doors[i].pos) > 2)
		{
			if (cub->doors[i].percent_closed < 1)
				cub->doors[i].percent_closed += 0.01;
			else
				cub->doors[i].closed = true;
		}
		else
		{
			if (cub->doors[i].percent_closed > 0)
				cub->doors[i].percent_closed -= 0.01;
			else
				cub->doors[i].closed = false;
		}
		if (last_state != cub->doors[i].closed)
			toggle(&cub->sound.door, true);
	}
}
