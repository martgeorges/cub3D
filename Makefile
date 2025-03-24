# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgeorges <mgeorges@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/13 08:15:39 by mgeorges          #+#    #+#              #
#    Updated: 2025/03/19 15:56:06 by mgeorges         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	cub3D

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror 
#CFLAGS	=	-Wall -Wextra -Werror -g -arch arm64

INCLUDES	=	-I./includes -I./minilibx-linux

OBJ_DIR		=	./objs

SRCS	=	sources/main.c \
		sources/utils.c sources/map_render.c \
		sources/libft.c \
		sources/keyboard_macos.c \
		sources/raycasting.c sources/error.c sources/raycasting_utils.c \
		sources/libft2.c sources/textures_floor_ceiling.c \
		sources/ft_split.c sources/textures.c sources/memory_management.c \
		sources/utils2.c sources/get_next_line.c sources/raycasting_utils2.c \
		sources/map_errors.c sources/map_errors_2.c sources/map_errors_3.c 
		
#LIBRARY     = -L./minilibx-linux -lmlx -lX11 -lXext -lXrandr -lXrender -lm
#LIBRARY	= -L./minilibx-macos -lmlx -lX11 -lXext -lm
LIBRARY		=	-L./minilibx-macos -lmlx -framework OpenGL -framework AppKit

OBJS	=	$(patsubst sources/%.c, $(OBJ_DIR)/%.o, $(SRCS))

YELLOW	=	\033[1;33m
GREEN	=	\033[1;32m
RESET	=	\033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@echo "\n$(YELLOW)Compiling $(NAME)...$(RESET)\n"
	$(CC) $(CFLAGS) $(OBJS) $(LIBRARY) -o $(NAME)
	@echo "\n$(GREEN)$(NAME) compiled successfully!$(RESET)\n"

$(OBJ_DIR)/%.o: sources/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@echo "\n$(YELLOW)CLeaning Objs...$(RESET)\n"
	@rm -rf $(OBJ_DIR)

fclean:
	@echo "\n$(YELLOW)Removing executables...$(RESET)\n"
	@rm -rf $(OBJ_DIR)
	@rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re