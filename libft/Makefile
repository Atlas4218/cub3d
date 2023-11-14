# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbonnard <gbonnard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/16 15:05:59 by gbonnard          #+#    #+#              #
#    Updated: 2023/01/03 13:46:04 by gbonnard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
SRC = ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_strlen.c \
	ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strncmp.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strnstr.c \
	ft_atoi.c \
	ft_calloc.c \
	ft_strdup.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_split.c \
	ft_itoa.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_lstnew.c \
	ft_lstadd_front.c \
	ft_lstsize.c \
	ft_lstlast.c \
	ft_lstadd_back.c \
	ft_lstdelone.c \
	ft_lstclear.c \
	ft_lstiter.c \
	ft_lstmap.c \
	ft_print_char.c \
	ft_printf.c \
	ft_print_hex.c \
	ft_print_number.c \
	ft_print_pointer.c \
	ft_print_unsigned.c \
	get_next_line.c \
	get_next_line_bonus.c \
	get_next_line_utils.c \
	
OBJ = $(SRC:.c=.o)
RM = rm -rf
AR = ar rcs
FLAGS = -Wall -Werror -Wextra

all : $(NAME)

%.o : %.c
	$(CC) $(FLAGS) -o $@ -c $<

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

clean :
	$(RM) *.o
	
fclean : clean
	$(RM) $(NAME)
	
re : fclean all

.PHONY : all clean fclean re