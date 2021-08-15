/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 04:46:53 by bledda            #+#    #+#             */
/*   Updated: 2021/08/15 05:54:34 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

void	add_value(char **str, char *new_value);
int		ft_strisdigit(char *str);
void	free_split(char ***tab);
int		count_char(const char *str, int c);
void	ft_error(const char *str, const char *color);

#endif
