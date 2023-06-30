/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrescen <jcrescen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 13:48:28 by jcrescen          #+#    #+#             */
/*   Updated: 2023/06/30 18:43:57 by jcrescen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_is_duplicate(int num, t_list *stack)
{
	while (stack != NULL)
	{
		if (stack->value == num)
			return (1);
		stack = stack->next;
	}
	return (0);
}

static int	ft_isnum(char *num)
{
	int	i;

	i = 0;
	if ((num[i] == '-' || num[i] == '+')
		&& (num[i + 1] == '\0' || num[i + 1] == 32))
		return (1);
	else if (num[i] == '-' || num[i] == '+')
		i++;
	while (num && num[i])
	{
		if (!ft_isdigit(num[i++]))
			return (1);
	}
	return (0);
}

void	ft_check_args(char **argv, t_list **stack)
{
	int		i;
	int		j;
	char	**args;
	long	temp;

	i = 0;
	while (argv[++i] != NULL)
	{
		j = -1;
		args = ft_split(argv[i], ' ');
		while (args[++j] != NULL)
		{
			if (ft_isnum (args[j]))
				ft_error("Error");
			temp = ft_atoi(args[j]);
			if (ft_is_duplicate(temp, *stack))
				ft_error("Error");
			if (temp < -2147483648 || temp > 2147483647)
				ft_error("Error");
			ft_lstadd_back(stack, ft_lstnew(ft_atoi(args[j])));
		}
		ft_free(args);
		free(args);
	}
}
