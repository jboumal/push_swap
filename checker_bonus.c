/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboumal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 13:57:15 by jboumal           #+#    #+#             */
/*   Updated: 2022/03/10 13:57:17 by jboumal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "checker_bonus.h"

static void	arg_error(t_stacks *stacks)
{
	ft_putstr_fd("Error\n", 2);
	free_and_exit(stacks);
}

static void	do_op(t_stacks *stacks, char *buf)
{
	if (ft_strncmp(buf, "sa\n", 3) == 0)
		sa(stacks);
	else if (ft_strncmp(buf, "sb\n", 3) == 0)
		sb(stacks);
	else if (ft_strncmp(buf, "ss\n", 3) == 0)
		ss(stacks);
	else if (ft_strncmp(buf, "ra\n", 3) == 0)
		ra(stacks);
	else if (ft_strncmp(buf, "rb\n", 3) == 0)
		rb(stacks);
	else if (ft_strncmp(buf, "rr\n", 3) == 0)
		rr(stacks);
	else if (ft_strncmp(buf, "rra\n", 4) == 0)
		rra(stacks);
	else if (ft_strncmp(buf, "rrb\n", 4) == 0)
		rrb(stacks);
	else if (ft_strncmp(buf, "rrr\n", 4) == 0)
		rrr(stacks);
	else if (ft_strncmp(buf, "pa\n", 3) == 0)
		pa(stacks);
	else if (ft_strncmp(buf, "pb\n", 3) == 0)
		pb(stacks);
	else
		arg_error(stacks);
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;
	char		*line;

	if (argc < 2)
		exit(EXIT_SUCCESS);
	stacks = init_stacks(argc - 1, argv + 1);
	line = get_next_line(0);
	while (line)
	{
		do_op(stacks, line);
		line = get_next_line(0);
	}
	if (is_sorted(stacks) && !stacks->b)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return (0);
}
