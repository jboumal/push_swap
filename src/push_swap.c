/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboumal <jboumal@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 18:06:22 by jboumal           #+#    #+#             */
/*   Updated: 2022/03/02 18:06:25 by jboumal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	sort5(t_stacks *stacks)
{
	int	k;

	k = stacks->a_size;
	while (stacks->a_size > 3)
	{
		if (stacks->a->n < k - 3)
			pb(stacks);
		else
			ra(stacks);
	}
	if (stacks->b_size == 2 && stacks->b->n < stacks->b->next->n)
		sb(stacks);
}

void	simple_sort(t_stacks *stacks)
{
	if (stacks->a_size == 2 && stacks->a->n > stacks->a->next->n)
	{
		sa(stacks);
		return ;
	}
	sort5(stacks);
	if (stacks->a->n > stacks->a->next->n
		&& stacks->a->n > stacks->a->next->next->n
		&& stacks->a->next->n < stacks->a->next->next->n)
	{
		rra(stacks);
		rra(stacks);
	}
	else
	{
		if (stacks->a->n > stacks->a->next->n)
			sa(stacks);
		if (stacks->a->next->n > stacks->a->next->next->n)
			rra(stacks);
		if (stacks->a->n > stacks->a->next->n)
			sa(stacks);
	}
	while (stacks->b_size)
		pa(stacks);
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;

	if (argc < 2)
		exit(EXIT_SUCCESS);
	stacks = init_stacks(argc - 1, argv + 1);
	if (is_sorted(stacks))
		return (0);
	normalize(stacks);
	if (stacks->a_size <= 5)
		simple_sort(stacks);
	else
		radix_sort(stacks, max_bit_weight(stacks->a));
	ft_printf("%s", stacks->op);
	free_stacks(stacks);
	return (0);
}
