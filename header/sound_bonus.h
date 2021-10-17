/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sound_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 08:02:18 by bledda            #+#    #+#             */
/*   Updated: 2021/10/17 11:54:16 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//http://www.un4seen.com/doc/
//http://www.un4seen.com/

#ifndef SOUND_BONUS_H
# define SOUND_BONUS_H

# include <stdbool.h>
# ifdef __APPLE__
#  include "../base24-osx/bass.h"
# elif __linux__
#  include "../base24-linux/bass.h"
# endif

void	init_sound(t_cub *cub);
void	free_sound(t_cub *cub);
void	toggle(t_music *music, bool restart);

#endif