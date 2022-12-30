# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/17 18:38:13 by sharnvon          #+#    #+#              #
#    Updated: 2022/12/20 15:50:30 by sharnvon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

NAME =	AbstractClass
MAIN =	main.cpp
SRCS =	AAnimal.cpp \
		Cat.cpp \
		Dog.cpp \
		WrongAnimal.cpp \
		WrongCat.cpp \
		Brain.cpp
OBJS =	$(SRCS:%.cpp=%.o)

all: $(NAME)
.PHONEY: all

$(NAME): $(OBJS)
	$(CC) $(CPPFLAGS) $(OBJS) $(MAIN) -o $(NAME)

clean:
	$(RM) $(OBJS)
.PHONEY: clean

fclean: clean
	$(RM) $(NAME)
.PHONEY: fclean

re: fclean all
.PHONEY: re