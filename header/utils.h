/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 04:46:53 by bledda            #+#    #+#             */
/*   Updated: 2021/10/11 23:59:56 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

typedef struct s_rgb	t_rgb;

void			add_value(char **str, char *new_value);
int				ft_strisdigit(char *str);
void			free_split(char ***tab);
int				count_char(const char *str, int c);
void			ft_error(const char *str, const char *color);
unsigned int	anti_rgb(t_rgb rgb);

#endif
