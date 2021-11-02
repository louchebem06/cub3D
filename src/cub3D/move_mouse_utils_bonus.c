/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_mouse_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:14:37 by bledda            #+#    #+#             */
/*   Updated: 2021/11/02 13:16:13 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/mouse_bonus.h"

#ifdef __APPLE__

#elif __linux__

int	enter_mouse_windows(t_cub *cub)
{
	(void)cub;
	cub->mouse_in_windows = true;
	return (0);
}

int	leave_mouse_windows(t_cub *cub)
{
	(void)cub;
	cub->mouse_in_windows = false;
	return (0);
}
#endif
