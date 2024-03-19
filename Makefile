# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/19 12:42:35 by rkrechun          #+#    #+#              #
#    Updated: 2024/03/19 12:43:32 by rkrechun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= pipex
CC		= gcc
FLAGS	= -Wall -Wextra -Werror
RM		= rm -rf

HEADER_SRCS	= pipex.h
HEADER_DIR	= include/
HEADER		= $(addprefix $(HEADER_DIR), $(HEADER_SRCS))

MPATH_SRCS	= child.c error.c free.c pipex.c
MPATH_DIR	= mandatory/
MPATH		= $(addprefix $(MPATH_DIR), $(MPATH_SRCS))
OBJ_M		= $(MPATH:.c=.o)

FUNC_SRCS	= ft_split.c ft_strjoin.c ft_strlen.c ft_strncmp.c ft_strdup.c
FUNC_DIR	= functions/
FUNC		= $(addprefix $(FUNC_DIR), $(FUNC_SRCS))
OBJ_F		= $(FUNC:.c=.o)


%.o: %.c $(HEADER) Makefile
	@$(CC) $(FLAGS) -c $< -o $@
								
$(NAME): $(OBJ_F) $(OBJ_M)
	@$(CC) $(OBJ_F) $(OBJ_M) -o $(NAME)
	@echo "$(GREEN)$(NAME) Created!$(DEFAULT)"

all:	$(NAME)

clean:	
		@$(RM) $(OBJ_M)
		@$(RM) $(OBJ_F)
		@echo "$(YELLOW) objectfile deleted!$(DEFAULT)"

fclean: 
		@$(RM) $(OBJ_M)
		@$(RM) $(OBJ_F)
		@$(RM) $(NAME)
		@echo "$(RED) all deleted!$(DEFAULT)"

re:	fclean all

.PHONY:	all clean fclean re

#COLORS
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m