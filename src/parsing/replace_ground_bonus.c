/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_ground_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 00:53:49 by bledda            #+#    #+#             */
/*   Updated: 2021/10/30 13:57:31 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/ft_config_bonus.h"
#include "../../header/cub_bonus.h"
#include "../../header/queue_bonus.h"

static int	max(const int *tab, const int size)
{
	int	tmp;
	int	i;

	tmp = 0;
	i = 0;
	while (++i < size)
	{
		if (tab[tmp] < tab[i])
			tmp = i;
	}
	return (tmp);
}

static char	floor_texture(char **map, int x, int y)
{
	const char	c[8] = {map[y - 1][x - 1], map[y - 1][x], map[y - 1][x + 1],
		map[y][x - 1], map[y][x + 1], map[y + 1][x - 1], map[y + 1][x],
		map[y + 1][x + 1]};
	const char	ground[5] = "0!`@$";
	int			choose[5];
	int			i;
	int			j;

	i = -1;
	while (++i < 5)
		choose[i] = 0;
	i = -1;
	while (++i < 8)
	{
		j = -1;
		while (++j < 5)
		{
			if (c[i] == ground[j])
				choose[j]++;
		}
	}
	return (ground[max(choose, 5)]);
}

static void	map_sprite(t_cub *cub, char **map)
{
	const char	set[] = "NSEW";
	int			y;
	int			x;
	int			i;

	cub->config.map_s = ft_calloc(sizeof(char *), cub->config.map_y + 1);
	y = -1;
	while (++y < cub->config.map_y)
		cub->config.map_s[y] = ft_strdup(map[y]);
	y = -1;
	while (cub->config.map_s[++y])
	{
		x = -1;
		while (cub->config.map_s[y][++x])
		{
			i = -1;
			while (set[++i])
			{
				if (cub->config.map_s[y][x] == set[i])
					cub->config.map_s[y][x] = \
						floor_texture(cub->config.map_s, x, y);
			}
		}
	}
}

static void	find_nearest(t_cub *cub, char **map, int x, int y)
{

	char	result = '0';
	t_queue	*qseen = create_queue();
	t_queue	*q = create_queue();
	push_queue(q, (t_position){x, y});
	push_queue(qseen, (t_position){x, y});
	map[y][x] = '?';
	while (q->head)
	{
		t_position e = pop_queue(q);
		t_position	edges[8] =
		{
			{e.x + 1, e.y},
			{e.x, e.y + 1},
			{e.x - 1, e.y},
			{e.x, e.y - 1},
			{e.x + 1, e.y + 1},
			{e.x - 1, e.y - 1},
			{e.x - 1, e.y + 1},
			{e.x + 1, e.y - 1}
		};
		for (int i = 0; i < 8; i++)
		{
			t_position w = edges[i];
			if (w.x < 0 || w.y < 0 || w.x >= cub->config.map_x || w.y >= cub->config.map_y)
				continue ;
			if (ft_isset_tab(map[(int)w.y][(int)w.x], "0!`@$"))
			{
				result = map[(int)w.y][(int)w.x];
				break ;
			}
			if (ft_isset_tab(map[(int)w.y][(int)w.x], "NSEWLPOFHI|A"))
			{
				map[(int)w.y][(int)w.x] = '?';
				push_queue(qseen, w);
				push_queue(q, w);
			}
		}
	}
	printf("%c\n", result);
	while (qseen->head)
	{
		t_position p = pop_queue(qseen);
		map[(int)p.y][(int)p.x] = result;
	}
	destroy_queue(q);
	destroy_queue(qseen);
}

void	replace_ground(t_cub *cub)
{
	map_sprite(cub, cub->config.map);
	for (int y = 0; y < cub->config.map_y; y++)
	{
		for (int x = 0; x < cub->config.map_x; x++)
		{
			if (ft_isset_tab(cub->config.map[y][x], "NSEWLPOFHI|A"))
				find_nearest(cub, cub->config.map, x, y);
		}
	}
	for (int i = 0; i < cub->config.map_y; i++)
		puts(cub->config.map[i]);
}
