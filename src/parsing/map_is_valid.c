/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_is_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 06:21:35 by bledda            #+#    #+#             */
/*   Updated: 2021/08/15 05:42:19 by bledda           ###   ########.fr       */
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
	ft_error("\t- ");
	ft_error(str);
	ft_error(" not *.xpm file\n");
}

static void	error_ext(t_cub *cub)
{
	ft_error("Error:\n");
	if (!ft_extension(cub->config.path_we, ".xmp"))
		error_xpm(cub->config.path_we);
	if (!ft_extension(cub->config.path_so, ".xmp"))
		error_xpm(cub->config.path_so);
	if (!ft_extension(cub->config.path_ea, ".xmp"))
		error_xpm(cub->config.path_ea);
	if (!ft_extension(cub->config.path_no, ".xmp"))
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
	if (!ft_extension(cub->config.path_we, ".xmp")
		|| !ft_extension(cub->config.path_so, ".xmp")
		|| !ft_extension(cub->config.path_ea, ".xmp")
		|| !ft_extension(cub->config.path_no, ".xmp"))
	{
		error_ext(cub);
		return (0);
	}
	create_player_info(cub);
	return (1);
}
