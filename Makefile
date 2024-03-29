# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/19 12:42:35 by rkrechun          #+#    #+#              #
#    Updated: 2024/03/29 11:43:46 by rkrechun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= pipex
CC		= gcc
FLAGS	= -Wall -Wextra -Werror #-g -O2 -fsanitize=address -fno-omit-frame-pointer
RM		= rm -rf

HEADER_SRCS	= pipex.h
HEADER_DIR	= include/
HEADER		= $(addprefix $(HEADER_DIR), $(HEADER_SRCS))

MPATH_SRCS	= child.c error.c free.c pipex.c
MPATH_DIR	= mandatory/
MPATH		= $(addprefix $(MPATH_DIR), $(MPATH_SRCS))
OBJ_M		= $(MPATH:.c=.o)

BPATH_SRCS 	= childs_bonus.c error_bonus.c files_bonus.c \
				free_bonus.c here_doc.c pipex_bonus.c
BPATH_DIR	= bonus/
BPATH		= $(addprefix $(BPATH_DIR), $(BPATH_SRCS)) 
OBJ_B		= $(BPATH:.c=.o)

FUNC_SRCS	= ft_split.c ft_strjoin.c ft_strncmp.c ft_strdup.c
FUNC_DIR	= functions/
FUNC		= $(addprefix $(FUNC_DIR), $(FUNC_SRCS)) \
			gnl/get_next_line.c gnl/get_next_line_utils.c 
OBJ_F		= $(FUNC:.c=.o)



%.o: %.c $(HEADER) Makefile
	@$(CC) $(FLAGS) -c $< -o $@
								
$(NAME): $(OBJ_F) $(OBJ_M)
	@$(CC) $(OBJ_F) $(OBJ_M) -o $(NAME)
	@echo "$(GREEN)$(NAME) Created!$(DEFAULT)"

all:	$(NAME)

bonus:	$(OBJ_B) $(OBJ_F)
		@$(CC) $(OBJ_F) $(OBJ_B) -o $(NAME)
		@echo "$(GREEN)$(NAME) Created bonus!$(DEFAULT)"

clean:	
		@$(RM) $(OBJ_M)
		@$(RM) $(OBJ_F)
		@$(RM) $(OBJ_B)
		@echo "$(YELLOW)objectfile deleted!$(DEFAULT)"

fclean: 
		@$(RM) $(OBJ_M)
		@$(RM) $(OBJ_F)
		@$(RM) $(OBJ_B)
		@$(RM) $(NAME)
		@echo "$(RED)all deleted!$(DEFAULT)"

re:	fclean all 

.PHONY:	all clean fclean re

#COLORS
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m