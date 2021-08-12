/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_lite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 00:28:46 by bledda            #+#    #+#             */
/*   Updated: 2021/06/20 00:31:14 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

void	ft_printf(const char *input, ...)
{
	va_list	ap;
	int		i;
	char	*str;

	i = -1;
	va_start(ap, input);
	while (input[++i] != 0)
	{
		if (input[i] == '%')
		{
			i++;
			if (input[i] == '%' || input[i] == 'c')
				ft_putchar_fd(input[i], 1);
			else if (input[i] == 's')
			{
				str = va_arg(ap, char *);
				ft_putstr_fd(str, 1);
			}
			else if (input[i] == 'd')
				ft_putnbr_fd(va_arg(ap, int), 1);
		}
		else
			ft_putchar_fd(input[i], 1);
	}
	va_end(ap);
}
