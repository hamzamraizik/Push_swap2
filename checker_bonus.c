#include "push_swap.h"

void	storing(t_list **stack_a, char **res2)
{
	int		num;
	int		i;

	i = 1;
	(*stack_a)->index = 0;
	while (res2[i])
	{
		num = ft_atoi(res2[i], 0);
		check_duplicated(*stack_a, num);
		ft_lstadd_back((stack_a), ft_lstnew(stack_a, num));
		i++;
	}
	free_substrs(res2);
	if (check_sorted(*stack_a) == 1)
		exit(0);
}

void	joining(int argc, char **argv, char **res)
{
	int	i;

	i = 1;
	*res = NULL;
	while (i < argc)
	{
		if (!*(argv[i]) || check_spaces(argv[i]))
			error();
		*res = ft_strjoin(*res, argv[i]);
		i++;
	}
}

void	process(int argc, char **argv)
{
	char		*res;
	t_list		*stack_a;
	t_list		*stack_b;
	char		**res2;
	int			i;

	i = 1;
	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		exit(0);
	joining(argc, argv, &res);
	res2 = ft_split(res, ' ', 0);
	if (!res2)
		return ;
	stack_a = ft_lstnew(&stack_a, ft_atoi((res2[0]), 0));
	storing(&stack_a, res2);
	#include <string.h>

	while (i < argc)
	{
	    if (strcmp(argv[i], "sa") == 0)
	        ft_sa(&stack_a);
	    else if (strcmp(argv[i], "sb") == 0)
	        ft_sb(&stack_b);
	    else if (strcmp(argv[i], "ss") == 0)
	        ft_ss(&stack_a, &stack_b);
	    else if (strcmp(argv[i], "ra") == 0)
	        ft_ra(&stack_a);
	    else if (strcmp(argv[i], "rb") == 0)
	        rb(&stack_b);
	    else if (strcmp(argv[i], "rr") == 0)
	        ft_rr(&stack_a, &stack_b);
	    else if (strcmp(argv[i], "rra") == 0)
	        ft_rra(&stack_a);
	    else if (strcmp(argv[i], "rrb") == 0)
	        ft_rrb(&stack_b);
	    else if (strcmp(argv[i], "rrr") == 0)
	        ft_rrr(&stack_a, &stack_b);
	    else
	        error();
	}
	if (check_sorted(stack_a) && !stack_b)
		write(1, "OK\n", 2);
	else
		error();
}

int	main(int argc, char **argv)
{
	process(argc, argv);
	return (0);
}
