/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 18:15:35 by bledda            #+#    #+#             */
/*   Updated: 2021/08/12 18:18:20 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <stdio.h>
# include "../libft/header/libft.h"
# include "../mlx_utils/header/mlx_keycode.h"
# include "../mlx_utils/header/mlx_put_img_to_img.h"

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}			t_vars;

#endif