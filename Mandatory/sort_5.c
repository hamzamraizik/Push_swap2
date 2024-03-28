/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmraizik <hmraizik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 03:26:43 by hmraizik          #+#    #+#             */
/*   Updated: 2024/03/28 03:26:43 by hmraizik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_index(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp)
	{
		if (tmp->data < lst->data)
			lst = tmp;
		tmp = tmp->next;
	}
	return (lst->position);
}

void	sort5(t_list **stack, t_list **stack_b)
{
	int		i;

	ft_mark(*stack);
	while (lstsize(*stack) > 3)
	{
		i = find_min_index(*stack);
		if (i <= 3)
		{
			while ((*stack)->position != i)
				ft_ra(stack);
		}
		else if (i > 3)
		{
			while ((*stack)->position != i)
				ft_rra(stack);
		}
		ft_pb(stack, stack_b);
	}
	sort_three(stack);
	ft_pa(stack_b, stack);
	ft_pa(stack_b, stack);
}
