NAME	:= Cube3D
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast 
LIBMLX	:= ./lib/MLX42

HEADERS	:= -I ./include -I $(LIBMLX)/include 
LIBS	:= $(LIBMLX)/build/libmlx42.a  -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/" -ldl -pthread -lm
SRCS	:= $(shell find ./src -iname "*.c")
OBJS	:= ${SRCS:.c=.o}

all: libmlx $(NAME)

libmlx:
	@bash initm.sh
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)\n"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)  -framework Cocoa -framework OpenGL -framework IOKit

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: clean all

.PHONY: all, clean, fclean, re, libmlx

run: all
	./$(NAME) map/map01.cub