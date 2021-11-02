/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:46:39 by bledda            #+#    #+#             */
/*   Updated: 2021/11/02 13:48:28 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/sprite_bonus.h"

float	ft_dot(t_position a, t_position b)
{
	return (a.x * b.x + a.y * b.y);
}

void	update_sprites_dist(t_position *p, t_item_sprite *config, int item)
{
	int	i;

	i = -1;
	while (++i < item)
	{
		config[i].dist = hypotf(p->x - config[i].pos.x,
				p->y - config[i].pos.y);
	}
}

void	sort_sprite(t_item_sprite *config, int item)
{
	t_item_sprite	temp;
	int				i;
	int				j;

	j = -1;
	while (++j + 1 < item)
	{
		i = -1;
		while (++i + j + 1 < item)
		{
			if (config[i + 1].dist > config[i].dist)
			{
				temp = config[i + 1];
				config[i + 1] = config[i];
				config[i] = temp;
			}
		}
	}
}
