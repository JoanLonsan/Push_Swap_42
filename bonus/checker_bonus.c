/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrescen <jcrescen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 13:49:02 by jcrescen          #+#    #+#             */
/*   Updated: 2023/04/27 13:59:42 by jcrescen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_do_commands(char *line, t_list **stack_a, t_list **stack_b)
{
	if (ft_strcmp(line, "s"))
		return (ft_cmd_s(line, stack_a, stack_b));
	else if (ft_strcmp(line, "p"))
		return (ft_cmd_p(line, stack_a, stack_b));
	else if (ft_strcmp(line, "rr"))
		return (ft_cmd_rr(line, stack_a, stack_b));
	else if (ft_strcmp(line, "ra") || ft_strcmp(line, "rb"))
		return (ft_cmd_r(line, stack_a, stack_b));
	return (1);
}

static void	ft_print_checker_res(t_list **stack_a, t_list **stack_b)
{
	if (ft_is_sorted(stack_a))
		ft_putendl_fd("OK\n", 1);
	else
		ft_putendl_fd("KO\n", 1);
	if (*stack_a)
		ft_free_stack(stack_a);
	if (*stack_b)
		ft_free_stack(stack_b);
}

static void	ft_init_stack(t_list **stack, int argc, char **argv)
{
	t_list	*new;
	char	**args;
	int		i;

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	while (args[i])
	{
		new = ft_lstnew(ft_atoi(args[i]));
		ft_lstadd_back(stack, new);
		i++;
	}
	ft_index_stack(stack);
	if (argc == 2)
		ft_free(args);
}

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;
	char	*line;

	if (argc < 2)
		return (0);
	stack_a = (t_list **)malloc(sizeof(t_list));
	stack_b = (t_list **)malloc(sizeof(t_list));
	*stack_a = NULL;
	*stack_b = NULL;
	ft_check_args(argc, argv);
	ft_init_stack(stack_a, argc, argv);
	while (get_next_line(0, &line))
	{
		if (ft_cmd_check(line, stack_a, stack_b))
		{
			ft_error("Error");
			return (-1);
		}
		free(line);
	}
	ft_print_checker_res(stack_a, stack_b);
	return (0);
}
