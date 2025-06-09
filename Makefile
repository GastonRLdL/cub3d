# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/22 08:06:23 by gasroman          #+#    #+#              #
#    Updated: 2025/06/09 19:39:44 by gasroman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# ============================== VARIABLES =================================== #

FLAGS = -g
RMV = rm -rf
CC = cc
NAME = cub3D

# Minilibx
MLX_PATH	= minilibx-linux/
MLX_NAME	= libmlx.a
MLX			= $(MLX_PATH)$(MLX_NAME)

# =============================== SOURCES ==================================== #

SRC_FILES = main.c \
			parsing/count_map.c					\
			parsing/data_sorter.c				\
			parsing/format_check.c				\
			parsing/is_surrounded.c				\
			parsing/line_checker.c				\
			parsing/parser_data.c				\
			parsing/parser_map.c				\
			parsing/store_color.c				\
			parsing/store_texture.c				\
			parsing/value_checks.c				\
			parsing_utils/free_data.c 			\
			parsing_utils/ft_double_realloc.c	\
			parsing_utils/ft_split_set.c		\
			parsing_utils/player_count.c		\
			parsing_utils/process_line.c		\
			parsing_utils/split_size.c			\
			parsing_utils/texture_color.c		\
			drawing/draw.c \
			drawing/frees.c \
			drawing/game.c \
			drawing/inicialice.c \
			drawing/init_aux.c \
			drawing/init_game_2.c \
			drawing/init_game.c \
			drawing/init_images_texture.c \
			drawing/init_render.c \
			drawing/init_william.c \
			drawing/init.c\
			drawing/key_release.c\
			drawing/key.c\
			drawing/load_more.c\
			drawing/load.c\
			drawing/mini_william_aux.c\
			drawing/mini_william.c\
			drawing/minimap.c\
			drawing/mouse.c\
			drawing/move_william.c\
			drawing/move.c\
			drawing/render_aux_v2.c\
			drawing/render_aux_v3.c\
			drawing/render_aux.c\
			drawing/render_hud.c\
			drawing/render.c\
			drawing/update_hands.c\
			drawing/update.c\
			drawing/utils.c\
			drawing/worldmap.c

LIB_PATH = ./libft/
LIB = $(LIB_PATH)libft.a

INCLUDES = $(addprefix -I, inc, -I ./minilibx-linux/)

# ============================== DIRECTORIES ================================= #

DIR_SOURCES = src/
DIR_OBJECTS = obj/

OBJECTS = $(addprefix $(DIR_OBJECTS), $(SRC_FILES:.c=.o))
DEPENDENCIES = $(addprefix $(DIR_OBJECTS), $(SRC_FILES:.c=.d))

# ============================== MAKE RULES ================================== #

all: dir $(NAME)

$(MLX):
	make -sC $(MLX_PATH)

-include $(DEPENDENCIES)

dir:
	-mkdir -p $(DIR_OBJECTS)parsing
	-mkdir -p $(DIR_OBJECTS)drawing
	-mkdir -p $(DIR_OBJECTS)parsing_utils
	@$(MAKE) -C $(LIB_PATH)

$(DIR_OBJECTS)%.o: $(DIR_SOURCES)%.c
	$(CC) -MMD $(FLAGS) $(INCLUDES) -c $< -o $@ 

$(NAME): $(OBJECTS) $(MLX)
	$(CC) $(FLAGS) $(OBJECTS) $(LIB) -o $(NAME) $(INCLUDES) $(MLX) -lXext -lX11 -lm
	printf ":D\n"

# # Objects directory rule
# $(OBJ_PATH):
# 	mkdir -p $(OBJ_PATH)

# # Objects rule
# $(OBJ_PATH)%.o: $(SRC_PATH)%.c
# 	$(CC) $(CFLAGS) -DBONUS=$(BONUS) -c $< -o $@ $(INC)

# # Project file rule
# $(NAME): $(OBJS)
# 	$(CC) $(CFLAGS) -DBONUS=$(BONUS) $(OBJS) -o $@ $(INC) $(LIBFT) $(MLX) -lXext -lX11 -lm

# # Libft rule
# $(LIBFT):
# 	make -sC $(LIBFT_PATH)

# # MLX rule-I ./minilibx-linux/
# $(MLX):
# 	make -sC $(MLX_PATH)

# bonus:
# 	make all BONUS=1

# test:
# 	echo $(DIR_OBJECTS)
# 	echo $(DIR_SOURCE)
# 	echo $(DIR_INCLUDE)
# 	echo $(OBJECTS)
# 	echo $(DEPENDENCIES)

# ================================= CLEAN ==================================== #

clean:
	$(RMV) $(DIR_OBJECTS)
	printf "delete dir obj\n"

fclean: clean
	$(RMV) $(NAME)
	@$(MAKE) fclean -C $(LIB_PATH)
	printf "delete $(NAME)\n"

re: fclean all

.PHONY: all clean fclean dir

.SILENT:

# .PHONY: all re clean fclean bonus

# # Program file name
# NAME	= cub3D

# # Mode
# BONUS = 0

# # Compiler and compilation flags
# CC		= gcc
# CFLAGS	= -Werror -Wextra -Wall -g -fsanitize=address

# # Minilibx
# MLX_PATH	= minilibx-linux/
# MLX_NAME	= libmlx.a
# MLX			= $(MLX_PATH)$(MLX_NAME)

# # Libft
# LIBFT_PATH	= libft/
# LIBFT_NAME	= libft.a
# LIBFT		= $(LIBFT_PATH)$(LIBFT_NAME)

# # Sources
# SRC_PATH = ./sources/
# SRC		= 	update_hands.c move_william.c load_more.c key_release.c init_render.c init_aux.c init_game.c init_game_2.c inicialice.c update.c key.c render_hud.c frees.c game.c draw.c init.c init_william.c init_images_texture.c utils.c load.c mouse.c minimap.c mini_william.c mini_william_aux.c worldmap.c move.c render_aux.c render_aux_v2.c render_aux_v3.c render.c
# SRCS	= $(addprefix $(SRC_PATH), $(SRC))

# # Objects
# OBJ_PATH	= ./objects/
# OBJ			= $(SRC:.c=.o)
# OBJS		= $(addprefix $(OBJ_PATH), $(OBJ))

# # Includes
# INC			=	-I ./includes/\
# 				-I ./libft/\
# 				-I ./minilibx-linux/

# # Main rule
# all: $(OBJ_PATH) $(MLX) $(LIBFT) $(NAME)

# # Objects directory rule
# $(OBJ_PATH):
# 	mkdir -p $(OBJ_PATH)

# # Objects rule
# $(OBJ_PATH)%.o: $(SRC_PATH)%.c
# 	$(CC) $(CFLAGS) -DBONUS=$(BONUS) -c $< -o $@ $(INC)

# # Project file rule
# $(NAME): $(OBJS)
# 	$(CC) $(CFLAGS) -DBONUS=$(BONUS) $(OBJS) -o $@ $(INC) $(LIBFT) $(MLX) -lXext -lX11 -lm

# # Libft rule
# $(LIBFT):
# 	make -sC $(LIBFT_PATH)

# # MLX rule
# $(MLX):
# 	make -sC $(MLX_PATH)

# bonus:
# 	make all BONUS=1

# # Clean up build files rule
# clean:
# 	rm -rf $(OBJ_PATH)
# 	make -C $(LIBFT_PATH) clean
# 	make -C $(MLX_PATH) clean

# # Remove program executable
# fclean: clean
# 	rm -f $(NAME)
# 	make -C $(LIBFT_PATH) fclean

# # Clean + remove executable
# re: fclean all