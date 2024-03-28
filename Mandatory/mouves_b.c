/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouves_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmraizik <hmraizik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 03:25:46 by hmraizik          #+#    #+#             */
/*   Updated: 2024/03/28 03:25:46 by hmraizik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_list **b)
{
	t_list	*tmp;

	tmp = *b;
	if (lstsize(*b) <= 1)
		return ;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *b;
	(*b)->previus = tmp;
	(*b) = (*b)->next;
	(*b)->previus->next = NULL;
	(*b)->previus = NULL;
	write(1, "rb\n", 3);
}

void	ft_pb(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (lstsize(*a) < 1)
		return ;
	tmp = *a;
	*a = (*a)->next;
	if (*a)
		(*a)->previus = NULL;
	if (!(*b))
	{
		*b = tmp;
		(*b)->previus = NULL;
		(*b)->next = NULL;
	}
	else
	{
		(*b)->previus = tmp;
		tmp->next = *b;
		*b = tmp;
		(*b)->previus = NULL;
	}
	write(1, "pb\n", 3);
}

void	ft_rrb(t_list **stack_b)
{
	t_list	*tmp;

	tmp = *stack_b;
	if (lstsize(*stack_b) <= 1)
		return ;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *stack_b;
	(*stack_b)->previus = tmp;
	tmp->previus->next = NULL;
	*stack_b = tmp;
	(*stack_b)->previus = NULL;
	write(1, "rrb\n", 4);
}
