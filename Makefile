
NAME = ft_ls

LIB = libft/libft.a

CC = gcc -Wall -Wextra -Werror

SRC = 	main.c \
		ftls_list.c \
		merge_sort.c \
		addto_spec_list.c \

all: $(NAME) $(SRC)

$(NAME): $(SRC)
	#@make -C libft
	@$(CC) $(SRC) -g libft/libft.a $(LIB) -o $(NAME)

re: $(NAME) $(SRC)

clean:
	#@make clean -C libft

fclean: clean
	#@make fclean -C libft
	@rm $(NAME)
