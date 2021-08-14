/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_config.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 04:46:17 by bledda            #+#    #+#             */
/*   Updated: 2021/08/14 05:08:58 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/ft_config.h"

/*
	Reste le parsing maps a faire
*/
int	ft_config(t_cub *cub, const char *file)
{
	int		fd;
	char	**data_file;

	data_file = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1 || !ft_extension(file, ".cub"))
	{
		printf("error: your card is not in the correct format \".cub\" \
or the file could not be opened\n");
		return (0);
	}
	get_file(fd, file, &data_file);
	if (!get_values(&data_file, cub))
		return (0);
	return (1);
}
