/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_is_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 06:21:35 by bledda            #+#    #+#             */
/*   Updated: 2021/10/04 14:58:53 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/ft_config.h"

static void	free_cub(t_cub *cub)
{
	int	i;

	i = -1;
	free(cub->config.path_ea);
	free(cub->config.path_no);
	free(cub->config.path_so);
	free(cub->config.path_we);
	while (cub->config.map[++i])
		free(cub->config.map[i]);
	free(cub->config.map);
}

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

int	map_is_valid(t_cub *cub)
{
	if (!remove_newlines(&cub->config.map) || remove_space_map(&cub->config.map)
		|| empty_line_in_map(cub->config.map)
		|| remove_end_space_map(&cub->config.map)
		|| forbiden_char_map(cub->config.map) || min_char_map(cub->config.map)
		|| multi_pos_map(cub->config.map) || wall_check_map(cub))
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
