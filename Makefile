# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/22 19:23:54 by susivagn          #+#    #+#              #
#    Updated: 2018/02/22 19:26:54 by susivagn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/09 17:53:05 by susivagn          #+#    #+#              #
#    Updated: 2018/02/15 13:45:47 by susivagn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

SRC = main_lemin.c \
	  room.c \
	  tube.c \
	  matrix.c

OFILE = $(SRC:.c=.o)

FLAGS= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OFILE)
	@gcc -Wall -Werror -Wextra  -g -c $(SRC)
	@echo "*** Lem-in Ready ***"


%.o: %.c
	@gcc $(FLAGS) -c -g $^

clean:
	@rm -f $(OFILE)

fclean: clean
	@rm -f $(NAME)

re: fclean all