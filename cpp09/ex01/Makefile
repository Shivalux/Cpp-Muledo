# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/30 02:53:26 by sharnvon          #+#    #+#              #
#    Updated: 2023/03/30 23:04:32 by sharnvon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= c++
CPPFLAGS	= -Wall -Wextra -Werror -std=c++98
RM			= rm -rf

NAME = RPN
SRCS = RPN.cpp
OBJS = $(SRCS:%.cpp=%.o)
MAIN = main.cpp

all: $(NAME)
.PHONY: all

$(NAME) : $(OBJS)
	$(CC) $(CPPFLAGS) $(MAIN) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)
.PHONY: clean

fclean: clean
	$(RM) $(NAME)
.PHONY: fclean

re: fclean all
.PHONY: re