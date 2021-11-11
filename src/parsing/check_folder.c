/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_folder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 20:12:04 by bledda            #+#    #+#             */
/*   Updated: 2021/11/11 13:57:30 by mmehran          ###   ########.fr       */
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
		ft_error("Error:\n\t-Your card is not in the correct \".cub\" format \
or the file could not be opened\n", RED);
		exit(1);
	}
}
