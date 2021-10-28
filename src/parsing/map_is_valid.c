/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_is_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 06:21:35 by bledda            #+#    #+#             */
/*   Updated: 2021/10/28 13:28:22 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/ft_config.h"

static void	error_xpm(char *str)
{
	ft_error("\t- ", RED);
	ft_error(str, RED);
	ft_error(" not *.xpm file\n", RED);
}

static void	error_ext(t_cub *cub)
{
	ft_error("Error:\n", RED);
	if (!ft_extension(cub->config.path_we, ".xpm"))
		error_xpm(cub->config.path_we);
	if (!ft_extension(cub->config.path_so, ".xpm"))
		error_xpm(cub->config.path_so);
	if (!ft_extension(cub->config.path_ea, ".xpm"))
		error_xpm(cub->config.path_ea);
	if (!ft_extension(cub->config.path_no, ".xpm"))
		error_xpm(cub->config.path_no);
	free_cub(cub);
}

static bool	min_ligne(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
		;
	if (i < 3)
	{
		ft_error("Error:\n\t-Minimun ligne for map is 3\n", RED);
		return (false);
	}
	return (true);
}

int	map_is_valid(t_cub *cub)
{
	if (!remove_newlines(&cub->config.map) || remove_space_map(&cub->config.map)
		|| empty_line_in_map(cub->config.map)
		|| remove_end_space_map(&cub->config.map)
		|| forbiden_char_map(cub->config.map) || min_char_map(cub->config.map)
		|| multi_pos_map(cub->config.map) || wall_check_map(cub)
		|| !min_ligne(cub->config.map))
	{
		free_cub(cub);
		return (0);
	}
	if (!ft_extension(cub->config.path_we, ".xpm")
		|| !ft_extension(cub->config.path_so, ".xpm")
		|| !ft_extension(cub->config.path_ea, ".xpm")
		|| !ft_extension(cub->config.path_no, ".xpm"))
	{
		error_ext(cub);
		return (0);
	}
	create_player_info(cub);
	return (1);
}
