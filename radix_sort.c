/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboumal <jboumal@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 13:31:19 by jboumal           #+#    #+#             */
/*   Updated: 2022/03/04 13:31:21 by jboumal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	max_bit_weight(t_stack *a)
{
	int		i;
	t_stack	*t;
	int		found;

	i = 0;
	found = 1;
	while (found)
	{
		t = a;
		found = 0;
		while (t)
		{
			if ((t->n >> i) & 1)
			{
				found = 1;
				break ;
			}
			t = t->next;
		}
		if (!found)
			return (i);
		i++;
	}
	return (i);
}

static void	odd_stacks(t_stacks *stacks)
{
	if (stacks->b_size % 2 == 1)
	{
		pa(stacks);
		if (stacks->a->n > stacks->a->next->n)
			sa(stacks);
		ra(stacks);
		ra(stacks);
	}
}

static void	radix_last(t_stacks *stacks)
{
	int	j;

	while (stacks->b_size > stacks->a_size)
		pa(stacks);
	odd_stacks(stacks);
	j = stacks->b_size;
	while (j > 0)
	{
		if (stacks->a->n > stacks->a->next->n)
		{
			if (stacks->b->n < stacks->b->next->n)
				ss(stacks);
			else
				sa(stacks);
		}
		else if (stacks->b->n < stacks->b->next->n)
			sb(stacks);
		rr(stacks);
		rr(stacks);
		j -= 2;
	}
	if ((stacks->a_size - stacks->b_size) % 2 == 1)
		ra(stacks);
	while (stacks->b_size)
		pa(stacks);
}

void	radix_sort(t_stacks *stacks, int max)
{
	int	i;
	int	j;

	i = 0;
	while (++i < max)
	{
		j = stacks->a_size + 1;
		while (--j > 0)
		{
			if (!(stacks->a->n >> i & 1))
				pb(stacks);
			else
				ra(stacks);
		}
		j = stacks->b_size + 1;
		while (--j > 0 && i != max - 1)
		{
			if (i + 1 < max && !(stacks->b->n >> (i + 1) & 1))
				rb(stacks);
			else
				pa(stacks);
		}
		if (i == max - 1)
			radix_last(stacks);
	}
}
