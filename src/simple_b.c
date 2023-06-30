/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrescen <jcrescen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 14:30:40 by jcrescen          #+#    #+#             */
/*   Updated: 2023/06/30 16:58:01 by jcrescen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sort_3_expand(t_list *head, int min, int next_min, t_list **stack_a)
{
	if (head->index == min && head->next->index != next_min)
	{
		ft_ra(stack_a);
		ft_sa(stack_a);
		ft_rra(stack_a);
	}
	else if (head->index == next_min)
	{
		if (head->next->index == min)
			ft_sa(stack_a);
		else
			ft_rra(stack_a);
	}
	else
	{
		if (head->next->index == min)
			ft_ra(stack_a);
		else
		{
			ft_sa(stack_a);
			ft_rra(stack_a);
		}
	}
}

void	ft_sort_3(t_list **stack_a)
{
	t_list	*head;
	int		min;
	int		next_min;

	head = *stack_a;
	min = ft_get_min(stack_a, -1);
	next_min = ft_get_min(stack_a, min);
	if (ft_is_sorted(*stack_a))
		return ;
	ft_sort_3_expand(head, min, next_min, stack_a);
}
