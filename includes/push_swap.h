/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prynty <prynty@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 14:55:12 by prynty            #+#    #+#             */
/*   Updated: 2024/09/06 15:24:26 by prynty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>

typedef struct s_stack
{
	long			nbr;
	struct s_stack	*next;
}	t_stack;

void		ra(t_stack **a);
void		rb(t_stack **b);
void		rr(t_stack **a, t_stack **b);

void		rra(t_stack **a);
void		rrb(t_stack **b);
void		rrr(t_stack **a, t_stack **b);

void		sa(t_stack **a);
void		sb(t_stack **b);
void		ss(t_stack **a, t_stack **b);

void		pa(t_stack **a, t_stack **b);
void		pb(t_stack **a, t_stack **b);

void		free_stack(t_stack *stack);
void		free_array_and_exit(t_stack *stack, char **numbers);
void		free_and_exit(t_stack *stack);
void		print_error(void);

const char	*parse_whitespace(const char *str);
int			parse_args(const char *str, int *error);

t_stack		*init_stack(int argc, char **argv);
t_stack		*new_stack_node(int content);
void		add_to_top(t_stack **stack, t_stack *new);
t_stack		*find_last(t_stack *lst);

t_stack		*find_cheapest(t_stack *stack_a, t_stack *stack_b);
int			find_index(t_stack *stack, int nbr);
int			find_pos_in_b(t_stack *stack_b, int nbr);
void		rotate_to_min(t_stack **a);

int			ft_abs(int nbr);
int			smallest_nbr(t_stack *stack);
int			biggest_nbr(t_stack *stack);
int			stack_size(t_stack *lst);

int			single_rotate_cost(int size, int pos);
int			calculate_cost(t_stack *stack_a, t_stack *stack_b, int nbr);

void		single_stack_rotations(t_stack **stack, int rotations,
				bool forward, bool is_stack_a);
void		perform_rotations(t_stack **stack_a, int cost_a,
				t_stack **stack_b, int cost_b);

int			check_sorted(t_stack *stack);
void		sort_three(t_stack **stack_a);
void		sort_small(t_stack **stack_a, t_stack **stack_b);
void		sort_stack(t_stack **stack_a);
void		sort_big(t_stack **a, t_stack **b);

#endif
