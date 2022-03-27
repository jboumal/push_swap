/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboumal <jboumal@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 11:29:31 by jboumal           #+#    #+#             */
/*   Updated: 2022/03/03 11:29:37 by jboumal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	pa(t_stacks *stacks)
{
	t_stack	*stack;

	if (stacks->b)
	{
		stacks->a = lstadd_front(stacks->a, stacks->b->n);
		if (!stacks->a)
			free_and_exit(stacks);
		stack = stacks->b->next;
		free(stacks->b);
		stacks->b = stack;
		stacks->a_size += 1;
		stacks->b_size -= 1;
	}
	add_op(stacks, "pa\n");
}

void	pb(t_stacks *stacks)
{
	t_stack	*stack;

	if (stacks->a)
	{
		stacks->b = lstadd_front(stacks->b, stacks->a->n);
		if (!stacks->b)
			free_and_exit(stacks);
		stack = stacks->a->next;
		free(stacks->a);
		stacks->a = stack;
		stacks->a_size -= 1;
		stacks->b_size += 1;
	}
	add_op(stacks, "pb\n");
}
