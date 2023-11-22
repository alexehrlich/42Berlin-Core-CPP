# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aehrlich <aehrlich@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/29 17:23:35 by aehrlich          #+#    #+#              #
#    Updated: 2023/11/22 15:42:18 by aehrlich         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= harl20

CC			= c++
CFLAGS		= -Werror -Wextra -Wall -std=c++98

OBJDIR		= objs

SRCS		= main.cpp Harl.cpp

OBJS		:= $(SRCS:%.cpp=$(OBJDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(OBJDIR)
	rm -f *.replace

fclean: clean
	rm -f $(NAME)

re: fclean all

