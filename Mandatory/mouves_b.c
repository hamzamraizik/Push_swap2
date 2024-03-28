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

// void    rotat(t_list**lst)
// {
//     t_list   *tmp;
//     t_list   *last;

//     if (!lst || !*lst || !(*lst)->next)
//         return ;
//     tmp = *lst;
//     last = *lst;
//     while (last->next)
//         last = last->next;
//     *lst = (*lst)->next;
//     last->next = tmp;
//     tmp->next = NULL;
// }

// void    rb(t_list **b)
// {
//     rotat(b);
//     write(1, "rb\n", 3);
// }

// void rb(t_list **b)
// {
//     if (lstsize(*b) <= 1)
//         return;

//     t_list *last = *b;
//     t_list *second = (*b)->next;

//     // Find the last node
//     while (last->next)
//         last = last->next;

//     last->next = *b; // Make the last node point to the first node
//     *b = second; // Update the head pointer to the second node
//     last->next->next = NULL; // Set the next pointer of the new last node to NULL

//     write(1, "rb\n", 3);
// }

// void rb(t_list **b)
// {
//     t_list *curr;
//     t_list *prev;
//     t_list *tmp;

//     if (lstsize(*b) < 2)
//         return ;
//     tmp = *b;
//     curr = *b;
//     prev = (*b)->next;
//     while(curr->next)
//         curr = curr->next;
//     curr->next = tmp;
//     tmp->next = NULL;
//     (*b) = prev;
//     write(1, "rb\n", 3);
// }

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
