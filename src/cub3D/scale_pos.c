/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale_pos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 00:20:45 by mmehran           #+#    #+#             */
/*   Updated: 2021/10/12 00:21:29 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

t_position	scale_pos(t_position *pos, float scale_x, float scale_y)
{
	t_position	screen_pos;

	screen_pos.x = scale_x * pos->x;
	screen_pos.y = scale_y * pos->y;
	return (screen_pos);
}
