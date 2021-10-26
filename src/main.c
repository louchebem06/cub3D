/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 18:13:22 by bledda            #+#    #+#             */
/*   Updated: 2021/10/26 17:33:28 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

int	main(int ac, const char **av)
{
	t_cub	cub;

	if (ac == 2 && ft_config(&cub, av[1]))
	{
		cub.keys = (t_keys){false};
		cub3d(&cub);
	}
	else if (ac == 1)
		ft_error("Error:\n\t-Please specify a map\n", RED);
	else if (ac > 2)
		ft_error("Error:\n\t-Too many arguments\n", RED);
	return (0);
}
