NAME = push_swap

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRC = push_swap.c ft_linked_list.c stack_a.c stack_b.c ft_split.c ft_for_split.c ft_atoi.c sort_more_than_5_numbers.c sort_less_than_5_numbers.c helpfull_func.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
		
clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re: fclean all