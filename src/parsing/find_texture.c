/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 18:06:44 by bledda            #+#    #+#             */
/*   Updated: 2021/11/05 12:02:45 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/ft_config_bonus.h"
#include "../../header/cub_bonus.h"
#include "../../header/queue_bonus.h"

static char	find_the_closest_texture(t_config *config,
									t_position *edges, char **map, t_queue **q)
{
	int			i;
	t_position	w;

	i = -1;
	while (++i < 8)
	{
		w = edges[i];
		if (w.x < 0 || w.y < 0
			|| w.x >= config->map_x || w.y >= config->map_y)
			continue ;
		if (ft_isset_tab(map[(int)w.y][(int)w.x], "0!`@$"))
		{
			return (map[(int)w.y][(int)w.x]);
		}
		if (ft_isset_tab(map[(int)w.y][(int)w.x], "NSEWLpPOFHI|A"))
		{
			map[(int)w.y][(int)w.x] = '?';
			push_queue(q[0], w);
			push_queue(q[1], w);
		}
	}
	return ('0');
}

static void	replace_texture(t_queue *q, char result, char **map)
{
	t_position	p;

	while (q->head)
	{
		p = pop_queue(q);
		map[(int)p.y][(int)p.x] = result;
	}
}

void	find_texture(t_cub *cub, char **map, int x, int y)
{
	char		result;
	t_queue		*q[2];
	t_position	e;
	t_position	edges[8];

	result = '0';
	q[0] = create_queue();
	q[1] = create_queue();
	push_queue(q[0], (t_position){x, y});
	push_queue(q[1], (t_position){x, y});
	map[y][x] = '?';
	while (q[0]->head)
	{
		e = pop_queue(q[0]);
		ft_memcpy(&edges, (t_position []){{e.x + 1, e.y}, {e.x, e.y + 1},
		{e.x - 1, e.y}, {e.x, e.y - 1}, {e.x + 1, e.y + 1}, {e.x - 1, e.y - 1},
		{e.x - 1, e.y + 1}, {e.x + 1, e.y - 1}}, sizeof(edges));
		result = find_the_closest_texture(&cub->config, edges, map, q);
	}
	replace_texture(q[1], result, map);
	destroy_queue(q[0]);
	destroy_queue(q[1]);
}
