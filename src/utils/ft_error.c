/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 05:25:05 by bledda            #+#    #+#             */
/*   Updated: 2021/10/04 14:53:29 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/ft_config.h"

void	ft_error(const char *str, const char *color)
{
	ft_putstr_fd((char *)color, 2);
	ft_putstr_fd((char *)str, 2);
	ft_putstr_fd(RESET, 2);
}
