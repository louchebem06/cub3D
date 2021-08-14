/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_config.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 04:46:53 by bledda            #+#    #+#             */
/*   Updated: 2021/08/14 20:57:45 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONFIG_H
# define FT_CONFIG_H

# include "cub3d.h"

typedef struct s_cub		t_cub;
typedef struct s_position	t_position;

typedef struct s_isset
{
	int	no;
	int	so;
	int	we;
	int	ea;
	int	f;
	int	c;
	int	error;
}		t_isset;

int		ft_config(t_cub *cub, const char *file);
int		ft_extension(const char *file, const char *ext);
void	get_file(int fd, const char *file, char ***config);
int		get_values(char ***data_file, t_cub *cub);
void	free_path(t_isset *isset, t_cub *cub);
void	add_simple(t_isset *isset, t_cub *cub, char ***split);
void	add_multi(t_isset *isset, t_cub *cub, char ***split);
int		map_is_valid(t_cub *cub);
int		remove_newlines(char ***map);
int		empty_line_in_map(char **map);
int		forbiden_char_map(char **map);
int		multi_pos_map(char **map);
int		min_char_map(char **m);

#endif
