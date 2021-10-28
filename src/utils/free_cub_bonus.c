/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cub_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 03:04:24 by bledda            #+#    #+#             */
/*   Updated: 2021/10/28 13:11:55 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/utils.h"
#include "../../header/cub_bonus.h"
#include "../../header/struct_bonus.h"

void	free_cub(t_cub *cub)
{
	int	i;

	i = -1;
	free(cub->config.path_ea);
	free(cub->config.path_no);
	free(cub->config.path_so);
	free(cub->config.path_we);
	while (cub->config.map[++i])
	{
		free(cub->config.map[i]);
		if (cub->config.map_s)
			free(cub->config.map_s[i]);
	}
	free(cub->config.map);
	free(cub->config.map_s);
	i = -1;
	while (++i < cub->sprite.item)
		free(cub->sprite.config[i].s_anim);
	free(cub->sprite.config);
}
