/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_b.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 20:03:18 by heejunki          #+#    #+#             */
/*   Updated: 2023/06/27 14:40:05 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHI_B_H
# define PHI_B_H

# define PURPLE "\033[0;95m"
# define RED "\033[0;91m"
# define GREEN "\033[0;92m"
# define YELLOW "\033[0;93m"
# define BLUE "\033[0;94m"
# define WHITE "\033[0;97m"
# define SKY "\033[0;96m"

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <semaphore.h>
# include <pthread.h>
# include <stdint.h>
# include <sys/time.h>
# include <pthread.h>
# include <fcntl.h>
# include <sys/time.h>
# include <sys/stat.h> 
# include <stdbool.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <signal.h>

typedef struct s_env	t_state;

typedef struct s_a
{
	int			pid;
	int			id;
	int			eat_count;
	uint64_t	last_eat;
	t_state		*link;
}				t_phis;

typedef struct s_env
{
	int			number_of;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			must_eat;
	uint64_t	start_time;
	sem_t		*forks;
	sem_t		*print;
	bool		all_eat;
	bool		is_died;
	pthread_t	yep;
	pthread_t	check;
	t_phis		*philo;
}				t_state;

void		check(t_state *all);
uint64_t	gettime(void);
void		ft_exit(char *s);
int			ft_atoi(char *s);
void		*waitp(void *data);
void		process(t_state *all);
void		meal_time(t_phis *philo);
void		philo_think(t_phis *philo);
void		philo_sleep(t_phis *philo);
void		pass_the_time(int time, t_state *all);
void		print(int id, char *s, t_state *aristo);
void		init_arguments(t_state *all, int ac, char **av);
#endif
