/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 20:05:33 by heejunki          #+#    #+#             */
/*   Updated: 2023/06/27 14:43:09 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHI_H
# define PHI_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

# define PURPLE "\033[0;95m"
# define RED "\033[0;91m"
# define GREEN "\033[0;92m"
# define YELLOW "\033[0;93m"
# define BLUE "\033[0;94m"
# define WHITE "\033[0;97m"
# define SKY "\033[0;96m"

struct	s_state;

typedef struct s_phi
{
	int				id;
	int				r_fork_id;
	int				l_fork_id;
	int				count_eat;
	uint64_t		last_eat;
	pthread_t		th_id;
	struct s_state	*link;
}t_phi;

typedef struct s_state
{
	int				number_of;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;	
	int				died;
	int				satisfy_count;
	pthread_mutex_t	*fork_mutex;
	pthread_mutex_t	print_mutex;
	t_phi			*phi;
	uint64_t		start_time;
}t_state;

int			check(t_state *info);
int			ft_atoi(const char *str);
int			ph_init(t_state *info, int ac, char **av, int begin);
int			ind_init(t_state *info);
int			ft_error(char *s);
uint64_t	gettime(void);
int			create(t_state *info, int i, int j);
void		print(int id, char *s, t_state *info);
int			die(t_state *info, int i, int j);
void		pass_the_time(int time, t_state *info);

#endif
