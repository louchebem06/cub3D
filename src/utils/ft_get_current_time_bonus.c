/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_current_time_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 20:55:39 by bledda            #+#    #+#             */
/*   Updated: 2021/10/23 17:04:17 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/utils_bonus.h"

unsigned long long	ft_get_current_time(void)
{
	struct timeval			current_time;
	unsigned long long		second;

	gettimeofday(&current_time, NULL);
	second = current_time.tv_sec * 1000;
	return (second + current_time.tv_usec / 1000);
}
