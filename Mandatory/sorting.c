/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmraizik <hmraizik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 03:26:52 by hmraizik          #+#    #+#             */
/*   Updated: 2024/03/30 07:02:57 by hmraizik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	positioning(t_list *stack)
{
	int		position;

	position = 0;
	while (stack)
	{
		stack->position = position;
		position++;
		stack = stack->next;
	}
}

int	the_biggest(t_list *stack)
{
	t_list	*tmp;

	tmp = stack;
	while (tmp)
	{
		if (tmp->data > stack->data)
			stack = tmp;
		tmp = tmp->next;
	}
	return (stack->position);
}

// the threshold , smaller threshold may
	//result in more frequent but smaller movements of elements to stack_b
		// big treshold may result fewwer but more movement;
void	semi_sorting(t_list **stack_a, t_list **stack_b)
{
	int	i;
	int	threshold;

	i = 0;
	while (*stack_a)
	{
		if (lstsize(*stack_a) <= 100)
			threshold = lstsize(*stack_a) / 4;
		else
			threshold = lstsize(*stack_a) / 8;
		if ((*stack_a)->index <= i)
		{
			ft_pb(stack_a, stack_b);
			i++;
		}
		else if ((*stack_a)->index <= i + threshold)
		{
			ft_pb(stack_a, stack_b);
			//it will in the top i shold make it in the bottom , the smaller became in the top
			rb(stack_b);
			i++;
		}
		else
			ft_ra(stack_a);
	}
}

void	last_sorting(t_list **stack_a, t_list **stack_b, int j, int i)
{
	j = lstsize(*stack_b) + 1;
	while (--j)
	{
		positioning(*stack_b);
		i = the_biggest(*stack_b);
		if (i <= j / 2)
		{
			while (i--)
				rb(stack_b);
			ft_pa(stack_b, stack_a);
		}
		else
		{
			while (i++ < j)
				ft_rrb(stack_b);
			ft_pa(stack_b, stack_a);
		}
	}
}
