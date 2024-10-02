/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prynty <prynty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:26:22 by prynty            #+#    #+#             */
/*   Updated: 2024/07/15 15:16:12 by prynty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_stack(t_stack *stack)
{
	t_stack	*temp;

	while (stack)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}

void	free_array_and_exit(t_stack *stack, char **numbers)
{
	int	i;

	i = 0;
	if (numbers)
	{
		while (numbers[i])
		{
			free(numbers[i]);
			numbers[i] = NULL;
			i++;
		}
		free(numbers);
	}
	free_and_exit(stack);
}

void	free_and_exit(t_stack *stack)
{
	if (stack)
		free_stack(stack);
	print_error();
}

void	print_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}
