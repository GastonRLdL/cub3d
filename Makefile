# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/22 08:06:23 by gasroman          #+#    #+#              #
#    Updated: 2025/04/22 10:49:19 by gasroman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ============================== VARIABLES =================================== #

FLAGS = -Wall -Werror -Wextra -g
RMV = rm -rf
CC = cc
NAME = cub3D

# ============================== DIRECTORIES ================================= #

DIR_SOURCES = src/
DIR_INCLUDE = inc/
DIR_OBJECTS = obj/

# =============================== SOURCES ==================================== #

# SRC_DIR = $(DIR_SOURCES)parsing/

# UTL_DIR	= $(DIR_SOURCES)parsing_utils/

# MAIN_FILE = $(DIR_SOURCES)main.c

# SRC_FILES = data_sorter.c parser_data.c store_color.c store_texture.c texture_format.c value_checks.c

# UTL_FILES = free_data.c ft_split_set.c ft_trim.c process_line.c split_size.c

# SOURCES = $(addprefix $(SRC_DIR), $(SRC_FILES)) \ $(MAIN_FILE) \ $(addprefix $(UTL_DIR), $(UTL_FILES))

SRC_FILES = parsing/data_sorter.c \
			parsing/parser_data.c \
			parsing/store_color.c  \
			parsing/store_texture.c  \
			parsing/texture_format.c \
			parsing/value_checks.c \
			parsing_utils/free_data.c \
			parsing_utils/ft_split_set.c \
			parsing_utils/ft_trim.c \
			parsing_utils/process_line.c \
			parsing_utils/split_size.c \
			main.c

SOURCES = $(addprefix $(DIR_SOURCES), $(SRC_FILES))

OBJECTS = $(addprefix $(DIR_OBJECTS), $(SRC_FILES:.c=.o))

DEPENDENCIES = $(addprefix $(DIR_OBJECTS), $(SRC_FILES:.c=.d))

LIB_PATH = ./libft/
LIB = $(LIB_PATH)libft.a

INCLUDES = $(addprefix -I, inc)

# ============================== MAKE RULES ================================== #

all: dir $(NAME)

-include $(DEPENDENCIES)

# $(DIR_OBJECTS)%.o: $(SRC_DIR)%.c
# 	$(CC) $(FLAGS) $(INCLUDES) -MMD -c $< -o $@

# $(DIR_OBJECTS)%.o: $(UTL_DIR)%.c
# 	$(CC) $(FLAGS) $(INCLUDES) -MMD -c $< -o $@
# 	printf ":(\n"

$(DIR_OBJECTS)%.o: $(DIR_SOURCES)%.c
	$(CC) $(FLAGS) $(INCLUDES) -MMD -c $< -o $@

$(NAME): $(OBJECTS)
	$(CC) $(FLAGS) $(INCLUDES) $(OBJECTS) -o $(NAME)
	printf ":D\n"

test:
	echo $(DIR_OBJECTS)
	echo $(DIR_SOURCE)
	echo $(DIR_INCLUDE)
	echo $(OBJECTS)
	echo $(DEPENDENCIES)
	
dir:
	-mkdir -p $(DIR_OBJECTS)src/parsing
	-mkdir -p $(DIR_OBJECTS)src/parsing_utils
	@$(MAKE) -C $(LIB_PATH)

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