/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_img_intro_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 15:22:48 by bledda            #+#    #+#             */
/*   Updated: 2021/11/11 13:47:18 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include "../../header/cub_bonus.h"

static void	create_img_intro(t_cub *cub, int start, int end)
{
	char		file[30];
	int			i;

	i = start;
	while (++i < end)
	{
		ft_bzero(file, 30);
		ft_strlcat(file, "texture/intro29s/intro", 30);
		file[22] = (i / 100) % 10 + '0';
		file[23] = (i / 10) % 10 + '0';
		file[24] = i % 10 + '0';
		ft_strlcat(file, ".xpm", 30);
		generate_i(cub, &cub->intro[i], file);
	}
}

static void	*generate_data_intro(void *cur_thread)
{
	t_thread	*thread;
	t_cub		*cub;
	int			rem;
	int			start;
	int			end;

	thread = (t_thread *)cur_thread;
	cub = (t_cub *)thread->main;
	rem = IMG_INTRO % thread->nb_thread;
	start = ((IMG_INTRO / thread->nb_thread) * (thread->id_thread)) - 1;
	end = (IMG_INTRO / thread->nb_thread) * (thread->id_thread + 1);
	if (thread->id_thread + 1 == thread->nb_thread)
		end += rem;
	create_img_intro(cub, start, end);
	pthread_exit(0);
}

void	generate_img_intro(t_cub *cub)
{
	t_thread					t[THREAD_IMG_INTRO];
	pthread_t					thread[THREAD_IMG_INTRO];
	int							i;
	const unsigned long long	time = ft_get_current_time();

	i = -1;
	while (++i < THREAD_IMG_INTRO)
	{
		t[i].id_thread = i;
		t[i].nb_thread = THREAD_IMG_INTRO;
		t[i].main = cub;
		pthread_create(&thread[i], NULL, generate_data_intro, &t[i]);
	}
	i = -1;
	while (++i < THREAD_IMG_INTRO)
		pthread_join(thread[i], NULL);
	printf("Loaded intro in : %f\n", (ft_get_current_time() - time) / 1000.0f);
}
