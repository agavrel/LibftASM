# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angavrel <angavrel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/29 21:40:42 by angavrel          #+#    #+#              #
#    Updated: 2018/05/20 20:47:07 by angavrel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =				libfts.a
ASM_FILES =			ft_isascii	\
					ft_isdigit	\
					ft_isupper	\
					ft_islower	\
					ft_isalpha	\
					ft_isalnum	\
					ft_isprint	\
					ft_strlen	\
					ft_puts		\
					ft_memcpy	\
					ft_toupper	\
					ft_tolower	\
					ft_strcat	\
					ft_pow		\
					ft_strdup	\
					ft_abs		\
					ft_memset	\
					ft_rand		\
					ft_swap		\
					ft_collatz	\
					ft_memchr	\
					ft_strncmp	\
					ft_atoi		\
					ft_align \
					ft_cat	\
					table_type


OS := $(shell uname)

ifeq ($(OS), Darwin)
ASM_COMPILER =		nasm -f macho64 -g#~/.brew/bin/nasm -f macho64 -g
else
ASM_COMPILER =		nasm -f elf64 -g
endif
ASM_SRC_DIR =		srcs/
ASM_OBJ_DIR_NAME =	obj
ASM_OBJ_DIR =		$(ASM_OBJ_DIR_NAME)/
ASM_OBJ :=			$(addsuffix .o,$(ASM_FILES))
ASM_OBJ :=			$(addprefix $(ASM_OBJ_DIR),$(ASM_OBJ))

TEST =				$(TEST_FILES).out
TEST_FILES =		maintest

C_COMPILER =		clang -Wall -Werror -Wextra -pedantic -O3
TEST_DIR_NAME =		test
TEST_DIR =			$(TEST_DIR_NAME)/
TEST_OBJ :=			$(addsuffix .o,$(TEST_FILES))
TEST_OBJ :=			$(addprefix $(TEST_DIR),$(TEST_OBJ))

OBJ_PATHS :=		$(ASM_OBJ) $(TEST_OBJ)

all: $(NAME)

$(NAME): $(ASM_OBJ)
	ar rc $(NAME) $(ASM_OBJ)

test: re $(TEST_OBJ)
	$(C_COMPILER) -L. $(TEST_OBJ) $(NAME) -o $(TEST)

$(ASM_OBJ): $(ASM_OBJ_DIR)%.o: $(ASM_SRC_DIR)%.s
	@/bin/mkdir -p $(ASM_OBJ_DIR)
	$(ASM_COMPILER) $< -o $@

$(TEST_OBJ): $(TEST_DIR)%.o: $(TEST_DIR)%.c
	$(C_COMPILER) -c -I. $< -o $@

clean:
	-/bin/rm -f $(OBJ_PATHS)
	/usr/bin/find . -name "$(ASM_OBJ_DIR_NAME)" -maxdepth 1 -type d -empty -delete

fclean: clean
	-/bin/rm -f $(NAME)
	-/bin/rm -f $(TEST)

re: fclean all

.PHONY: all clean fclean re
