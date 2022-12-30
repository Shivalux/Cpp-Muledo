# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/02 03:25:41 by sharnvon          #+#    #+#              #
#    Updated: 2022/11/02 22:21:15 by sharnvon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

NAME = harlFilter
SRCS = main.cpp Harl.cpp
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