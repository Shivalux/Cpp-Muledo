# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/21 13:21:45 by sharnvon          #+#    #+#              #
#    Updated: 2022/12/30 23:56:08 by sharnvon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

NAME =	AtleastThisBeatsCoffeeMaking
MAIN =	main.cpp
SRCS =	Bureaucrat.cpp \
		AForm.cpp \
		ShrubberyCreationForm.cpp \
		RobotomyRequestForm.cpp \
		PresidentialPardonForm.cpp \
		Intern.cpp
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

remove:
	$(RM) *_shrubbery
.PHONEY: remove

re:	fclean all
.PHONEY: re


