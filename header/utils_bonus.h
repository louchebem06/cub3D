/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 20:57:14 by bledda            #+#    #+#             */
/*   Updated: 2021/10/23 16:48:46 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_BONUS_H
# define UTILS_BONUS_H

# include <sys/time.h>
# include <sys/types.h>
# include "cub_bonus.h"

unsigned long long	ft_get_current_time(void);
bool				ismove(t_cub *cub);
bool				isrotate(t_cub *cub);

#endif
