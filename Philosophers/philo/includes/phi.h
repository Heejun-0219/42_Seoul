/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 20:05:33 by heejunki          #+#    #+#             */
/*   Updated: 2023/07/06 13:25:45 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHI_H
# define PHI_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

# define SUCCESS 0
# define FAILURE 1
# define ALIVE 0
# define DEAD 1
# define FINISH 1

typedef struct s_phi
{
	int				id;
	int				r_fork_id;
	int				l_fork_id;
	int				count_eat;
	long			last_eat;
	pthread_t		th_id;
	struct s_state	*link;
}t_phi;

typedef struct s_state
{
	int				number_of;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	int				must_eat;	
	int				died;
	int				satisfy_count;
	pthread_mutex_t	*fork_mutex;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	eat_cnt_mutex;
	pthread_mutex_t	eat_satisft_mutex;
	pthread_mutex_t	died_mutex;
	pthread_mutex_t	last_eat_mutex;
	t_phi			*phi;
	long			start_time;
}t_state;

int			check(t_state *info);
int			ft_atoi(char *s);
int			ph_init(t_state *info, int ac, char **av);
int			ind_init(t_state *info);
void		th_init(t_state *intfo);
int			ft_error(char *s);
long		gettime(void);
int			create(t_state *info);
int			print(int id, char *s, t_state *info);
int			die(t_state *info);
int			pass_the_time(long time, t_phi *philo);
void		destory(t_state *info);
int			get_fork(t_phi *philo);
int			check_status(t_phi *phi);
int			ft_fork_unlock(t_phi *phi);

void free_all(t_state *info);

#endif
