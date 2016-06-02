#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/29 14:39:00 by pdelefos          #+#    #+#              #
#    Updated: 2016/05/30 10:12:39 by pdelefos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC_PATH = src
SRC_NAME = main.c \
		   parse.c \
		   list.c \
		   ft_atoi_ll.c \
		   swap.c \
		   push.c \
		   rotate.c \
		   rev_rotate.c \
		   push_swap.c

OBJ_PATH = obj
OBJ_NAME = $(SRC_NAME:.c=.o)

PATH_INC = includes
PATH_LIBFT = libft/includes
LIBFT = libftprintf.a

CC = clang
CFLAGS = -Wall -Werror -Wextra

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/, $(OBJ_NAME))
INC = $(addprefix -I,$(PATH_INC) $(PATH_LIBFT) $(PATH_MINILIBX))

NO_COLOR = \x1b[0m
GREEN = \x1b[32;01m
RED = \x1b[31;01m
BLUE = \x1b[34;01m
MAGENTA = \x1b[35;01m

all: $(NAME) end

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(INC) $(LIBFT) $(MINILIBX) $(OBJ) -o $(NAME) 
	@echo "$(GREEN)CC >>$(NO_COLOR) $(CFLAGS) libftprintf $(GREEN)>>$(NO_COLOR) \
	$(OBJ_PATH) $(GREEN)>> $(NAME)$(NO_COLOR)"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<
	@echo "$(GREEN)CC$(NO_COLOR) $(MAGENTA)>>$(NO_COLOR) $< $(MAGENTA)>>$(NO_COLOR) $@"

clean:
	@rm -f $(OBJ)
	@echo "$(RED)RM >>$(NO_COLOR) $(OBJ_PATH)"
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)RM >>$(NO_COLOR) $(NAME)"

re: fclean all

end:
	@echo "$(BLUE)-------------------------------------$(NO_COLOR)"

norme:
	norminette $(SRC)
	norminette $(PATH_INC)/libft.h
	norminette $(PATH_INC)/printf.h
	norminette $(PATH_INC)/push_swap.h

.PHONY: all lib clean fclean re norme end
