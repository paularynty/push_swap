/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prynty <prynty@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 12:00:11 by prynty            #+#    #+#             */
/*   Updated: 2024/07/24 14:44:13 by prynty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	check_dup(t_stack *stack, int nbr)
{
	while (stack != NULL)
	{
		if (stack->nbr == nbr)
			return (1);
		stack = stack->next;
	}
	return (0);
}

static int	add_to_stack(t_stack **stack, char *str)
{
	int		nbr;
	int		error;
	t_stack	*new_node;

	error = 0;
	nbr = parse_args(str, &error);
	if (error || check_dup(*stack, nbr))
		return (-1);
	new_node = new_stack_node(nbr);
	if (!new_node)
		return (-1);
	add_to_top(stack, new_node);
	return (0);
}

static void	add_from_string(t_stack **stack, char *str)
{
	char	**numbers;
	int		i;

	numbers = ft_split(str, ' ');
	if (!numbers)
		free_and_exit(*stack);
	i = 0;
	while (numbers[i] != NULL)
		i++;
	while (i > 0)
	{
		i--;
		if (add_to_stack(stack, numbers[i]) == -1)
		{
			free(numbers[i]);
			numbers[i] = NULL;
			free_array_and_exit(*stack, numbers);
		}
		free(numbers[i]);
	}
	free(numbers);
}

t_stack	*init_stack(int argc, char **argv)
{
	t_stack	*stack_a;
	int		i;

	stack_a = NULL;
	if (argc == 2)
	{
		if (argv[1] == NULL || *parse_whitespace(argv[1]) == '\0')
			free_and_exit(stack_a);
		add_from_string(&stack_a, argv[1]);
	}
	else
	{
		i = argc - 1;
		while (i > 0)
		{
			if (add_to_stack(&stack_a, argv[i]) == -1)
				free_and_exit(stack_a);
			i--;
		}
	}
	return (stack_a);
}
