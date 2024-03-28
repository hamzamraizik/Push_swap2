/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmraizik <hmraizik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 03:26:52 by hmraizik          #+#    #+#             */
/*   Updated: 2024/03/28 03:26:52 by hmraizik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_mark_pos(t_list *lst)
{
	t_list	*tmp;
	t_list	*tmp1;
	int		j;

	tmp1 = lst;
	while (tmp1)
	{
		j = 0;
		tmp = lst;
		while (tmp)
		{
			if (tmp->data < tmp1->data)
				j++;
			tmp = tmp->next;
		}
		tmp1->index = j;
		tmp1 = tmp1->next;
	}
}

void	ft_mark(t_list *lst)
{
	t_list	*tmp;
	int		position;

	tmp = lst;
	position = 0;
	while (tmp)
	{
		tmp->position = position;
		position++;
		tmp = tmp->next;
	}
	ft_mark_pos(lst);
}

int	fin_max_pos(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp)
	{
		if (tmp->data > lst->data)
			lst = tmp;
		tmp = tmp->next;
	}
	return (lst->position);
}

void	push_to_b(t_list **a, t_list **b, int i, int x)
{
	t_list	*tmp;

	if (lstsize(*a) <= 100)
		x = 16;
	else
		x = 34;
	while (*a)
	{
		tmp = *a;
		if (tmp->index <= i)
		{
			ft_pb(a, b);
			i++;
		}
		else if (tmp->index < i + x)
		{
			ft_pb(a, b);
			rb(b);
			i++;
		}
		else
			ft_ra(a);
	}
}

void	push_to_a(t_list **a, t_list **b, int j, int i)
{
	j = lstsize(*b);
	while (j)
	{
		ft_mark(*b);
		i = fin_max_pos(*b);
		if (i <= j / 2)
		{
			while (i--)
				rb(b);
			ft_pa(b, a);
		}
		else
		{
			while (i < (j - 1))
			{
				ft_rrb(b);
				i++;
			}
			ft_rrb(b);
			ft_pa(b, a);
		}
		j--;
	}
}
