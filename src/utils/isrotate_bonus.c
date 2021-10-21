/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isrotate_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 21:06:31 by bledda            #+#    #+#             */
/*   Updated: 2021/10/21 21:08:28 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/utils_bonus.h"

bool	isrotate(t_cub *cub)
{
	if (cub->keys.arrow_l || cub->keys.arrow_r)
		return (true);
	return (false);
}
