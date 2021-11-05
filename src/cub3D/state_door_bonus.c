/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_door_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 14:28:02 by bledda            #+#    #+#             */
/*   Updated: 2021/11/05 15:38:56 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub_bonus.h"

static inline float	distance(const t_position *a, const t_position *b)
{
	return (hypotf(a->x - b->x, a->y - b->y));
}

void	state_door(t_cub *cub)
{
	float	dist;
	int		i;

	i = -1;
	while (++i < cub->nb_doors)
	{
		dist = distance(&cub->player.pos, &cub->doors[i].pos);
		if (dist >= 2.0f)
		{
			if (cub->doors[i].percent_closed < 1.0f)
				cub->doors[i].percent_closed += 0.1f;
		}
		else
		{
			if (cub->doors[i].percent_closed > 0.0f)
				cub->doors[i].percent_closed -= 0.1f;
		}
	}
}
