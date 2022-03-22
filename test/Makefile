# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/22 18:23:49 by mypark            #+#    #+#              #
#    Updated: 2022/03/23 01:38:43 by mypark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -fsanitize=address#-Wall -Wextra -Werror
AR = ar rcs
RM = rm -rf
NAME = minishell

LIBFT_DIR = ../libft
LIBFT_NAME = ft
LIBFT = $(LIBFT_DIR)/lib$(LIBFT_NAME).a

RL_DIR = /usr/include#$(shell brew --prefix readline)
RL_INC = $(RL_DIR)/include
RL_LIB = $(RL_DIR)/lib

# SRCS =	test_tokenizer.c\
# 		tokenizer.c\
# 		tokenizer_utils.c\
# 		token.c\
# 		cut_tokens.c\
# 		find_token_forward.c\
# 		merge_tokens.c\
# 		print_tokens.c\
# 		buffer.c\
# 		behavior.c

SRCS =	test_parser.c\
		tokenizer.c\
		tokenizer_utils.c\
		token.c\
		cut_tokens.c\
		find_token_forward.c\
		merge_tokens.c\
		print_tokens.c\
		buffer.c\
		behavior.c\
		parse_bool.c\
		parse_pipe.c\
		parse_redir.c\
		parse.c\
		pass_parenthesis.c\
		remove_parenthesis.c\
		parse_tree.c\
		syntax_error.c\
		syntax_unexpected_token.c\
		syntax_incorrect_pairs.c\
		syntax_error_print.c\
		print_parsetree.c\
		is_chars.c


INCS = test.h
OBJ_DIR = ./obj
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
INC_DIR = ../include
VPATH = $(shell ls -R ..)

all : $(NAME)

$(NAME) : $(LIBFT) $(OBJS) $(INCS)
	@$(CC) $(CFLAGS) $(OBJS) \
	-L $(LIBFT_DIR) -l$(LIBFT_NAME) \
	-L $(RL_DIR) -lreadline \
	-o $@
	@printf "💡 Make $(NAME) Done\n"

clean :
	@$(RM) $(OBJ_DIR)
	@echo "🗑 Remove $(NAME)'s OBJs Done"

fclean : clean
	@$(RM) $(NAME)
	@echo "🗑 Remove $(NAME) Done"

wclean : fclean $(LIBFT_NAME)_fclean

re : fclean all

rr : wclean all

$(OBJ_DIR)/%.o : %.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I $(LIBFT_DIR) -I$(RL_INC) -I$(INC_DIR) -c $< -o $@ -g

.PHONY : all clean fclean wclean re rr \
	$(LIBFT_NAME)_clean $(LIBFT_NAME)_fclean

$(LIBFT) :
	@make bonus -C $(LIBFT_DIR)

$(LIBFT_NAME)_clean :
	@make -C $(LIBFT_DIR) clean

$(LIBFT_NAME)_fclean :
	@make -C $(LIBFT_DIR) fclean
