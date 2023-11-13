CC = cc 

COMPILER_FLAGS = -Wall -Wextra -Werror
MLX_CMP_FLAGS = 

SOURCES = sources/main.c \
sources/input_handler.c 

NAME = fractol

OBJS := $(SOURCES:%.c=%.o)

%.o : %.c
	$(CC) $(COMPILER_FLAGS) $(MLX_CMP_FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@cd libft && $(MAKE) --no-print-directory && $(MAKE) --no-print-directory bonus
	@$(CC) $(COMPILER_FLAGS) $(MLX_CMP_FLAGS) -o $(NAME) $(OBJS) ./libft/libft.a



.PHONY: all clean fclean re

all: $(NAME)

clean:
	@cd libft --no-print-directory && $(MAKE) --no-print-directory fclean
	@rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re : fclean all


