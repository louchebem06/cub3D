/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_check_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 23:33:33 by bledda            #+#    #+#             */
/*   Updated: 2021/08/15 00:31:25 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//         1111111111111111111111111
//         1000000000110000000000001
//         1011000001110000000000001
//         1001000000000000000000001
// 111111111011000001110000000000001
// 100000000011000001110111111111111
// 1111011111111101111110000101
// 111101111111110111  10010001
// 11000000110101011111100001011
// 10000000000000001100000010001
// 10000000000000001101010010001
// 11000001110101011111011110N0111
// 11110111 1110101 101111010001
// 11111111 1111111 111111111111

#include "../../header/ft_config.h"

static int	size_map(char ***map, int c)
{
	int	i;
	int	x;
	int	tmp;

	if (c == 'x')
	{
		i = -1;
		x = 0;
		while ((*map)[++i])
		{
			tmp = ft_strlen((*map)[i]);
			if (tmp > x)
				x = tmp;
		}
		return (x);
	}
	else if (c == 'y')
	{
		i = 0;
		while ((*map)[i])
			i++;
		return (i);
	}
	return (0);
}

static void	add_space(char **line, int space)
{
	char	*tmp;
	char	*tmp_space;

	tmp_space = ft_calloc(sizeof(char *), space + 1);
	while (space-- > 0)
		tmp_space[space] = ' ';
	tmp = ft_strjoin(*line, tmp_space);
	free(*line);
	free(tmp_space);
	*line = tmp;
}

static void	normalize_map(char ***map)
{
	int	max_size;
	int	y;

	max_size = size_map(map, 'x');
	y = -1;
	while ((*map)[++y])
	{
		if ((int)ft_strlen((*map)[y]) < max_size)
			add_space(&(*map)[y], max_size - (int)ft_strlen((*map)[y]));
	}
}

void	print_map(char **map)//doit etre remove
{
	for (int i = 0; map[i]; i++)
		printf("%s*\n", map[i]);
}

int	wall_check_map(t_cub *cub)
{
	cub->config.map_x = size_map(&cub->config.map, 'x');
	cub->config.map_y = size_map(&cub->config.map, 'y');
	normalize_map(&cub->config.map);
	print_map(cub->config.map);
	return (0);
}
