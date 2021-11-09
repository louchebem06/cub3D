/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_folder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 20:12:04 by bledda            #+#    #+#             */
/*   Updated: 2021/11/09 20:15:36 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/ft_config.h"

void	check_folder(const char *file)
{
	int	fd;

	fd = open(file, O_DIRECTORY);
	if (fd != -1)
	{
		close(fd);
		ft_error("Error:\n\t-Your card is not in the correct format \".cub\" \
or the file could not be opened\n", RED);
		exit(1);
	}
}
