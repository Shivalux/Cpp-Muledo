# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/21 13:21:45 by sharnvon          #+#    #+#              #
#    Updated: 2022/12/30 23:55:15 by sharnvon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

NAME =	FormUpMaggots
MAIN =	main.cpp
SRCS =	Bureaucrat.cpp \
		Form.cpp
OBJS =	$(SRCS:%.cpp=%.o)

$(NAME): $(OBJS)
	$(CC) $(CPPFLAGS) $(OBJS) $(MAIN) -o $(NAME)

all: $(NAME)
.PHONEY: all

clean:
	$(RM) $(OBJS)
.PHONEY: clean

fclean: clean
	$(RM) $(NAME)
.PHONEY: fclean

re:	fclean all
.PHONEY: re


