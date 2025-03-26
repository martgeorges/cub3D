# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgeorges <mgeorges@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/13 08:15:39 by mgeorges          #+#    #+#              #
#    Updated: 2025/03/26 10:02:54 by mgeorges         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	cub3D

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror 

INCLUDES	=	-I./includes -I./minilibx-linux

OBJ_DIR		=	./objs

ERROR_SRCS	=	sources/error/error.c sources/error/error2.c

LIBFT_SRCS	=	sources/libft/ft_split.c sources/libft/get_next_line.c sources/libft/libft.c \
			sources/libft/libft2.c sources/libft/utils2.c

MAP_SRCS	=	sources/map_files/map_errors.c sources/map_files/map_errors_2.c \
			sources/map_files/map_errors_3.c sources/map_files/map_render.c \
			sources/map_files/map_closed.c
			 
RAYCAST_SRCS = sources/raycasting/raycasting.c sources/raycasting/raycasting_utils.c \
			sources/raycasting/raycasting_utils2.c

TEXTURES_SRCS =	sources/textures/textures.c sources/textures/textures_floor_ceiling.c

KEYBOARD_SRCS = sources/keyboard/keyboard_handler.c

SRCS	=	sources/main.c \
		sources/utils.c \
		sources/memory_management.c \
		$(ERROR_SRCS) $(LIBFT_SRCS) $(MAP_SRCS) $(RAYCAST_SRCS) $(TEXTURES_SRCS) $(KEYBOARD_SRCS)
		
LIBRARY     = -L./minilibx-linux -lmlx -lX11 -lXext -lXrandr -lXrender -lm
#LIBRARY	= -L./minilibx-macos -lmlx -lX11 -lXext -lm
#LIBRARY		=	-L./minilibx-macos -lmlx -framework OpenGL -framework AppKit

OBJS	=	$(patsubst sources/%.c, $(OBJ_DIR)/%.o, $(SRCS))

YELLOW	=	\033[1;33m
GREEN	=	\033[1;32m
RESET	=	\033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@echo "\n$(YELLOW)Compiling $(NAME)...$(RESET)\n"
	$(CC) $(CFLAGS) $(OBJS) $(LIBRARY) -o $(NAME)
	@echo "\n$(GREEN)$(NAME) compiled successfully!$(RESET)\n"

$(OBJ_DIRS): 
	@mkdir -p $(OBJ_DIRS)

$(OBJ_DIR)/%.o: sources/%.c
	@mkdir -p $(dir $@)
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