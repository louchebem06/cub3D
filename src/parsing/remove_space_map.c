/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_space_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 22:16:41 by bledda            #+#    #+#             */
/*   Updated: 2021/08/14 22:31:33 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/ft_config.h"

static void	move_left(char **str)
{
	char	*tmp;
	int		i;
	int		j;

	tmp = ft_strdup(*str);
	i = 0;
	j = 0;
	while (tmp[++j])
		(*str)[i++] = tmp[j];
	(*str)[i++] = 0;
	free(tmp);
}

int	remove_space_map(char ***map)
{
	int	i;

	i = -1;
	while ((*map)[++i])
		if ((*map)[i][0] != ' ')
			return (0);
	i = -1;
	while ((*map)[++i])
		move_left(&(*map)[i]);
	remove_space_map(map);
	return (0);
}
