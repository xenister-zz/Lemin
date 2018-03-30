# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/22 19:23:54 by susivagn          #+#    #+#              #
#    Updated: 2018/03/30 16:42:03 by susivagn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = src/
OBJ_PATH = obj/

CPPFLAGS = -I include -I LibftXen
LDFLAGS = -LLibftXen
LDLIBS = -lft

CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = lem-in

SRC_NAME = main_lemin.c \
		   room.c \
		   tube.c \
		   matrix.c \
		   lemin_print.c \
		   init_matrix_free.c

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	@make -C LibftXen
	$(CC) $(LDFLAGS) $(LDLIBS) $^ -o $@

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2>/dev/null || true
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

norme:
	norminette $(SRC)

clean:
	@make -C LibftXen clean
	rm -fv $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	@make -C LibftXen fclean
	rm -fv $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
