/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 18:13:10 by mmehran           #+#    #+#             */
/*   Updated: 2021/10/30 12:31:09 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_BONUS_H
# define QUEUE_BONUS_H

# include <stdlib.h>
# include "cub3d.h"

typedef struct s_qnode
{
	t_position		key;
	struct s_qnode	*next;
}	t_qnode;

typedef struct s_queue
{
	t_qnode	*head;
	t_qnode	*tail;
}	t_queue;

t_queue		*create_queue(void);
void		push_queue(t_queue *q, t_position k);
t_position	pop_queue(t_queue *q);
void		destroy_queue(t_queue *q);

#endif
