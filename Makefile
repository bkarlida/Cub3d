SRCS = 	main.c start_map.c gnl/get_next_line.c gnl/get_next_line_utils.c \
		map_utils1.c tools.c textures_utils.c  map_utils2.c	\
		map_cover.c	mlx_set.c start_mlx.c mlx_key.c \
		move.c calculator.c textures_pixel.c print_pixel.c \
		rotate_mouse.c
OBJS = $(SRCS:.c=.o)
CC = gcc
MFLAGS = ./minilbx/libmlx.a
LFLAGS = ./libft/libft.a
AFLAGS =  -Wall -Wextra -Werror -I./minilbx -I./libft -g
RM = rm -rf
NAME = cub3d

all :$(MFLAGS) $(LFLAGS) $(NAME)
 
$(MFLAGS):
	@make -C ./minilbx

$(LFLAGS):
	@make -C ./libft

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(MFLAGS) $(LFLAGS) $(AFLAGS) -framework OpenGL -framework AppKit -o $(NAME)

fclean : clean
	@make fclean -C ./libft
	@$(RM) $(NAME)

clean :
	@make clean -C ./minilbx
	@make clean -C ./libft
	@$(RM) ./*.o ./gnl/*.o

re : fclean all

.PHONY : all fclean clean re