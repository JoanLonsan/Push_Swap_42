/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrescen <jcrescen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 13:44:21 by jcrescen          #+#    #+#             */
/*   Updated: 2023/06/30 17:06:45 by jcrescen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

// Stack
typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
}				t_list;

t_list	*ft_lstnew(int value);
t_list	*ft_lstlast(t_list *head);
void	ft_lstadd_front(t_list **stack, t_list *new);
void	ft_lstadd_back(t_list **stack, t_list *new);
void	ft_print_list(t_list *head);
int		ft_lstsize(t_list *head);
void	ft_error(char *msg);
void	ft_check_args(char **argv, t_list **stack);
int		ft_is_sorted(t_list *stack);
int		ft_get_distance(t_list **stack, int index);
void	ft_make_top(t_list **stack, int distance);
void	ft_free_stack(t_list *stack);
void	ft_free(char **str);
void	ft_radix_sort(t_list **stack_a, t_list **stack_b);
void	ft_simple_sort(t_list **stack_a, t_list **stack_b);
void	ft_index_stack(t_list **stack);
void	ft_sort_5(t_list **stack_a, t_list **stack_b);
void	ft_sort_3(t_list **stack_a);
int		ft_get_min(t_list **stack, int val);

int		ft_swap(t_list **stack);
int		ft_sa(t_list **stack_a);
int		ft_sb(t_list **stack_b);
int		ft_ss(t_list **stack_a, t_list **stack_b);
int		ft_push(t_list **stack_to, t_list **stack_from);
int		ft_pa(t_list **stack_a, t_list **stack_b);
int		ft_pb(t_list **stack_b, t_list **stack_a);
int		ft_rotate(t_list **stack);
int		ft_ra(t_list **stack_a);
int		ft_rb(t_list **stack_b);
int		ft_rr(t_list **stack_a, t_list **stack_b);
int		ft_reverse_rotate(t_list **stack);
int		ft_rra(t_list **stack_a);
int		ft_rrb(t_list **stack_b);
int		ft_rrr(t_list **stack_a, t_list **stack_b);

int		ft_cmd_check(char *line, t_list **stack_a, t_list **stack_b);
int		ft_cmd_s(char *line, t_list **stack_a, t_list **stack_b);
int		ft_cmd_p(char *line, t_list **stack_a, t_list **stack_b);
int		ft_cmd_rr(char *line, t_list **stack_a, t_list **stack_b);
int		ft_cmd_r(char *line, t_list **stack_a, t_list **stack_b);

#endif
