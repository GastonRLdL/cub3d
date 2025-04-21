FLAGS = -Wall -Werror -Wextra -g
RMV = rm -rf
CC = cc
NAME = cub3D

DIR_SOURCE = src
DIR_INCLUDE = inc

DIR_OBJECTS = obj

SOURCES = $(DIR_SOURCE)/parsing_utils/*.c \
		  $(DIR_SOURCE)/parsing/*.c

OBJECTS = $(addprefix $(DIR_OBJECTS)/, $(SOURCES:.c=.o))

DEPENDECIES = $(addprefix $(DIR_OBJECTS)/, $(SOURCES:.c=.d))

INCLUDES = $(addprefix -I, inc)

all: dir

$(NAME): $(OBJECTS)
	$(CC) $(FLAGS) $(INCLUDES) $(OBJECTS) -o $(NAME)
	printf ":D\n"

$(DIR_OBJECTS)/%.o:$(DIR_SOURCE)/%.c
	printf "Estoy compilando\n"
	$(CC) $(FLAGS) $(INCLUDES) -MMD -c $< -o $@
	printf ":)\n"

test:
	echo $(DIR_OBJECTS)
	echo $(DIR_SOURCE)
	echo $(DIR_INCLUDE)
	echo $(OBJECTS)
	echo $(DEPENDECIES)
dir:
	-mkdir -p $(DIR_OBJECTS)

clean:
	$(RMV) $(DIR_OBJECTS)
	printf "delete dir obj\n"

fclean: clean
	$(RMV) $(NAME)
	printf "delete $(NAME)"

re: fclean all

.PHONY: all clean fclean dir

.SILENT: