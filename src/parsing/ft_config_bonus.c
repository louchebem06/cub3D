/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_config_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 21:05:17 by bledda            #+#    #+#             */
/*   Updated: 2021/11/11 13:51:20 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/ft_config.h"
#include "../../header/cub_bonus.h"
#include "../../header/init.h"
#include "../../header/ft_config_bonus.h"

static int	get_nb_sprite(t_cub *cub, const char *ls_sprite)
{
	int	y;
	int	x;
	int	size;

	y = -1;
	size = 0;
	while (++y < cub->config.map_y)
	{
		x = -1;
		while (++x < cub->config.map_x)
			if (ft_isset_tab(cub->config.map[y][x], (char *)ls_sprite))
				size++;
	}
	return (size);
}

static void	add_value_sprite(t_cub *cub, t_item_sprite *config, char c)
{
	const int	size_anim = 6;
	int			i;

	i = -1;
	if (c == 'L')
		config->s = &cub->sprite.lit;
	else if (c == 'O')
		config->s = &cub->sprite.circle;
	else if (c == 'F')
		config->s = &cub->sprite.woman;
	else if (c == 'H')
		config->s = &cub->sprite.man;
	else if (c == 'I')
		config->s = &cub->sprite.intel;
	else if (c == '|')
	{
		config->s_anim = malloc(sizeof(t_img) * size_anim);
		while (++i < size_anim)
			config->s_anim[i] = &cub->sprite.doll[i];
	}
	else if (c == 'A')
		config->s = &cub->sprite.tree;
	config->c = c;
}

static void	get_data_sprite(t_cub *cub)
{
	const char	ls_sprite[] = "LOFHI|A";
	const int	size = get_nb_sprite(cub, ls_sprite);
	int			y;
	int			x;
	int			i;

	cub->sprite.config = ft_calloc(size, sizeof(t_item_sprite));
	cub->sprite.item = size;
	i = 0;
	y = -1;
	while (++y < cub->config.map_y)
	{
		x = -1;
		while (++x < cub->config.map_x)
		{
			if (ft_isset_tab(cub->config.map[y][x], (char *)ls_sprite))
			{
				cub->sprite.config[i].pos = (t_position){(x + 0.5), (y + 0.5)};
				add_value_sprite(cub, &cub->sprite.config[i++],
					cub->config.map[y][x]);
			}
		}
	}
}

static void	get_data_door(t_cub *cub)
{
	const char	ls_sprite[] = "Pp";
	const int	size = get_nb_sprite(cub, ls_sprite);
	int			y;
	int			x;
	int			i;

	cub->doors = ft_calloc(size, sizeof(t_door));
	cub->nb_doors = size;
	i = 0;
	y = -1;
	while (++y < cub->config.map_y)
	{
		x = -1;
		while (++x < cub->config.map_x)
		{
			if (ft_isset_tab(cub->config.map[y][x], (char *)ls_sprite))
			{
				cub->doors[i].c = cub->config.map[y][x];
				cub->doors[i].percent_closed = 1.0f;
				cub->doors[i].closed = true;
				cub->doors[i].pos = (t_position){x, y};
				i++;
			}
		}
	}
}

int	ft_config(t_cub *cub, const char *file)
{
	int		fd;
	char	**data_file;

	data_file = 0;
	check_folder(file);
	fd = open(file, O_RDONLY);
	if (fd == -1 || !ft_extension(file, ".cub"))
	{
		ft_error("Error:\n\t-Your card is not in the correct \".cub\" format \
or the file could not be opened\n", RED);
		return (0);
	}
	get_file(fd, file, &data_file);
	if (!get_values(&data_file, cub) || !map_is_valid(cub))
		return (0);
	get_data_sprite(cub);
	get_data_door(cub);
	replace_ground(cub);
	return (1);
}
