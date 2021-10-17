/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ismove_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 22:46:33 by bledda            #+#    #+#             */
/*   Updated: 2021/10/17 22:48:02 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/utils_bonus.h"

bool	ismove(t_cub *cub)
{
	if (cub->keys.down || cub->keys.up || cub->keys.left || cub->keys.right)
		return (true);
	return (false);
}
