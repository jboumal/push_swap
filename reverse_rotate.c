/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboumal <jboumal@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 15:28:46 by jboumal           #+#    #+#             */
/*   Updated: 2022/03/03 15:28:48 by jboumal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*reverse_rotate(t_stack *s)
{
	t_stack	*last;
	t_stack	*before_last;

	if (s && s->next)
	{
		last = lst_last(s);
		before_last = lst_before_last(s);
		last->next = s;
		before_last->next = NULL;
		s = last;
	}
	return (s);
}

void	rra(t_stacks *stacks)
{
	stacks->a = reverse_rotate(stacks->a);
	add_op(stacks, "rra\n");
}

void	rrb(t_stacks *stacks)
{
	stacks->b = reverse_rotate(stacks->b);
	add_op(stacks, "rrb\n");
}

void	rrr(t_stacks *stacks)
{
	stacks->a = reverse_rotate(stacks->a);
	stacks->b = reverse_rotate(stacks->b);
	add_op(stacks, "rrr\n");
}
