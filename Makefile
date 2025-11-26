# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbraga <lbraga@student.42lisboa.com>>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/18 19:46:58 by lbraga            #+#    #+#              #
#    Updated: 2025/11/26 00:09:27 by lbraga           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	pipex
HEADER	=	pipex.h
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror -I.
RM		=	rm -f

SRC		=	src/pipex.c src/pipex_utils.c

OBJ		=	$(SRC:.c=.o)
LIBFT_D	=	src/libft
LIBFT	=	$(LIBFT_D)/libft.a

all: $(NAME)
$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBFT)
	@echo "$(NAME) compiled"

$(LIBFT):
	@$(MAKE) -C $(LIBFT_D) --no-print-directory

%.o: %.c $(HEADER)
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ)
	@$(MAKE) clean -C $(LIBFT_D) --no-print-directory
	@echo "Objects deleted"

fclean: clean	
	@$(RM) $(NAME)
	@$(MAKE) fclean -C $(LIBFT_D) --no-print-directory
	@echo "Library deleted"

re: fclean all

.PHONY: all clean fclean re