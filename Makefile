# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/21 09:35:18 by hermarti          #+#    #+#              #
#    Updated: 2025/07/30 14:02:21 by hermarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCDIR = src/
ODIR = obj/
IDIR = inc/
SRC = $(wildcard $(SRCDIR)*.c)

CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(IDIR)

DEBUG ?= 0
ifeq ($(DEBUG), 1)
	CFLAGS += -g2 -O0
endif

OBJ = $(SRC:$(SRCDIR)%=$(ODIR)%.o)

RM = rm -f
RMDIR = rm -rf
.PHONY: all clean fclean

all: $(NAME)

$(NAME): $(OBJ)

$(ODIR):
	@mkdir -p $@

$(OBJ): | $(ODIR)

$(OBJ): $(ODIR)%.o: $(SRCDIR)%
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar rcs $@ $^

cleanobj:
	$(RM) $(wildcard $(OBJ))

cleanobjdir: cleanobj
	$(RMDIR) $(ODIR)

clean: cleanobjdir

fclean: clean
	$(RM) $(NAME)

re: fclean all
