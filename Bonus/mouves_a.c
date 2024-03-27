#include "checker.h"

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

// void ft_rb(t_list **stack_b)
// {
// 	t_list	*tmp;
// 	t_list	*tmp2;

// 	tmp2 = (*stack_b);
// 	tmp = (*stack_b);
// 	if (!tmp)
// 		return ;
// 	while(tmp->next)
// 	{
// 		tmp = tmp->next;
// 		// printf("tmp:%d\n",tmp == NULL);
// 	}	
// 	tmp->next = (*stack_b);
// 	(*stack_b) = (*stack_b)->next;
// 	tmp2->next = NULL;
// 	write(1, "rb\n", 3);
// }

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

// void	ft_rrb(t_list **stack_b)
// {
// 	t_list	*tmp;
// 	t_list	*last;

// 	tmp = (*stack_b);
// 	if(!tmp)
// 		exit(0);
// 	while(tmp->next->next)
// 		tmp = tmp->next;
// 	last = tmp->next;
// 	last->next = (*stack_b);
// 	tmp->next = NULL;
// 	(*stack_b) = last;
// 	write(1, "rrb\n", 4);
// }

void	ft_rrr(t_list **stack_a, t_list **stack_b)
{
	t_list		*tmp;
	t_list		*last;
//for reverse rotate stack_a
	tmp = (*stack_a);
	while (tmp->next->next)
		tmp = tmp->next;
	last = tmp->next;
	tmp->next = NULL;
	last->next = (*stack_a);
	(*stack_a) = last;
//the same function for stack_b
	tmp = (*stack_b);
	while (tmp->next->next)
		tmp = tmp->next;
	last = tmp->next;
	last->next = (*stack_b);
	tmp->next = NULL;
	(*stack_b) = last;
	write(1, "rrr\n", 4);
}

// void	ft_pa(t_list **stack_a, t_list **stack_b)
// {
// 	t_list	*tmp;

// 	tmp = (*stack_b);
// 	if (!(tmp))
// 		exit(1);
// 	(*stack_b) = (*stack_b)->next;
// 	tmp->next = (*stack_a);
// 	(*stack_a) = tmp;
// 	write(1, "pa\n", 3);
// }

// void	ft_pb(t_list **stack_a, t_list **stack_b)
// {
// 	t_list	*tmp;

// 	tmp = (*stack_a);
// 	if (!tmp)
// 		return ;
// 	(*stack_a)=(*stack_a)->next;
// 	tmp->next = (*stack_b);
// 	(*stack_b) = tmp;
// 	write(1, "pb\n", 3);
// }
