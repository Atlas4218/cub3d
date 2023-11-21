# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbonnard <gbonnard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/10 11:29:27 by gbonnard          #+#    #+#              #
#    Updated: 2023/11/20 14:27:12 by gbonnard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= cub3D
CC 				= gcc
SRC 			= main.c \
				
				

RM 				= rm -rf
LIBFT_PATH		=	./libft
LIBFT			=	$(LIBFT_PATH)/libft.a
MINILIBX_PATH	=	./minilibx-linux
MINILIBX		=	$(MINILIBX_PATH)/libmlx.a
SOURCES_DIR		=	src
HEADER			=	./inc/cub3D.h
SOURCES			=	$(addprefix $(SOURCES_DIR)/, $(SRC))
OBJ 			= $(SOURCES:.c=.o)
FLAGS 			= -Wall -Werror -Wextra -g3
MLX				= -Lminilibx-linux -L/usr/lib -Iminilibx-linux -lXext -lX11 -lm -lz -L. -lmlx

all : $(NAME)

lib :
	make -C $(LIBFT_PATH)

%.o: %.c
	$(CC) $(FLAGS) -I/usr/include -Iminilibx-linux -O3 -c $< -o $(<:.c=.o) 



$(NAME):		$(LIBFT)  $(OBJ) $(HEADER) $(MINILIBX)
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
