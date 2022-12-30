# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/29 12:17:32 by sharnvon          #+#    #+#              #
#    Updated: 2022/12/30 11:32:23 by sharnvon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

NAME =	MutatedAbomination
MAIN =	main.cpp
SRCS =	
OBJS =	$(SRCS:%.cpp=%.o)

$(NAME): $(OBJS) $(TOBJS)
	$(CC) $(CPPFLAGS) $(MAIN) $(OBJS) -o $(NAME)

all: $(NAME)
.PHONY: all

clean:
	$(RM) $(OBJS)
.PHONY: clean

fclean: clean
	$(RM) $(NAME)
.PHONY: fclean

re: fclean all
.PHONY: re