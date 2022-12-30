# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/28 00:44:26 by sharnvon          #+#    #+#              #
#    Updated: 2022/12/28 02:05:08 by sharnvon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

NAME =	StartWithAFewFunction
MAIN =	main.cpp
SRCS =	
OBJS = $(SRCS:%.cpp=%.o)

$(NAME) : $(OBJS)
	$(CC) $(CPPFLAGS) $(OBJS) $(MAIN) -o $(NAME)

all: $(NAME)
.PHONEY: all

clean:
	$(RM) $(OBJS)
.PHONEY: clean

fclean: clean
	$(RM) $(NAME)
.PHONEY: fclean

re: fclean all
.PHONEY: re