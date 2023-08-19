SRCS = 	main.c start_map.c gnl/get_next_line.c gnl/get_next_line_utils.c \
		start_map_utils.c tools.c textures_utils.c  start_map_utils2.c	\
		map_cover.c
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