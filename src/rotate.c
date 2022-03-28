/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboumal <jboumal@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 14:30:57 by jboumal           #+#    #+#             */
/*   Updated: 2022/03/03 14:30:59 by jboumal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static t_stack	*rotate(t_stack *s)
{
	t_stack	*tmp;

	if (s && s->next)
	{
		tmp = lst_last(s);
		tmp->next = s;
		tmp = s->next;
		s->next = NULL;
		s = tmp;
	}
	return (s);
}

void	ra(t_stacks *stacks)
{
	stacks->a = rotate(stacks->a);
	add_op(stacks, "ra\n");
}

void	rb(t_stacks *stacks)
{
	stacks->b = rotate(stacks->b);
	add_op(stacks, "rb\n");
}

void	rr(t_stacks *stacks)
{
	stacks->a = rotate(stacks->a);
	stacks->b = rotate(stacks->b);
	add_op(stacks, "rr\n");
}
