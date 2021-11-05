/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 16:47:02 by mmehran           #+#    #+#             */
/*   Updated: 2021/11/05 12:35:05 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub_bonus.h"

static t_img	*get_wall_direction(t_cub *cub, const t_position *ray_pos)
{
	const float	off_x = ray_pos->x - floorf(ray_pos->x);
	const float	off_y = ray_pos->y - floorf(ray_pos->y);

	if (off_x > off_y)
	{
		if (cub->player.pos.y > ray_pos->y)
			return (&cub->texture.so);
		return (&cub->texture.no);
	}
	else
	{
		if (cub->player.pos.x > ray_pos->x)
			return (&cub->texture.ea);
		return (&cub->texture.we);
	}
	return (NULL);
}

t_img	*get_wall_texture(t_cub *cub, const t_position *ray_pos)
{
	const char	c = get_map_char2(cub, ray_pos, &cub->player.pos);

	if (c == '2')
		return (&cub->texture.two);
	if (c == '3')
		return (&cub->texture.three);
	if (c == '4')
		return (&cub->texture.four);
	if (c == '5')
		return (&cub->texture.five);
	if (c == '6')
		return (&cub->texture.six);
	if (c == '7')
		return (&cub->texture.seven);
	if (c == '8')
		return (&cub->texture.eight);
	if (c == '9')
		return (&cub->texture.nine);
	if (c == ']')
		return (&cub->texture.beton);
	if (c == '1')
		return (get_wall_direction(cub, ray_pos));
	if (c == 'p' || c == 'P')
		return (&cub->sprite.door);
	return (NULL);
}

t_img	*get_fc_texture(t_cub *cub, const t_position *ray_pos, bool floor)
{
	const char	c = get_map_char(&cub->map, ray_pos, &cub->player.pos);

	if (c == '!')
	{
		if (floor)
			return (&cub->texture.floor);
		return (&cub->texture.ceiling);
	}
	else if (c == '`')
	{
		if (floor)
			return (&cub->texture.redline);
		return (&cub->texture.ceiling);
	}
	else if (c == '@')
		return (&cub->texture.bet);
	else if (c == '$')
	{
		if (floor)
			return (&cub->texture.bet);
		return (&cub->texture.stairs);
	}
	return (NULL);
}
