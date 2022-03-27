/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboumal <jboumal@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 22:45:25 by jboumal           #+#    #+#             */
/*   Updated: 2022/03/02 22:45:27 by jboumal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "printf/ft_printf.h"

typedef struct s_stack
{
	int				n;
	struct s_stack	*next;
}					t_stack;

typedef struct s_stacks
{
	t_stack	*a;
	t_stack	*b;
	int		a_size;
	int		b_size;
	char	*op;
}					t_stacks;

t_stack		*lstadd_front(t_stack *list, int n);
t_stack		*lstnew(int n);
t_stack		*lst_last(t_stack *lst);
t_stack		*lst_before_last(t_stack *lst);
t_stack		*lstadd_back(t_stack *list, int n);

t_stacks	*init_stacks(int n, char **numbers);
int			is_sorted(t_stacks *stacks);
void		radix_sort(t_stacks *stacks, int max);
void		normalize(t_stacks *stacks);
void		add_op(t_stacks *stacks, char *op);
void		free_stacks(t_stacks *stacks);
void		free_and_exit(t_stacks *stacks);
int			max_bit_weight(t_stack *a);

void		sa(t_stacks *stacks);
void		sb(t_stacks *stacks);
void		ss(t_stacks *stacks);
void		pa(t_stacks *stacks);
void		pb(t_stacks *stacks);
void		ra(t_stacks *stacks);
void		rb(t_stacks *stacks);
void		rr(t_stacks *stacks);
void		rra(t_stacks *stacks);
void		rrb(t_stacks *stacks);
void		rrr(t_stacks *stacks);

#endif