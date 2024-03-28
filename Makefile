# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/19 12:42:35 by rkrechun          #+#    #+#              #
#    Updated: 2024/03/28 14:45:29 by rkrechun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= pipex
CC		= gcc
FLAGS	= -Wall -Wextra -Werror
RM		= rm -rf

HEADER_SRCS	= pipex.h
HEADER_DIR	= include/
HEADER		= $(addprefix $(HEADER_DIR), $(HEADER_SRCS))

HEADERB_SRCS= pipex_bonus.h
HEADERB_DIR = include/
HEADERB		= $(addprefix $(HEADERB_DIR), $(HEADERB_SRCS))

MPATH_SRCS	= child.c error.c free.c pipex.c
MPATH_DIR	= mandatory/
MPATH		= $(addprefix $(MPATH_DIR), $(MPATH_SRCS))
OBJ_M		= $(MPATH:.c=.o)

FUNC_SRCS	= ft_split.c ft_strjoin.c ft_strlen.c ft_strncmp.c ft_strdup.c
FUNC_DIR	= functions/
FUNC		= $(addprefix $(FUNC_DIR), $(FUNC_SRCS))
OBJ_F		= $(FUNC:.c=.o)

BPATH_SRCS 	= childs_bonus.c error_bonus.c files_bonus.c \
				free_bonus.c here_doc.c pipex_bonus.c
BPATH_DIR	= bonus/
BPATH		= $(addprefix $(BPATH_DIR), $(BPATH_SRCS)) \
				gnl/get_next_line.c gnl/get_next_line_utils.c 
OBJ_B		= $(BPATH:.c=.o)


%.o: %.c $(HEADER) Makefile
	@$(CC) $(FLAGS) -c $< -o $@

%.o: %.c $(HEADERB) Makefile
	@$(CC) $(FLAGS) -c $< -o $@
								
$(NAME): $(OBJ_F) $(OBJ_M)
	@$(CC) $(OBJ_F) $(OBJ_M) -o $(NAME)
	@echo "$(GREEN)$(NAME) Created!$(DEFAULT)" 

$(BONUSNAME): $(OBJ_B) $(OBJ_F)
	@$(CC) $(OBJ_F) $(OBJ_B) -o $(BONUSNAME)
	@echo "$(GREEN)$(BONUSNAME) Created bonus!$(DEFAULT)"

all:	$(NAME)

bonus: $(BONUSNAME)

clean:	
		@$(RM) $(OBJ_M)
		@$(RM) $(OBJ_F)
		@$(RM) $(OBJ_B)
		@echo "$(YELLOW) objectfile deleted!$(DEFAULT)"

fclean: 
		@$(RM) $(OBJ_M)
		@$(RM) $(OBJ_F)
		@$(RM) $(OBJ_B)
		@$(RM) $(NAME)
		@$(RM) $(BONUSNAME)
		@echo "$(RED) all deleted!$(DEFAULT)"

re:	fclean all

.PHONY:	all clean fclean re

#COLORS
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m