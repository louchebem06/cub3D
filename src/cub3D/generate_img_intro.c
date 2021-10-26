/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_img_intro.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 15:22:48 by bledda            #+#    #+#             */
/*   Updated: 2021/10/26 21:04:33 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include "../../header/cub_bonus.h"

#ifdef __APPLE__

# define THREAD_IMG_INTRO 3
#elif __linux__

# define THREAD_IMG_INTRO 1
#endif

#define IMG_INTRO 465

static void	create_img_intro(t_cub *cub, int start, int end)
{
	const char	ch_intro[] = "texture/intro29s/intro";
	char		*file;
	char		*tmp[2];
	char		*nb;
	int			i;

	i = start;
	while (++i < end)
	{
		nb = ft_itoa(i);
		if (i < 10)
		{
			tmp[1] = ft_strjoin(ch_intro, "00");
			tmp[0] = ft_strjoin(tmp[1], nb);
			free(tmp[1]);
		}
		else if (i < 100)
		{
			tmp[1] = ft_strjoin(ch_intro, "0");
			tmp[0] = ft_strjoin(tmp[1], nb);
			free(tmp[1]);
		}
		else
			tmp[0] = ft_strjoin(ch_intro, nb);
		file = ft_strjoin(tmp[0], ".xpm");
		generate_i(cub, &cub->intro[i], file);
		free(nb);
		free(tmp[0]);
		free(file);
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
}
