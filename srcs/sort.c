/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prynty <prynty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 17:47:48 by prynty            #+#    #+#             */
/*   Updated: 2024/07/18 14:14:40 by prynty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three(t_stack **stack_a)
{
	int	first;
	int	second;
	int	third;

	first = (*stack_a)->nbr;
	second = (*stack_a)->next->nbr;
	third = (*stack_a)->next->next->nbr;
	if (first > second && first < third)
		sa(stack_a);
	else if (first > second && second > third)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (first > second && second < third)
		ra(stack_a);
	else if (first < second && first > third)
		rra(stack_a);
	else if (first < third && second > third)
	{
		sa(stack_a);
		ra(stack_a);
	}
}

void	sort_small(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = stack_size(*stack_a);
	if (size == 2)
		sa(stack_a);
	else
	{
		while (size > 3 && !check_sorted(*stack_a))
		{
			rotate_to_min(stack_a);
			pb(stack_a, stack_b);
			size--;
		}
		sort_three(stack_a);
		while (*stack_b)
			pa(stack_a, stack_b);
	}
}

void	sort_stack(t_stack **stack_a)
{
	t_stack	*stack_b;
	int		size;

	stack_b = NULL;
	size = stack_size(*stack_a);
	if (size <= 10)
		sort_small(stack_a, &stack_b);
	else
		sort_big(stack_a, &stack_b);
	free_stack(stack_b);
}
