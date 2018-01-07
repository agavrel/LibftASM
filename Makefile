# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angavrel <angavrel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/29 21:40:42 by angavrel          #+#    #+#              #
#    Updated: 2018/01/07 00:00:19 by angavrel         ###   ########.fr        #
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
					table_type



ASM_COMPILER =		~/.brew/bin/nasm -f macho64 -g
ASM_SRC_DIR =		srcs/
ASM_OBJ_DIR_NAME =	obj
ASM_OBJ_DIR =		$(ASM_OBJ_DIR_NAME)/
ASM_OBJ :=			$(addsuffix .o,$(ASM_FILES))
ASM_OBJ :=			$(addprefix $(ASM_OBJ_DIR),$(ASM_OBJ))

TEST =				test.out
TEST_FILES =		main

C_COMPILER =		clang -Wall -Werror -Wextra
TEST_DIR_NAME =		test
TEST_DIR =			$(TEST_DIR_NAME)/
TEST_OBJ :=			$(addsuffix .o,$(TEST_FILES))
TEST_OBJ :=			$(addprefix $(TEST_DIR),$(TEST_OBJ))

OBJ_PATHS :=		$(ASM_OBJ) $(TEST_OBJ)

all: $(NAME)

$(NAME): $(ASM_OBJ)
	ar rc $(NAME) $(ASM_OBJ)

test: re $(TEST_OBJ)
	$(C_COMPILER) $(TEST_OBJ) -I. -L. -lfts -o $(TEST)

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
