NAME = fractol
FLAG1 = -Wall -Wextra -Werror -lpthread
FLAG2 = -lmlx -framework OpenGL -framework AppKit
CC = gcc
INC = -I includes
SRC = srcs/barnsleyfern.c srcs/burningship.c srcs/fractol.c srcs/hook_mouse.c srcs/julia.c srcs/mandelbrot.c \
	srcs/sierpinskicarpet.c libft/libft.a
OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean name

all: $(NAME)

$(NAME): Makefile
	@make -C libft
	@$(CC) $(FLAG1) $(FLAG2) $(INC) -o $(NAME) $(SRC)
	@echo "create $(NAME)"

%.o: %.c
	@$(CC) $(FLAG1) $(FLAG2) $(INC) -o $@ -c $<

clean:
	@make clean -C libft
	@rm -rf $(OBJ)

fclean: clean
	@make fclean -C libft
	@rm -rf $(NAME)

re: fclean all
