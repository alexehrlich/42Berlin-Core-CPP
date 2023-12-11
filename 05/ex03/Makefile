# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aehrlich <aehrlich@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/29 17:23:35 by aehrlich          #+#    #+#              #
#    Updated: 2023/12/11 16:36:54 by aehrlich         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= office

CC			= c++
CFLAGS		= -Werror -Wextra -Wall -std=c++98 -ggdb

OBJDIR		= objs

SRCS		= main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp

OBJS		:= $(SRCS:%.cpp=$(OBJDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(OBJDIR)
	rm -rf *_shrubbery

fclean: clean
	rm -f $(NAME)

re: fclean all

