/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboumal <jboumal@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 11:19:59 by jboumal           #+#    #+#             */
/*   Updated: 2022/03/03 11:20:02 by jboumal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	swap(t_stack *s)
{
	int	tmp;

	if (s && s->next)
	{
		tmp = s->n;
		s->n = s->next->n;
		s->next->n = tmp;
	}
}

void	sa(t_stacks *stacks)
{
	swap(stacks->a);
	add_op(stacks, "sa\n");
}

void	sb(t_stacks *stacks)
{
	swap(stacks->b);
	add_op(stacks, "sb\n");
}

void	ss(t_stacks *stacks)
{
	swap(stacks->a);
	swap(stacks->b);
	add_op(stacks, "ss\n");
}
