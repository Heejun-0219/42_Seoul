/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 14:49:01 by heejunki          #+#    #+#             */
/*   Updated: 2023/01/19 02:18:21 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../Libft/libft.h"

void	insert_stack(t_list **stack, char **val);
int		main(int ac, char **av);

void	eexit(void);
long	overflow_check(const char *str);

void	check_overflow(char *val);
int		check_double_zero(char *val);
void	check_overlap(char **val);
void	check_digit(char *val);
int		ft_strcmp(const char *str, const char *str2);

int		param_check(char **av);

void	ft_lst_order(t_list **stack);
void	ft_lst_inverted(t_list **stack);
void	three_size_sorting(t_list **a);
void	five_size_sorting(t_list **a, t_list **b);

int     *list_data_copy(t_list *a, int size);
int     *return_lis(int *data, int *step, int size, int max);
void    find_step(int *data, int *step, int size);
int     *count_lis(int *data, int size, int *max);
void	rotate_to_start(t_list **a, int a_size);

void    move_to_a(t_list **a, t_list **b);
int     pos_to_a(t_list **a,int a_size, t_list **b, int b_size);
void    move_to_b(t_list **a, t_list **b, int *lis, int max);
int     pos_to_b(t_list *a, int *lis, int max);
int     return_val(int *max_or_min_pos, int a_size, int content);
int     max_or_min(t_list *a, int a_size, int content);
int     max_val(int distance, int sector);
int     mix_val(int distance, int sector);
int     find_sector(t_list *a, int a_size, int content);
int     find_distance(int index, int size);
int     find_best_pos_move(int *distanc, int *sedctor, int b_size);
int     ra_rra_move_to_a(int distance, int sector, t_list **a, t_list **b);

void	ss(t_list **a, t_list **b);
void	sb(t_list **b);
void	sa(t_list **a);
void	pb(t_list **a, t_list **b);
void	pa(t_list **a, t_list **b);
void	rr(t_list **a, t_list **b);
void	rb(t_list **b);
void	ra(t_list **a);
void	rra(t_list **a);
void	rrb(t_list **b);
void	rrr(t_list **a, t_list **b);

#endif