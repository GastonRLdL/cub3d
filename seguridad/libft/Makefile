# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/05 14:35:28 by gasroman          #+#    #+#              #
#    Updated: 2024/07/10 17:26:17 by gasroman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# =============================== VARIABLES ================================== #

NAME	=	libft.a
CC		=	cc
RM		=	rm -rf
FLAGS	=	-Wall -Wextra -Werror
LIBC	=	ar -rcs

# =========================== SOURCES ======================================== #

SRCS_FILES	=	ft_atoi			\
				ft_bzero		\
				ft_calloc		\
				ft_isalnum		\
				ft_isalpha		\
				ft_isascii		\
				ft_isdigit		\
				ft_isprint		\
				ft_itoa			\
				ft_memchr		\
				ft_memcmp		\
				ft_memcpy		\
				ft_memmove		\
				ft_memset		\
				ft_putchar_fd	\
				ft_putendl_fd	\
				ft_putnbr_fd	\
				ft_putstr_fd	\
				ft_split		\
				ft_strchr		\
				ft_strdup		\
				ft_striteri		\
				ft_strjoin		\
				ft_strlcat		\
				ft_strlcpy		\
				ft_strlen		\
				ft_strmapi		\
				ft_strncmp		\
				ft_strnstr		\
				ft_strrchr		\
				ft_strtrim		\
				ft_substr		\
				ft_tolower		\
				ft_toupper		\
				ft_printf		\
				ft_for_cs		\
				ft_for_diupx	\
				fd_printf		\
				fd_for_cs		\
				fd_for_diupx	\
				fd_for_xX		\
				get_next_line	\
				get_next_line_utils	\
				
BONUS_FILES	=	ft_lstadd_back	\
				ft_lstadd_front	\
				ft_lstclear		\
				ft_lstdelone	\
				ft_lstiter		\
				ft_lstlast		\
				ft_lstmap		\
				ft_lstnew		\
				ft_lstsize		\

# =========================== DIRECTORIES ==================================== #

#.c
SRCS = $(addsuffix .c, $(SRCS_FILES))
BONUS = $(addsuffix .c, $(BONUS_FILES))

D_OBJ = obj
#.o
OBJ = $(addprefix $(D_OBJ)/, $(SRCS:.c=.o))
DEP = $(addprefix $(D_OBJ)/, $(SRCS:.c=.d))
#Bonus .o
B_OBJ = $(addprefix $(D_OBJ)/, $(BONUS:.c=.o))
# B_DEP = $(addprefix $(D_OBJ)/, $(BONUS:.c=.d))

# =========================== BOLD COLORS ==================================== #

E = \033[m
R = \033[31m
G = \033[32m
Y = \033[33m
B = \033[34m
P = \033[35m
C = \033[36m
#Font
ligth = \033[1m
dark = \033[2m
italic = \033[3m

# ========================== MAKE RULES ===================================== #
all:	dir $(NAME)
-include $(DEP)
-include $(B_DEP)

dir: 
	@mkdir -p $(D_OBJ)

$(D_OBJ)/%.o: %.c
	$(CC) -MMD $(FLAGS) -c $< -o $@
	@printf "\r$(G)$<$(E) to $(P)$@$(E)                                       "

$(NAME):	${OBJ}
	$(LIBC) $(NAME) $(OBJ)
	touch $(NAME)
	@echo "\n$(G)$(NAME) succesfully compiled...$(E)"
	
bonus:	dir ${B_OBJ} $(NAME)
	if [ -f bonus ]; then\
		echo "$(B)$(ligth)make:$(E)$(ligth) 'bonus' is up to date.$(E)";\
	else\
		$(LIBC) $(NAME) $(OBJ) $(B_OBJ);\
		touch bonus;\
		echo "$B$(ligth)⏳Compiling libft:$E";\
	fi
# ========================== CLEAN   ===================================== #
.PHONY: all clean fclean re bonus
clean:
	$(RM) $(D_OBJ) bonus
	echo "✅ ==== $(P)$(ligth)Libft object files cleaned!$(E) ==== ✅"
fclean: clean
	$(RM) $(NAME)
	echo "✅ ==== $(P)$(ligth)Libft executable files and name cleaned!$(E) ==== ✅\n"
re: fclean all
TOTAL_FILES := $(words $(SRCS))
.SILENT:
