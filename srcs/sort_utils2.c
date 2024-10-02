/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prynty <prynty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 19:39:51 by prynty            #+#    #+#             */
/*   Updated: 2024/07/19 17:42:21 by prynty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_index(t_stack *stack, int nbr)
{
	int	i;

	i = 0;
	while (stack->nbr != nbr)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

int	find_pos_in_b(t_stack *stack_b, int nbr)
{
	t_stack	*temp;
	int		position;

	if (nbr > stack_b->nbr && nbr < find_last(stack_b)->nbr)
		position = 0;
	else if (nbr > biggest_nbr(stack_b) || nbr < smallest_nbr(stack_b))
		position = find_index(stack_b, biggest_nbr(stack_b));
	else
	{
		position = 1;
		temp = stack_b->next;
		while (stack_b->nbr < nbr || temp->nbr > nbr)
		{
			stack_b = stack_b->next;
			temp = stack_b->next;
			position++;
		}
	}
	return (position);
}

void	rotate_to_min(t_stack **stack_a)
{
	int	min_val;
	int	pos_in_a;
	int	size;

	min_val = smallest_nbr(*stack_a);
	pos_in_a = find_index(*stack_a, min_val);
	size = stack_size(*stack_a);
	if (pos_in_a <= size / 2)
	{
		while ((*stack_a)->nbr != min_val)
			ra(stack_a);
	}
	else
	{
		while ((*stack_a)->nbr != min_val)
			rra(stack_a);
	}
}
