/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extension.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 05:06:31 by bledda            #+#    #+#             */
/*   Updated: 2021/08/15 09:36:15 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/ft_config.h"

int	ft_extension(const char *file, const char *ext)
{
	int	size_file;
	int	size_ext;

	size_file = ft_strlen(file);
	size_ext = ft_strlen(ext);
	if (size_ext > size_file)
		return (0);
	while (size_ext >= 0)
	{
		if (file[size_file] != ext[size_ext])
			return (0);
		size_file--;
		size_ext--;
	}
	return (1);
}
