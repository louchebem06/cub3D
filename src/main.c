/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 18:13:22 by bledda            #+#    #+#             */
/*   Updated: 2021/08/15 04:29:29 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

int	main(int ac, const char **av)
{
	t_cub	cub;

	if (ac == 2 && ft_config(&cub, av[1]))
	{
		cub.win.mlx = mlx_init();
		cub.win.win = mlx_new_window(cub.win.mlx, WINDOWS_WIDTH,
				WINDOWS_HEIGHT, "cub3D");
		mlx_loop(cub.win.mlx);
	}
	else if (ac == 1)
		printf("Error:\n\t-Please specify a map\n");
	else if (ac > 2)
		printf("Error:\n\t-Too many arguments\n");
	return (0);
}
