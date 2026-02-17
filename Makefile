# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: varandri <varandri@student.42antananari    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/17 08:07:10 by varandri          #+#    #+#              #
#    Updated: 2026/02/17 09:01:56 by varandri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a

CC = cc

CFLAGS = -Wall -Werror -Wextra


SRC = get_next_line.c \
		get_next_line_utils.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	ar -rcs $(NAME) $(OBJ)

clean : 
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)
	
re : fclean all

.PHONY = all clean fclean re