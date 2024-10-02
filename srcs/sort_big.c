/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prynty <prynty@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:01:01 by prynty            #+#    #+#             */
/*   Updated: 2024/07/21 16:34:43 by prynty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	single_stack_rotations(t_stack **stack, int rotations, bool forward,
		bool is_stack_a)
{
	while (rotations > 0)
	{
		if (forward)
		{
			if (is_stack_a)
				ra(stack);
			else
				rb(stack);
		}
		else
		{
			if (is_stack_a)
				rra(stack);
			else
				rrb(stack);
		}
		rotations--;
	}
}

void	perform_rotations(t_stack **stack_a, int cost_a, t_stack **stack_b,
		int cost_b)
{
	if (cost_a > 0 && cost_b > 0)
	{
		while (cost_a > 0 && cost_b > 0)
		{
			rr(stack_a, stack_b);
			cost_a--;
			cost_b--;
		}
	}
	else if (cost_a < 0 && cost_b < 0)
	{
		while (cost_a < 0 && cost_b < 0)
		{
			rrr(stack_a, stack_b);
			cost_a++;
			cost_b++;
		}
	}
	single_stack_rotations(stack_a, ft_abs(cost_a), (cost_a >= 0), true);
	single_stack_rotations(stack_b, ft_abs(cost_b), (cost_b >= 0), false);
}

void	sort_big(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cheapest;
	int		pos_a;
	int		pos_b;
	int		cost_a;
	int		cost_b;

	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	if (check_sorted(*stack_b))
		sb(stack_b);
	while (*stack_a)
	{
		cheapest = find_cheapest(*stack_a, *stack_b);
		pos_a = find_index(*stack_a, cheapest->nbr);
		pos_b = find_pos_in_b(*stack_b, cheapest->nbr);
		cost_a = single_rotate_cost(stack_size(*stack_a), pos_a);
		cost_b = single_rotate_cost(stack_size(*stack_b), pos_b);
		perform_rotations(stack_a, cost_a, stack_b, cost_b);
		pb(stack_a, stack_b);
	}
	while (*stack_b)
		pa(stack_a, stack_b);
	rotate_to_min(stack_a);
}
