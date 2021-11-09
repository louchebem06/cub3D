/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 05:09:42 by bledda            #+#    #+#             */
/*   Updated: 2021/11/09 11:50:18 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/ft_config.h"

static void	fix_folder(int i)
{
	if (i == 1)
	{
		ft_error("Error:\n\t-Your card is not in the correct format \".cub\" \
or the file could not be opened\n", RED);
		exit(1);
	}
}

void	get_file(int fd, const char *file, char ***config)
{
	char	*line;
	int		i;

	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		i++;
		free(line);
	}
	i++;
	fix_folder(i);
	free(line);
	close (fd);
	fd = open(file, O_RDONLY);
	*config = ft_calloc(sizeof(char *), i + 1);
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		(*config)[i++] = ft_strdup(line);
		free(line);
	}
	if (ft_strlen(line) > 0)
		(*config)[i] = ft_strdup(line);
	free(line);
	close(fd);
}
