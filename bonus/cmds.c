/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrescen <jcrescen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 14:49:20 by jcrescen          #+#    #+#             */
/*   Updated: 2023/04/27 15:23:20 by jcrescen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_cmd_r(char *line, t_list **stack_a, t_list **stack_b)
{
	if ((ft_strcmp(line, "ra")) == 0)
	{
		ft_rotate(stack_a);
		return (0);
	}
	if ((ft_strcmp(line, "rb")) == 0)
	{
		ft_rotate(stack_b);
		return (0);
	}
	else if ((ft_strcmp(line, "rr")) == 0)
	{
		ft_rotate(stack_a);
		ft_rotate(stack_b);
		return (0);
	}
	return (0);
}

int	ft_cmd_rr(char *line, t_list **stack_a, t_list **stack_b)
{
	if (!(ft_strcmp(line, "rra")))
	{
		ft_reverse_rotate(stack_a);
		return (0);
	}
	else if (!(ft_strcmp(line, "rrb")))
	{
		ft_reverse_rotate(stack_b);
		return (0);
	}	
	else if (!(ft_strcmp(line, "rrr")))
	{
		ft_reverse_rotate(stack_a);
		ft_reverse_rotate(stack_b);
		return (0);
	}
	else
	{
		ft_cmd_r(line, stack_a, stack_b);
		return (0);
	}
	return (0);
}

int	ft_cmd_p(char *line, t_list **stack_a, t_list **stack_b)
{
	if ((ft_strcmp(line, "pa")) == 0)
	{
		ft_push(stack_a, stack_b);
		return (0);
	}
	if ((ft_strcmp(line, "pb")) == 0)
	{
		ft_push(stack_b, stack_a);
		return (0);
	}
	else
	{
		ft_cmd_rr(line, stack_a, stack_b);
		return (0);
	}
	return (0);
}

int	ft_cmd_s(char *line, t_list **stack_a, t_list **stack_b)
{
	if ((ft_strcmp(line, "sa")) == 0)
	{
		ft_swap(stack_a);
		return (0);
	}
	if ((ft_strcmp(line, "sb")) == 0)
	{
		ft_swap(stack_b);
		return (0);
	}
	if ((ft_strcmp(line, "ss")) == 0)
	{
		ft_swap(stack_a);
		ft_swap(stack_b);
		return (0);
	}
	else
	{
		ft_cmd_p(line, stack_a, stack_b);
		return (0);
	}
	return (0);
}

int	ft_cmd_check(char *line, t_list **stack_a, t_list **stack_b)
{
	if (((ft_strncmp(line, "sa", 2)) == 0 || (ft_strncmp(line, "sb", 2)) == 0
			|| (ft_strncmp(line, "ss", 2)) == 0
			|| (ft_strncmp(line, "pa", 2)) == 0
			|| (ft_strncmp(line, "pb", 2)) == 0
			|| (ft_strncmp(line, "ra", 2)) == 0
			|| (ft_strncmp(line, "rb", 2)) == 0
			|| (ft_strncmp(line, "rr", 2)) == 0
			|| (ft_strncmp(line, "rra", 3)) == 0
			|| (ft_strncmp(line, "rrb", 3)) == 0
			|| (ft_strncmp(line, "rrr", 3)) == 0))
	{
		ft_cmd_s(line, stack_a, stack_b);
		return (0);
	}
	if (ft_strcmp(line, " "))
		return (1);
	else
		return (1);
}
