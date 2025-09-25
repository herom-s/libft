# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/21 09:35:18 by hermarti          #+#    #+#              #
#    Updated: 2025/09/09 23:02:51 by hermarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCDIR = src/
ODIR = obj/
IDIR = inc/
SRC = ft_atoi.c \
	  ft_atod.c \
	  ft_atof.c \
      ft_isalpha.c \
      ft_itoa.c \
      ft_lstdelone.c \
      ft_lstnew.c \
      ft_memcpy.c \
      ft_putendl_fd.c \
      ft_putulnbr_base_fd.c \
      ft_strdup.c \
      ft_strlcpy.c \
      ft_strnstr.c \
      ft_substrp.c \
      ft_bzero.c \
      ft_isascii.c \
      ft_lstadd_back.c \
      ft_lstiter.c \
      ft_lstsize.c \
      ft_memmove.c \
      ft_putnbr_base_fd.c \
      ft_putunbr_base_fd.c \
      ft_striteri.c \
      ft_strlen.c \
      ft_strrchr.c \
      ft_tolower.c \
      ft_calloc.c \
      ft_isdigit.c \
      ft_lstadd_front.c \
      ft_lstlast.c \
      ft_memchr.c \
      ft_memset.c \
      ft_putnbr_fd.c \
      ft_split.c \
      ft_strjoin.c \
      ft_strmapi.c \
      ft_strtrim.c \
      ft_toupper.c \
      ft_isalnum.c \
      ft_isprint.c \
	  ft_isfloat.c \
	  ft_isnumber.c \
      ft_lstclear.c \
      ft_lstmap.c \
      ft_memcmp.c \
      ft_putchar_fd.c \
      ft_putstr_fd.c \
      ft_strchr.c \
      ft_strlcat.c \
	  ft_strcmp.c \
      ft_strncmp.c \
      ft_substr.c \
	  ft_dprintf.c \
      ft_printf.c \
	  ft_print_formart.c \
      ft_printf_char.c \
      ft_printf_decimal.c \
      ft_printf_hex.c \
      ft_printf_interger.c \
      ft_printf_pointer.c \
      ft_printf_string.c \
      ft_printf_uinterger.c \
      get_next_line.c \
	  ft_dlstadd_back.c \
	  ft_dlstadd_front.c \
	  ft_dlstast.c \
	  ft_dlstclear.c \
	  ft_dlstdelone.c \
	  ft_dlstiter.c \
	  ft_dlstmap.c \
	  ft_dlstnew.c \
	  ft_dlstsize.c

SRCS = $(addprefix $(SRCDIR), $(SRC))

CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(IDIR)

DEBUG ?= 0
ifeq ($(DEBUG), 1)
	CFLAGS += -g2 -O0
endif

OBJS = $(patsubst $(SRCDIR)%.c,$(ODIR)%.o,$(SRCS))

RM = rm -f
RMDIR = rm -rf
.PHONY: all clean fclean

all: $(NAME)

$(NAME): $(OBJS)

$(ODIR):
	@mkdir -p $@

$(OBJS): | $(ODIR)

$(ODIR)%.o: $(SRCDIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar rcs $@ $^

cleanobj:
	$(RM) $(wildcard $(OBJS))

cleanobjdir: cleanobj
	$(RMDIR) $(ODIR)

clean: cleanobjdir

fclean: clean
	$(RM) $(NAME)

re: fclean all
