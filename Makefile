# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/22 19:23:54 by susivagn          #+#    #+#              #
#    Updated: 2018/03/26 20:39:19 by susivagn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = src

OBJ_PATH = obj

LDFLAGS = -LLibftXen

LDLIBS = -llibft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = lem-in

SRC_NAME =

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(LDFLAGS) $(LDLIBS) $^ -o $@

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2>/dev/null
	$(CC) $(CFLAGS) $