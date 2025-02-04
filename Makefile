# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgeorges <mgeorges@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/13 08:15:39 by mgeorges          #+#    #+#              #
#    Updated: 2025/02/04 08:15:12 by mgeorges         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	cub3D

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror -g

INCLUDES	=	-I./includes -I./minilibx

OBJ_DIR		=	./objs

SRCS	=	sources/main.c \
		sources/utils.c sources/map_render.c \
			
LIBRARY     = -L./minilibx-linux -lmlx -lX11 -lXext -lXrandr -lXrender -lm
# LIBRARY	= -L./minilibx -lmlx -lX11 -lXext -lm

OBJS	=	$(patsubst srcs/%.c, $(OBJ_DIR)/%.o, $(SRCS))

YELLOW	=	\033[1;33m
GREEN	=	\033[1;32m
RESET	=	\033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@echo "\n$(YELLOW)Compiling $(NAME)...$(RESET)\n"
	$(CC) $(CFLAGS) $(OBJS) $(LIBRARY) -o $(NAME)
	@echo "\n$(GREEN)$(NAME) compiled successfully!$(RESET)\n"

$(OBJ_DIR)/%.o: srcs/%.c
	@mkdir -p (OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@echo "\n$(YELLOW)CLeaning Objs...$(RESET)\n"
	@rm -rf $(OBJ_DIR)

fclean:
	@echo "\n$(YELLOW)Removing executables...$(RESET)\n"
	@rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re