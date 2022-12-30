# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/31 15:33:09 by sharnvon          #+#    #+#              #
#    Updated: 2022/11/03 14:35:59 by sharnvon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

NAME = moarBrainz
SRCS = main.cpp zombieHorde.cpp Zombie.cpp
OBJS = $(SRCS:%.cpp=%.o)

all: $(OBJS)
	$(CC) $(CPPFLAGS) $(OBJS) -o $(NAME)
.PHONY: all

clean:
	$(RM) $(OBJS)
.PHONY: clean

fclean: clean
	$(RM) $(NAME)
.PHONY: fclean

re: fclean all
.PHONY: re
