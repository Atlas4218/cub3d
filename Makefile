# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbonnard <gbonnard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/10 11:29:27 by gbonnard          #+#    #+#              #
#    Updated: 2023/12/05 12:50:29 by gbonnard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= cub3D
CC 				= gcc
SRC 			= get_map.c \
				init.c \
				parse_map.c \
				parse_file.c \
				raycast_move.c \
				raycast_screen.c \
				raycasting.c \
				main.c \
				utils.c \
				ft_simple_split.c\
				minimap.c\

RM 				= rm -rf
LIBFT_PATH		=	./libft
LIBFT			=	$(LIBFT_PATH)/libft.a
MINILIBX_PATH	=	./minilibx-linux
MINILIBX		=	$(MINILIBX_PATH)/libmlx.a
SOURCES_DIR		=	src
HEADER			=	./inc/cub3D.h
SOURCES			=	$(addprefix $(SOURCES_DIR)/, $(SRC))
OBJ 			= $(SOURCES:.c=.o)
FLAGS 			= -Wall -Werror -Wextra -g
MLX				= -Lminilibx-linux -lmlx_Linux -L/usr/lib -Iminilibx-linux -lXext -lX11 -lm -lz -L. -lmlx

all : $(NAME)

lib :
	make -C $(LIBFT_PATH)

%.o: %.c
	$(CC) $(FLAGS) -I/usr/include -Iminilibx-linux -O3 -c $< -o $(<:.c=.o) 


$(NAME):		$(LIBFT) $(MINILIBX) $(OBJ) $(HEADER)
				$(CC) $(OBJ) $(MLX) $(LIBFT) $(MINILIBX) -o $(NAME) 

				
$(LIBFT):
				$(MAKE) -C $(LIBFT_PATH)

$(MINILIBX):
				$(MAKE) -C $(MINILIBX_PATH)

clean :
	make -C $(LIBFT_PATH) clean
	make -C $(MINILIBX_PATH) clean
	$(RM) $(OBJ) *.o
	
fclean : clean
	make -C $(LIBFT_PATH) fclean
	$(RM) $(NAME) cub3D
	 
	
	
re : fclean all

.PHONY : all clean fclean re libft minilibx
