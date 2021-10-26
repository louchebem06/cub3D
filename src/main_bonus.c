/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 20:17:10 by bledda            #+#    #+#             */
/*   Updated: 2021/10/26 20:22:53 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

int	main(int ac, const char **av)
{
	t_cub	cub;

	cub.no_intro = false;
	if (ac == 3 && !ft_strncmp(av[2], "NO_INTRO", 8) && ft_strlen(av[2]) == 8)
		cub.no_intro = true;
	if ((ac == 2 || cub.no_intro) && ft_config(&cub, av[1]))
	{
		cub.keys = (t_keys){false};
		cub3d(&cub);
	}
	else if (ac == 1)
		ft_error("Error:\n\t-Please specify a map\n", RED);
	else if (ac > 3)
		ft_error("Error:\n\t-Too many arguments\n", RED);
	return (0);
}
