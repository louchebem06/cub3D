/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_config.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 04:46:17 by bledda            #+#    #+#             */
/*   Updated: 2021/11/09 20:05:29 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/ft_config.h"

int	ft_config(t_cub *cub, const char *file)
{
	int		fd;
	char	**data_file;

	data_file = 0;
	fd = open(file, O_DIRECTORY);
	if (fd != -1)
	{
		ft_error("Error:\n\t-Your card is not in the correct format \".cub\" \
or the file could not be opened\n", RED);
		return (0);
	}
	close(fd);
	fd = open(file, O_RDONLY);
	if (fd == -1 || !ft_extension(file, ".cub"))
	{
		ft_error("Error:\n\t-Your card is not in the correct format \".cub\" \
or the file could not be opened\n", RED);
		return (0);
	}
	get_file(fd, file, &data_file);
	if (!get_values(&data_file, cub) || !map_is_valid(cub))
		return (0);
	return (1);
}
