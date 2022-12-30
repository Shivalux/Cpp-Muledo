# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/17 18:38:13 by sharnvon          #+#    #+#              #
#    Updated: 2022/12/19 22:07:09 by sharnvon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

NAME =	InterfaceAndRecap
MAIN =	main.cpp
SRCS =	Character.cpp \
		Cure.cpp \
		Ice.cpp \
		MateriaSource.cpp \
		AMateria.cpp
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