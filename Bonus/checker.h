#ifndef CHECKER_H
# define CHECKER_H

# include "libc.h"
# include <string.h>
# include <limits.h>

typedef struct s_list
{
	struct s_list	*previus;
	int				data;
	int				index;
	int				position;
	struct s_list	*next;
}		t_list;

# define BUFFER_SIZE 24

//  #define malloc(X)  NULL
//parsing functions
char		*get_next_line(int fd);
void		ft_free(char **x);
char		*ft_strchr(const char *s, int c);
char		*ft_substr(char const *s, unsigned int start, size_t len);
void		check_char(const char *s);
void		check_duplicated(t_list *head, int x);
int			check_sorted(t_list *head);
int			check_spaces(const char *s);
size_t		ft_strlen(const char *str);
char		**ft_split(char const *s, char c, int i);
long		ft_isdigit(long i);
int			ft_isspace(char c);
int			ft_atoi(const char *str, long i);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strdup(const char *s1);
void		error(void);
void		indexing(t_list **stack, t_list **new);
char		**free_substrs(char **substrs);
//list tools
t_list		*ft_lstnew(t_list **stack, int data);
void		ft_lstadd_back(t_list **alst, t_list *new);
int			lstsize(t_list *stack);
//linked list mouves
void		ft_sa(t_list **stack_a);
void		ft_sb(t_list **stack_b);
void		ft_ss(t_list **stack_a, t_list **stack_b);
void		ft_ra(t_list **stack_a);
void		rb(t_list **b);
void		ft_pb(t_list **a, t_list **b);
void		ft_pa(t_list **b, t_list **a);
// ________________________
void		ft_rr(t_list **stack_a, t_list **stack_b);
void		ft_rra(t_list **stack_a);
void		ft_rrb(t_list **stack_b);
void		ft_rrr(t_list **stack_a, t_list **stack_b);
void		ft_pa(t_list **stack_a, t_list **stack_b);
void		ft_pb(t_list **stack_a, t_list **stack_b);
void		push_to_b(t_list **a, t_list **b, int i, int x);
void		push_to_a(t_list **a, t_list **b, int j, int i);
void		ft_mark(t_list *lst);
int			fin_max_index(t_list *lst);
void		indexing(t_list **stack, t_list **new);

#endif