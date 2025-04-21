FLAGS = -Wall -Werror -Wextra -g
RMV = rm -rf
CC = cc
NAME = cub3D

DIR_SOURCE = src/
DIR_INCLUDE = inc/

DIR_OBJECTS = obj

SRC_DIR = $(DIR_SOURCE)/parsing/

UTL_DIR	= $(DIR_SOURCE)/parsing_utils/

MAIN_FILE = $(DIR_SOURCE)/main.c

SRC_FILES = data_sorter.c parser_data.c store_color.c store_texture.c texture_format.c value_checks.c

UTL_FILES = free_data.c ft_split_set.c ft_trim.c process_line.c split_size.c

SOURCES = $(addprefix $(SRC_DIR)/, $(SRC_FILES)) $(MAIN_FILE) $(addprefix $(UTL_DIR)/, $(UTL_FILES))

OBJECTS = $(addprefix $(DIR_OBJECTS)/, $(SOURCES:.c=.o))

DEPENDENCIES = $(addprefix $(DIR_OBJECTS)/, $(SOURCES:.c=.d))

INCLUDES = $(addprefix -I, inc)

all: dir

$(NAME): $(OBJECTS)
	$(CC) $(FLAGS) $(INCLUDES) $(OBJECTS) -o $(NAME)
	printf ":D\n"

$(DIR_OBJECTS)/%.o: $(DIR_SOURCE)/parsing/%.c
	$(CC) $(FLAGS) $(INCLUDES) -MMD -c $< -o $@

$(DIR_OBJECTS)/%.o: $(DIR_SOURCE)/parsing_utils/%.c
	$(CC) $(FLAGS) $(INCLUDES) -MMD -c $< -o $@
	printf ":(\n"

test:
	echo $(DIR_OBJECTS)
	echo $(DIR_SOURCE)
	echo $(DIR_INCLUDE)
	echo $(OBJECTS)
	echo $(DEPENDENCIES)
dir:
	-mkdir -p $(DIR_OBJECTS)

clean:
	$(RMV) $(DIR_OBJECTS)
	printf "delete dir obj\n"

fclean: clean
	$(RMV) $(NAME)
	printf "delete $(NAME)\n"

re: fclean all

.PHONY: all clean fclean dir

.SILENT: