# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/01 16:17:32 by sharnvon          #+#    #+#              #
#    Updated: 2022/11/03 18:46:49 by sharnvon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

TEST = infile
NAME = sedIsForLosers
OUTFILE = *.replace
SRCS = main.cpp
OBJS = $(SRCS:%.cpp=%.o)

all: $(OBJS)
	$(CC) $(CPPFLAGS) $(OBJS) -o $(NAME)
.PHONY: all

test:
	@echo "There's a calm surrender\nTo the rush of day\nWhen the heat of a rolling wind\nCan be turned away\nAn enchanted moment\nAnd \
	it sees me through\nIt's enough for this restless warrior\nJust to be with you\n\nAnd can you feel the love tonight?\nIt is where \
	we are\nIt's enough for this wide-eyed wanderer\nThat we got this far\nAnd can you feel the love tonight\nHow it's laid to rest?\n\
	It's enough to make kings and vagabonds\n\nBelieve the very best\n\nThere's a time for everyone\nIf they only learn\nThat the twis\
	ting kaleidoscope\nMoves us all in turn\nThere's a rhyme and reason\n\nTo the wild outdoors\nWhen the heart of this star-crossed \
	voyager\n\nBeats in time with yours\nAnd can you feel the love tonight?\nIt is where we are\nIt's enough for this wide-eyed wanderer\
	\nThat we got this far\nAnd can you feel the love tonight\nHow it's laid to rest?\nIt's enough to make kings and vagabonds\nBelieve \
	the very best\nIt's enough to make kings and vagabonds\nBelieve the very best" > infile
.PHONY: test

clean:
	$(RM) $(OBJS) $(OUTFILE)
.PHONY: clean

fclean: clean
	$(RM) $(NAME) $(TEST)
.PHONY: fclean

re: fclean all
.PHONY: re