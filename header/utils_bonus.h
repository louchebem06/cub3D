/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 20:57:14 by bledda            #+#    #+#             */
/*   Updated: 2021/10/17 23:37:10 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_BONUS_H
# define UTILS_BONUS_H

# include <sys/time.h>
# include <sys/types.h>
# include "cub_bonus.h"

long int	ft_get_current_time(void);
bool		ismove(t_cub *cub);

#endif