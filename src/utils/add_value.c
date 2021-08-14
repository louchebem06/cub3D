/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 05:17:04 by bledda            #+#    #+#             */
/*   Updated: 2021/08/14 05:18:20 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/ft_config.h"

void	add_value(char **str, char *new_value)
{
	char	*tmp;

	tmp = ft_strjoin(*str, new_value);
	free(*str);
	*str = tmp;
}
