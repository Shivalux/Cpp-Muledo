# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/15 14:30:56 by sharnvon          #+#    #+#              #
#    Updated: 2022/12/15 21:15:55 by sharnvon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++ 
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

NAME =	RepetitiveWork
MAIN =	main.cpp
SRCS =	ClapTrap.cpp \
		ScavTrap.cpp \
		FragTrap.cpp
OBJS =	$(SRCS:%.cpp=%.o)

all: $(NAME)
.PHONY: all

$(NAME): $(OBJS)
	$(CC) $(CPPFLAGS) $(OBJS) $(MAIN) -o $(NAME)

clean:
	$(RM) $(OBJS)
.PHONY: clean

fclean: clean
	$(RM) $(NAME)
.PHONY: fclean

re:	fclean all
.PHONY: re