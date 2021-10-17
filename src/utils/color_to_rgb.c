/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_to_rgb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 14:58:27 by bledda            #+#    #+#             */
/*   Updated: 2021/10/17 15:00:47 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/utils.h"

t_rgb	color_to_rgb(unsigned int color)
{
	t_rgb	result;

	result.r = ((color & 0x00FF0000) >> 16);
	result.g = ((color & 0x0000FF00) >> 8);
	result.b = ((color & 0x000000FF));
	return (result);
}
