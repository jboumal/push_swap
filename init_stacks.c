/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboumal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 14:10:29 by jboumal           #+#    #+#             */
/*   Updated: 2022/03/10 14:10:31 by jboumal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int	check_arg(t_stacks *stacks, char *arg)
{
	int		i;
	t_stack	*a;

	i = 0;
	if (!arg || !*arg || ((arg[i] < '0' || arg[i] > '9') && arg[i] != '-'))
		return (0);
	while (arg[++i])
	{
		if (arg[i] < '0' || arg[i] > '9')
			return (0);
	}
	i = ft_atoi(arg);
	if (i == 0 && (arg[0] != '0' || arg[1] != '\0'))
		return (0);
	if (i == -1 && (arg[0] != '-' || arg[1] != '1' || arg[2] != '\0'))
		return (0);
	a = stacks->a;
	while (a)
	{
		if (a->n == i)
			return (0);
		a = a->next;
	}
	return (1);
}

t_stacks	*init_stacks(int n, char **numbers)
{
	t_stacks	*stacks;

	stacks = malloc(sizeof(t_stacks));
	if (!stacks)
		exit(EXIT_FAILURE);
	stacks->b = NULL;
	stacks->a = NULL;
	stacks->a_size = n;
	stacks->b_size = 0;
	stacks->op = malloc(sizeof(char));
	stacks->op[0] = '\0';
	if (!stacks->op)
		free_and_exit(stacks);
	while (--n >= 0)
	{
		if (!check_arg(stacks, numbers[n]))
		{
			ft_putstr_fd("Error\n", 2);
			free_and_exit(stacks);
		}
		stacks->a = lstadd_front(stacks->a, ft_atoi(numbers[n]));
		if (!stacks->a)
			free_and_exit(stacks);
	}
	return (stacks);
}
