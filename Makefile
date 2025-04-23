# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/22 08:06:23 by gasroman          #+#    #+#              #
#    Updated: 2025/04/23 07:07:07 by gasroman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ============================== VARIABLES =================================== #

FLAGS = -g
RMV = rm -rf
CC = cc
NAME = cub3D

# =============================== SOURCES ==================================== #

SRC_FILES = main.c \
			parsing/data_sorter.c \
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
			parsing_utils/texture_color.c

LIB_PATH = ./libft/
LIB = $(LIB_PATH)libft.a

INCLUDES = $(addprefix -I, inc)

# ============================== DIRECTORIES ================================= #

DIR_SOURCES = src/
DIR_OBJECTS = obj/

OBJECTS = $(addprefix $(DIR_OBJECTS), $(SRC_FILES:.c=.o))
DEPENDENCIES = $(addprefix $(DIR_OBJECTS), $(SRC_FILES:.c=.d))

# ============================== MAKE RULES ================================== #

all: dir $(NAME)

-include $(DEPENDENCIES)

dir:
	-mkdir -p $(DIR_OBJECTS)parsing
	-mkdir -p $(DIR_OBJECTS)parsing_utils
	@$(MAKE) -C $(LIB_PATH)

$(DIR_OBJECTS)%.o: $(DIR_SOURCES)%.c
	$(CC) -MMD $(FLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJECTS)
	$(CC) $(FLAGS) $(OBJECTS) $(LIB) -o $(NAME) $(INCLUDES)
	printf ":D\n"

test:
	echo $(DIR_OBJECTS)
	echo $(DIR_SOURCE)
	echo $(DIR_INCLUDE)
	echo $(OBJECTS)
	echo $(DEPENDENCIES)

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