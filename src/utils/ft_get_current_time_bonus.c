/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_current_time_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 20:55:39 by bledda            #+#    #+#             */
/*   Updated: 2021/10/17 21:02:19 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/utils_bonus.h"

long int	ft_micro_to_mili(useconds_t micro)
{
	long int	mili;

	mili = micro / 1000;
	return (mili);
}

long int	ft_get_current_time(void)
{
	struct timeval	current_time;
	long int		second;
	long int		micro;
	long int		mili;

	gettimeofday(&current_time, NULL);
	second = (current_time.tv_sec * 1000000);
	micro = (second + current_time.tv_usec);
	mili = ft_micro_to_mili(micro);
	return (mili);
}
