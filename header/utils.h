/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 04:46:53 by bledda            #+#    #+#             */
/*   Updated: 2021/10/12 02:24:02 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdbool.h>
# include "../libft/header/libft.h"
# include "cub3d.h"

typedef struct s_rgb	t_rgb;
typedef struct s_cub	t_cub;

void			add_value(char **str, char *new_value);
int				ft_strisdigit(char *str);
void			free_split(char ***tab);
int				count_char(const char *str, int c);
void			ft_error(const char *str, const char *color);
unsigned int	anti_rgb(t_rgb rgb);
bool			is_valid_int(char *input);
void			free_cub(t_cub *cub);

#endif
