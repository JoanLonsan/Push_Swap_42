/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrescen <jcrescen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 13:47:57 by jcrescen          #+#    #+#             */
/*   Updated: 2023/06/30 18:15:07 by jcrescen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_sort_stack(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) <= 5)
		ft_simple_sort(stack_a, stack_b);
	else
		ft_radix_sort(stack_a, stack_b);
}

/*void	leaks(void)
{
	system("leaks -q push_swap");
}*/

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	// atexit(leaks);

	if (argc < 2)
		return (-1);
	stack_a = NULL;
	stack_b = NULL;
	ft_check_args(argv, &stack_a);
	if (ft_is_sorted(stack_a))
	{
		ft_free_stack(stack_a);
		ft_free_stack(stack_b);
		return (0);
	}
	ft_sort_stack(&stack_a, &stack_b);
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
	return (0);
}
