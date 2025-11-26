# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbraga <lbraga@student.42lisboa.com>>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/23 16:04:42 by lbraga            #+#    #+#              #
#    Updated: 2025/11/24 20:11:13 by lbraga           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a
HEADER	=	libft.h
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror -I.
LIBC	=	ar rcs
RM		=	rm -f

SRC		=	src/ft_atoi.c		src/ft_bzero.c		src/ft_calloc.c		src/ft_isalnum.c \
			src/ft_isalpha.c	src/ft_isascii.c	src/ft_isdigit.c	src/ft_isprint.c \
			src/ft_memchr.c		src/ft_memcmp.c		src/ft_memcpy.c		src/ft_memmove.c \
			src/ft_memset.c		src/ft_strchr.c		src/ft_strdup.c		src/ft_strlcat.c \
			src/ft_strlcpy.c	src/ft_strlen.c		src/ft_strncmp.c	src/ft_strnstr.c \
			src/ft_strrchr.c	src/ft_tolower.c	src/ft_toupper.c	src/ft_substr.c \
			src/ft_strjoin.c	src/ft_strtrim.c	src/ft_split.c		src/ft_itoa.c \
			src/ft_strmapi.c	src/ft_striteri.c	src/ft_putchar_fd.c	src/ft_putstr_fd.c \
			src/ft_putendl_fd.c	src/ft_putnbr_fd.c \
			src/ft_printf.c		src/ft_pformat.c \
			src/ft_isspace.c	src/ft_atol.c		src/ft_atol_intoverflow.c \
			src/ft_getenv.c		src/ft_freecharray.c	src/ft_strjoinfree.c 

OBJ		=	$(SRC:.c=.o)

all: $(NAME)
$(NAME): $(OBJ)
	@$(LIBC) $(NAME) $(OBJ)
	@echo "$(NAME) created"

%.o: %.c $(HEADER)
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) -c $< -o $@

clean: 
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re