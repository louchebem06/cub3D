/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_img_intro_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 15:22:48 by bledda            #+#    #+#             */
/*   Updated: 2021/10/31 00:07:08 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include "../../header/cub_bonus.h"

#ifdef __APPLE__

# define THREAD_IMG_INTRO 5
#elif __linux__

# define THREAD_IMG_INTRO 1
#endif

#define IMG_INTRO 134

static char	*add_zero(int i)
{
	char	*tmp[2];

	tmp[0] = ft_calloc(sizeof(char), 2);
	tmp[0][0] = '0';
	while (--i > 0)
	{
		tmp[1] = ft_strdup(tmp[0]);
		free(tmp[0]);
		tmp[0] = ft_strjoin(tmp[1], "0");
		free(tmp[1]);
	}
	return (tmp[0]);
}

static char	*file_name(int i)
{
	const char	ch_intro[] = "texture/intro29s/intro";
	char		*file;
	char		*tmp[3];
	char		*nb[2];
	int			nb_zero;

	nb[0] = ft_itoa(i);
	nb[1] = ft_itoa(IMG_INTRO);
	if (ft_strlen(nb[0]) != ft_strlen(nb[1]))
	{
		nb_zero = ft_strlen(nb[1]) - ft_strlen(nb[0]);
		tmp[2] = add_zero(nb_zero);
		tmp[1] = ft_strjoin(ch_intro, tmp[2]);
		tmp[0] = ft_strjoin(tmp[1], nb[0]);
		free(tmp[1]);
		free(tmp[2]);
	}
	else
		tmp[0] = ft_strjoin(ch_intro, nb[0]);
	file = ft_strjoin(tmp[0], ".xpm");
	free(nb[0]);
	free(tmp[0]);
	free(nb[1]);
	return (file);
}

static void	create_img_intro(t_cub *cub, int start, int end)
{
	char		*file;
	int			i;

	i = start;
	while (++i < end)
	{
		file = file_name(i);
		generate_i(cub, &cub->intro[i], file);
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
	printf("Intro load in : %f\n", (ft_get_current_time() - time) / 1000.0f);
}
