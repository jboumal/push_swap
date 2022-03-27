/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboumal <jboumal@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 11:45:05 by jboumal           #+#    #+#             */
/*   Updated: 2022/03/03 11:45:07 by jboumal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

t_stack	*lst_last(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		(lst = lst->next);
	return (lst);
}

t_stack	*lst_before_last(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next->next)
		(lst = lst->next);
	return (lst);
}

t_stack	*lstnew(int n)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->n = n;
	new->next = NULL;
	return (new);
}

t_stack	*lstadd_front(t_stack *list, int n)
{
	t_stack	*new;

	new = lstnew(n);
	new->next = list;
	return (new);
}

t_stack	*lstadd_back(t_stack *list, int n)
{
	t_stack	*new;
	t_stack	*last;

	new = lstnew(n);
	if (!list)
		return (new);
	last = lst_last(list);
	last->next = new;
	return (list);
}
