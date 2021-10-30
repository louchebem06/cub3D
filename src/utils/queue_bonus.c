/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 18:13:05 by mmehran           #+#    #+#             */
/*   Updated: 2021/10/30 15:17:29 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/queue_bonus.h"

static t_qnode	*new_node(t_position k)
{
	t_qnode	*new;

	new = malloc(sizeof(t_qnode));
	new->key = k;
	new->next = NULL;
	return (new);
}

t_queue	*create_queue(void)
{
	t_queue	*q;

	q = malloc(sizeof(t_queue));
	q->head = NULL;
	q->tail = NULL;
	return (q);
}

void	push_queue(t_queue *q, t_position k)
{
	t_qnode	*new;

	new = new_node(k);
	if (!q->head)
	{
		q->head = new;
		q->tail = new;
		return ;
	}
	q->tail->next = new;
	q->tail = new;
}

t_position	pop_queue(t_queue *q)
{
	t_qnode		*temp;
	t_position	result;

	result = (t_position){0};
	if (q && q->head)
	{
		result = q->head->key;
		temp = q->head;
		q->head = q->head->next;
		if (!q->head)
			q->tail = NULL;
		free(temp);
	}
	return (result);
}

void	destroy_queue(t_queue *q)
{
	if (!q)
		return ;
	while (q->head)
		pop_queue(q);
	free(q);
}
