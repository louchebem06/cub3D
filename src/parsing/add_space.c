/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_space.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 06:02:58 by bledda            #+#    #+#             */
/*   Updated: 2021/08/15 06:04:07 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/ft_config.h"

void	add_space(char **line, int space)
{
	char	*tmp;
	char	*tmp_space;

	tmp_space = ft_calloc(sizeof(char *), space + 1);
	while (space-- > 0)
		tmp_space[space] = ' ';
	tmp = ft_strjoin(*line, tmp_space);
	free(*line);
	free(tmp_space);
	*line = tmp;
}
