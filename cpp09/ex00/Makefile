# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/26 23:35:44 by sharnvon          #+#    #+#              #
#    Updated: 2023/03/28 11:36:38 by sharnvon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= c++
CPPFLAGS	= -Wall -Wextra -Werror -std=c++98
RM			= rm -rf

NAME		= btc
SRCS		= BitcoinExchange.cpp
MAIN		= main.cpp
OBJS		= $(SRCS:%.cpp=%.o)
INPUT		= input.txt

$(NAME): $(OBJS)
	$(CC) $(CPPFLAGS) $(MAIN) $(OBJS) -o $(NAME)

all: $(NAME)
.PHONY : all

$(INPUT) :
	@echo "date | value\n\
	2011-01-03 | 3\n\
	2011-01-03 | 2\n\
	2011-01-03 | 1\n\
	2011-01-03 | 1.2\n\
	2011-01-09 | 1\n\
	2012-01-11 | -1\n\
	2001-42-42\n\
	2012-01-11 | 1\n\
	2012-01-11 | 2147483648" > $(INPUT)
		
input : $(INPUT)
.PHONY : input

clean :
	$(RM) $(OBJS)
.PHONY : clean

fclean : clean
	$(RM) $(NAME)
.PHONY : fclean

re : fclean all
.PHONY : re