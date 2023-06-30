/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrescen <jcrescen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 13:48:19 by jcrescen          #+#    #+#             */
/*   Updated: 2023/06/30 16:57:37 by jcrescen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_get_min(t_list **stack, int val)
{
	t_list	*head;
	int		min;

	head = *stack;
	min = head->index;
	while (head->next)
	{
		head = head->next;
		if ((head->index < min) && head->index != val)
			min = head->index;
	}
	return (min);
}

static void	ft_sort_4(t_list **stack_a, t_list **stack_b)
{
	int	distance;

	if (ft_is_sorted(*stack_a))
		return ;
	distance = ft_get_distance(stack_a, ft_get_min(stack_a, -1));
	if (distance == 1)
		ft_ra(stack_a);
	else if (distance == 2)
	{
		ft_ra(stack_a);
		ft_ra(stack_a);
	}
	else if (distance == 3)
		ft_rra(stack_a);
	if (ft_is_sorted(*stack_a))
		return ;
	ft_pb(stack_a, stack_b);
	ft_sort_3(stack_a);
	ft_pa(stack_a, stack_b);
}

void	ft_sort_5(t_list **stack_a, t_list **stack_b)
{
	int	distance;

	distance = ft_get_distance(stack_a, ft_get_min(stack_a, -1));
	if (distance == 1)
		ft_ra(stack_a);
	else if (distance == 2)
	{
		ft_ra(stack_a);
		ft_ra(stack_a);
	}
	else if (distance == 3)
	{
		ft_rra(stack_a);
		ft_rra(stack_a);
	}
	else if (distance == 4)
		ft_rra(stack_a);
	if (ft_is_sorted(*stack_a))
		return ;
	ft_pb(stack_a, stack_b);
	ft_sort_4(stack_a, stack_b);
	ft_pa(stack_a, stack_b);
}

void	ft_simple_sort(t_list **stack_a, t_list **stack_b)
{
	int	size;

	if (ft_is_sorted(*stack_a) || ft_lstsize(*stack_a) == 0
		|| ft_lstsize(*stack_a) == 1)
		return ;
	size = ft_lstsize(*stack_a);
	if (size == 2)
		ft_sa(stack_a);
	else if (size == 3)
		ft_sort_3(stack_a);
	else if (size == 4)
		ft_sort_4(stack_a, stack_b);
	else if (size == 5)
		ft_sort_5(stack_a, stack_b);
}
