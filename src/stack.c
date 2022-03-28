/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboumal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 11:50:26 by jboumal           #+#    #+#             */
/*   Updated: 2022/03/17 11:50:28 by jboumal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_a(t_stacks *stacks)
{
	t_stack	*stack;

	while (stacks->a)
	{
		stack = stacks->a;
		stacks->a = stacks->a->next;
		free(stack);
	}
}

void	normalize(t_stacks *stacks)
{
	t_stack	*new;
	t_stack	*a;
	t_stack	*a2;
	int		i;

	a = stacks->a;
	new = NULL;
	while (a)
	{
		a2 = stacks->a;
		i = 0;
		while (a2)
		{
			if (a->n > a2->n)
				i++;
			a2 = a2->next;
		}
		new = lstadd_back(new, i);
		if (!new)
			free_and_exit(stacks);
		a = a->next;
	}
	free_a(stacks);
	stacks->a = new;
}
