CC = cc 

COMPILER_FLAGS = -Wall -Wextra -Werror -O2
MLX_CMP_FLAGS = -lmlx -lXext -lX11 

SOURCES = sources/main.c \
sources/input_handler.c \
sources/mandelbrot.c \
sources/utils.c \
sources/mandel_artist.c \
sources/event_utils.c \
sources/julia.c \
sources/julia_artist.c

NAME = fractol

OBJS := $(SOURCES:%.c=%.o)

%.o : %.c
	$(CC) $(COMPILER_FLAGS)  -c $< -o $@

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


