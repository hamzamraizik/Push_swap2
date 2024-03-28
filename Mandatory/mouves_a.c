/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouves_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmraizik <hmraizik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 03:25:41 by hmraizik          #+#    #+#             */
/*   Updated: 2024/03/28 03:25:41 by hmraizik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_list **stack_a)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp2 = (*stack_a);
	tmp = (*stack_a);
	(*stack_a) = (*stack_a)->next;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = tmp2;
	tmp2->next = NULL;
	write(1, "ra\n", 3);
}

void	ft_pa(t_list **b, t_list **a)
{
	t_list	*tmp;

	if (lstsize(*b) < 1)
		return ;
	tmp = *b;
	*b = (*b)->next;
	if (*b)
		(*b)->previus = NULL;
	if (!(*a))
	{
		*a = tmp;
		(*a)->previus = NULL;
		(*a)->next = NULL;
	}
	else
	{
		(*a)->previus = tmp;
		tmp->next = *a;
		*a = tmp;
		(*a)->previus = NULL;
	}
	write(1, "pa\n", 3);
}
// ____________________________________

void	ft_rr(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = (*stack_a);
	tmp2 = (*stack_a);
	(*stack_a) = (*stack_a)->next;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = tmp2;
	tmp2->next = NULL;
	tmp2 = (*stack_b);
	tmp = (*stack_b);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = (*stack_b);
	(*stack_b) = (*stack_b)->next;
	tmp2->next = NULL;
	write(1, "rr\n", 3);
}

void	ft_rra(t_list **stack_a)
{
	t_list	*tmp;
	t_list	*last;

	tmp = (*stack_a);
	while (tmp->next->next)
		tmp = tmp->next;
	last = tmp->next;
	tmp->next = NULL;
	last->next = (*stack_a);
	(*stack_a) = last;
	write(1, "rra\n", 4);
}

void	ft_rrr(t_list **stack_a, t_list **stack_b)
{
	t_list		*tmp;
	t_list		*last;

	tmp = (*stack_a);
	while (tmp->next->next)
		tmp = tmp->next;
	last = tmp->next;
	tmp->next = NULL;
	last->next = (*stack_a);
	(*stack_a) = last;
	tmp = (*stack_b);
	while (tmp->next->next)
		tmp = tmp->next;
	last = tmp->next;
	last->next = (*stack_b);
	tmp->next = NULL;
	(*stack_b) = last;
	write(1, "rrr\n", 4);
}
