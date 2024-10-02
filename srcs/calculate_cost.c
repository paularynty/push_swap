/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prynty <prynty@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:22:18 by prynty            #+#    #+#             */
/*   Updated: 2024/07/23 18:06:17 by prynty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*find_cheapest(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*cheapest_elem;
	t_stack	*current;
	int		min_cost;
	int		cost;

	cheapest_elem = NULL;
	min_cost = INT_MAX;
	current = stack_a;
	while (current)
	{
		cost = calculate_cost(stack_a, stack_b, current->nbr);
		if (cost < min_cost)
		{
			min_cost = cost;
			cheapest_elem = current;
		}
		current = current->next;
	}
	return (cheapest_elem);
}

int	single_rotate_cost(int size, int pos)
{
	int	forward;
	int	reverse;

	forward = pos;
	reverse = size - pos;
	if (forward <= reverse)
		return (forward);
	else
		return (-reverse);
}

static int	combo_rotate_cost(int *cost_a, int *cost_b, bool forward)
{
	int	total_cost;

	total_cost = 0;
	if (forward)
	{
		while (*cost_a > 0 && *cost_b > 0)
		{
			(*cost_a)--;
			(*cost_b)--;
			total_cost++;
		}
	}
	else
	{
		while (*cost_a < 0 && *cost_b < 0)
		{
			(*cost_a)++;
			(*cost_b)++;
			total_cost++;
		}
	}
	return (total_cost);
}

static int	total_cost(int cost_a, int cost_b)
{
	int	total_cost;

	total_cost = 0;
	if (cost_a > 0 && cost_b > 0)
	{
		total_cost = combo_rotate_cost(&cost_a, &cost_b, true);
		total_cost += ft_abs(cost_a) + ft_abs(cost_b);
	}
	else if (cost_a < 0 && cost_b < 0)
	{
		total_cost = combo_rotate_cost(&cost_a, &cost_b, false);
		total_cost += ft_abs(cost_a) + ft_abs(cost_b);
	}
	else
		total_cost = ft_abs(cost_a) + ft_abs(cost_b);
	return (total_cost);
}

int	calculate_cost(t_stack *stack_a, t_stack *stack_b, int nbr)
{
	int	pos_a;
	int	pos_b;
	int	cost_a;
	int	cost_b;

	pos_a = find_index(stack_a, nbr);
	pos_b = find_pos_in_b(stack_b, nbr);
	cost_a = single_rotate_cost(stack_size(stack_a), pos_a);
	cost_b = single_rotate_cost(stack_size(stack_b), pos_b);
	return (total_cost(cost_a, cost_b));
}
