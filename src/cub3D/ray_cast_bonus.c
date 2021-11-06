/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 23:43:42 by mmehran           #+#    #+#             */
/*   Updated: 2021/11/06 04:53:37 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"
#include "../../header/cub_bonus.h"
#include "../../header/utils_bonus.h"

static char	next_door(const t_cub *cub, t_position *ray,
						const t_position *dir, const t_position *p)
{
	int					j;
	int					x;
	int					y;
	char				c;

	c = get_map_char2(cub, ray, p);
	if (c == 'p' || c == 'P')
	{
		x = calc_x_y(p->x, ray->x);
		y = calc_x_y(p->y, ray->y);
		j = -1;
		while (++j < cub->nb_doors)
			if (cub->doors[j].pos.x == x && cub->doors[j].pos.y == y)
				break ;
		if (c == 'p')
			next_d(ray, dir, cub->doors[j].percent_closed);
		else if (c == 'P')
			next_d2(ray, dir, cub->doors[j].percent_closed);
		c = get_map_char2(cub, ray, p);
	}
	return (c);
}

t_position	ray_cast(const t_position *p, const float angle, const t_cub *cub)
{
	const t_position	dir = {cosf(angle), sinf(angle)};
	t_position			ray;
	char				c;
	int					i;

	ray = *p;
	c = next_door(cub, &ray, &dir, p);
	i = 0;
	while (i++ < 100 && ft_isset_tab(c, "0!`@$"))
	{
		next(&ray, &dir);
		c = next_door(cub, &ray, &dir, p);
	}
	return (ray);
}
