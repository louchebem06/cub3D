/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_is_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 06:21:35 by bledda            #+#    #+#             */
/*   Updated: 2021/08/14 20:54:50 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/ft_config.h"

//remove space debut de ligne si il a lieu et ce en fin
//verifier que les mur soit au bon endroit
int	map_is_valid(t_cub *cub)
{
	int	i;

	i = -1;
	if (!remove_newlines(&cub->config.map)
		|| empty_line_in_map(cub->config.map)
		|| forbiden_char_map(cub->config.map)
		|| min_char_map(cub->config.map)
		|| multi_pos_map(cub->config.map))
	{
		free(cub->config.path_ea);
		free(cub->config.path_no);
		free(cub->config.path_so);
		free(cub->config.path_we);
		while (cub->config.map[++i])
			free(cub->config.map[i]);
		free(cub->config.map);
		return (0);
	}
	return (1);
}
