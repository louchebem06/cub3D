/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 02:08:09 by bledda            #+#    #+#             */
/*   Updated: 2021/10/12 02:09:38 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/utils.h"

static unsigned int	get_number(char *str)
{
	unsigned int	result;

	result = 0;
	while (*str)
		result = result * 10 + *(str++) - '0';
	return (result);
}

bool	is_valid_int(char *input)
{
	int				mult;
	unsigned int	unbr;
	int				i;
	char			*temp;

	i = 0;
	mult = 1;
	if (*input == '-' && input++)
		mult = -1;
	if (mult == -1 && *input == 0)
		return (0);
	while (*input == '0')
		input++;
	temp = input;
	while (*temp && ++i)
	{
		if (i > 10 || !ft_isdigit(*temp))
			return (0);
		temp++;
	}
	unbr = get_number(input);
	if ((mult == 1 && unbr > 2147483647) || (mult == -1 && unbr > 2147483648))
		return (0);
	return (1);
}
