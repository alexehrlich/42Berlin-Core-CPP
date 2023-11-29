# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aehrlich <aehrlich@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/29 17:23:35 by aehrlich          #+#    #+#              #
#    Updated: 2023/11/29 16:57:54 by aehrlich         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= zoo

CC			= c++
CFLAGS		= -Werror -Wextra -Wall -std=c++98

OBJDIR		= objs

SRCS		= main.cpp Dog.cpp Cat.cpp Animal.cpp WrongCat.cpp WrongAnimal.cpp

OBJS		:= $(SRCS:%.cpp=$(OBJDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

