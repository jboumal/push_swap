/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboumal <jboumal@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 10:45:33 by jboumal           #+#    #+#             */
/*   Updated: 2022/03/04 10:45:35 by jboumal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	add_op(t_stacks *stacks, char *op)
{
	char	*old;

	old = stacks->op;
	stacks->op = ft_strjoin(stacks->op, op);
	free(old);
	if (!stacks->op)
		free_and_exit(stacks);
}

void	free_stacks(t_stacks *stacks)
{
	t_stack	*stack;

	if (!stacks)
		exit(EXIT_FAILURE);
	while (stacks->a)
	{
		stack = stacks->a;
		stacks->a = stacks->a->next;
		free(stack);
	}
	while (stacks->b)
	{
		stack = stacks->b;
		stacks->b = stacks->b->next;
		free(stack);
	}
	if (stacks->op)
		free(stacks->op);
	free(stacks);
}

void	free_and_exit(t_stacks *stacks)
{
	free_stacks(stacks);
	exit(EXIT_FAILURE);
}

int	is_sorted(t_stacks *stacks)
{
	int		last;
	t_stack	*a;
	t_stack	*b;

	a = stacks->a;
	b = stacks->b;
	if (b)
		return (0);
	last = a->n;
	a = a->next;
	while (a)
	{
		if (a->n < last)
			return (0);
		last = a->n;
		a = a->next;
	}
	return (1);
}
