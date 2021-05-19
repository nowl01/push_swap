# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abdait-m <abdait-m@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/15 14:08:46 by abdait-m          #+#    #+#              #
#    Updated: 2021/05/19 15:05:45 by abdait-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

PS_LIB = pushswap.a

MAIN = ./srcs/push_swap.c

LIBFT = ./libft

LIBFT_LIB = $(LIBFT)/libft.a

FILES = ./srcs/push_swap.c ./srcs/error_checker.c ./srcs/push.c \
		./srcs/rotate.c ./srcs/tools.c

HEADER = ./header/push_swap.h

OBJECT = $(FILES:.c=.o)

FLAGS = -Wextra -Werror -Wall

LIBFT_FILES = $(wildcard ./libft/*.c ./libft/*.h)

all: $(NAME)

$(NAME): $(LIBFT_FILES) $(OBJECT) $(HEADER) $(MAIN) $(FILES)
			@make -C $(LIBFT)
			@ar -rcs $(PS_LIB) $(OBJECT)
			@gcc  $(FLAGS) $(MAIN) $(PS_LIB) $(LIBFT_LIB) -o $(NAME)
			@echo "\n\033[35m Hajime \033[0m\n"
					


%.o:%.c $(HEADER)
			@gcc -c $< $(FLAGS) -o $@

clean:
			@make clean -C $(LIBFT)
			@rm -rf srcs/*.o $(LIB)
			@echo "\n\033[32mCleaning is Done!\033[0m\n"

fclean: clean
			@make fclean -C $(LIBFT)
			@rm -rf $(NAME) $(PS_LIB) 

re : fclean all