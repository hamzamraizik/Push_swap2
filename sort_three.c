#include "push_swap.h"

void sort_three(t_list **stack)
{
	int		first;
	int		middle;
	int		last;

	first = (*stack)->data;
	middle = (*stack)->next->data;
	last = (*stack)->next->next->data;
	if ((first < middle) && (middle < last))
		exit(0);
	if ((first < middle) && (middle > last) && (last > first))
	{
		ft_rra(stack);
		ft_sa(stack);
	}
	if ((first > middle) && (middle < last) && (last > first))
		ft_sa(stack);
	if ((first < middle) && (middle > last) && (last < first))
		ft_rra(stack);
	if ((first > middle) && (middle < last) && (last < first))
		ft_ra(stack);
	if ((first > middle) && (middle > last))
	{
		ft_sa(stack);
		ft_rra(stack);
	}
}
