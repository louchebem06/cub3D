/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_config.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 04:46:53 by bledda            #+#    #+#             */
/*   Updated: 2021/11/09 20:15:43 by bledda           ###   ########.fr       */
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

typedef struct s_direction_parsing_wall
{
	int	x_map;
	int	y_map;
	int	up;
	int	left;
	int	down;
	int	right;
}		t_direction_parsing_wall;

int		ft_config(t_cub *cub, const char *file);
int		ft_extension(const char *file, const char *ext);
void	get_file(int fd, const char *file, char ***config);
int		get_values(char ***data_file, t_cub *cub);
void	add_simple(t_isset *isset, t_cub *cub, char ***split);
void	add_multi(t_isset *isset, t_cub *cub, char ***split);
int		map_is_valid(t_cub *cub);
int		remove_newlines(char ***map);
int		empty_line_in_map(char **map);
int		forbiden_char_map(char **map);
int		multi_pos_map(char **map);
int		min_char_map(char **m);
int		remove_end_space_map(char ***map);
int		remove_space_map(char ***map);
void	create_player_info(t_cub *cub);
int		wall_check_map(t_cub *cub);
int		size_map(char ***map, int c);
void	add_space(char **line, int space);
void	normalize_map(char ***map);
void	check_folder(const char *file);

#endif
