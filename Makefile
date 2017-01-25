# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bpezeshk <bpezeshk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/17 14:12:17 by bpezeshk          #+#    #+#              #
#    Updated: 2017/01/19 00:43:44 by bpezeshk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCDIR = ./srcs

LIBDIR = ./libft

OBJ = file_len.o initialize_minos.o main.o make_mino.o putboard.o solver.o \
top_left_mino.o valid_buf.o

CFLAGS += -Wall -Wextra -Werror

LIB = libft.a

all: $(NAME)

$(NAME): $(LIBDIR)/$(LIB) $(OBJ)
	@echo [CC] [BINARY] $(NAME)
	@gcc $(OBJ) $(LIBDIR)/$(LIB) -o $(NAME)

%.o: $(SRCDIR)/%.c
	@echo [CC] $@
	@gcc $(CFLAGS) $< -c -o $@

$(LIBDIR)/$(LIB):
	#@cd libft && make

clean:
	@echo [RM] "*.o"
	@rm -f $(OBJ)
	#@cd libft && make clean

fclean: clean
	@echo [RM] $(NAME)
	@rm -f $(NAME)
	#@cd libft && make fclean --silent

re: fclean all
