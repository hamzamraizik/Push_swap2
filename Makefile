CFILES = push_swap.c ft_atoi.c ft_split.c libft_utils.c list_tools.c mouves_a.c mouves_b.c swap_mouves.c sort_three.c sorting.c Utils1.c
BFILES = checker_bonus.c ft_atoi.c ft_split.c libft_utils.c list_tools.c mouves_a.c mouves_b.c swap_mouves.c sort_three.c sorting.c Utils1.c
OFILES = $(CFILES:.c=.o)
B_OFILES = $(BFILES:.c=.o)
NAME = push_swap
BONUS_NAME = checker_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OFILES)
	$(CC) $(CFLAGS) -o $(NAME) $(OFILES)

$(BONUS_NAME): $(B_OFILES)
	$(CC) $(CFLAGS) -o $(BONUS_NAME) $(B_OFILES)

bonus: $(BONUS_NAME)

clean:
	rm -f $(OFILES) $(B_OFILES)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all
