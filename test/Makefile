# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/22 18:23:49 by mypark            #+#    #+#              #
#    Updated: 2022/03/31 02:11:28 by mypark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -g -fsanitize=address -Wall -Wextra -Werror
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
# 		actions.c

# SRCS =	test_parser.c\
# 		tokenizer.c\
# 		tokenizer_utils.c\
# 		token.c\
# 		cut_tokens.c\
# 		find_token_forward.c\
# 		merge_tokens.c\
# 		buffer.c\
# 		tokenizer_actions.c\
# 		parse_bool.c\
# 		parse_pipe.c\
# 		parse_redir.c\
# 		parse.c\
# 		pass_parenthesis.c\
# 		remove_parenthesis.c\
# 		parse_tree.c\
# 		syntax_error.c\
# 		syntax_unexpected_token.c\
# 		syntax_incorrect_pairs.c\
# 		print_tokens.c\
# 		print_syntax_error.c\
# 		print_malloc_error.c\
# 		print_parsetree.c\
# 		is_chars.c\
# 		issue_token.c

SRCS_EXPANDER =	quote_remover_actions.c\
				quote_remover.c\
				env_epdr_actions.c\
				env_epdr_actions_expand.c\
				env_expander.c\
				dupenv.c\
				wildcard_check_format.c\
				wildcard_matcher_actions.c\
				wildcard_spliter_actions.c\
				wildcard_expander.c\
				wildcard_split.c\
				dup_filenames.c\
				expand.c\
				ep_rec.c\
				tokens_to_splited.c\
				count_token.c

SRCS_REDIRECTION =	make_exetree.c\
					listen_heredoc_quoted.c\
					make_cmd.c\
					meet_redir.c

SRCS_INFO =	cmd_info.c\
			err_info.c\
			exe_info.c

SRCS_TREE =	exe_tree.c\
			parse_tree.c

SRCS_PRINT =	print_syntax_error.c\
				print_malloc_error.c\
				print_strerror.c

SRCS_TEST_PRINT =	print_tokens.c\
					print_parsetree.c\
					print_exetree.c\
					print_ep_rec.c\
					print_splited.c\
					print_exe_info.c

SRCS =	test_to_exetree.c\
		tokenizer.c\
		tokenizer_utils.c\
		token.c\
		cut_tokens.c\
		find_token_forward.c\
		merge_tokens.c\
		buffer.c\
		tokenizer_actions.c\
		parse_bool.c\
		parse_pipe.c\
		parse_redir.c\
		parse.c\
		pass_parenthesis.c\
		remove_parenthesis.c\
		syntax_error.c\
		syntax_unexpected_token.c\
		syntax_incorrect_pairs.c\
		is_chars.c\
		issue_token.c\
		$(SRCS_EXPANDER) \
		$(SRCS_REDIRECTION)\
		$(SRCS_INFO)\
		$(SRCS_TREE)\
		$(SRCS_TEST_PRINT)\
		$(SRCS_PRINT)

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

$(LIBFT_NAME)_re :
	@make fclean bonus -C $(LIBFT_DIR)

$(LIBFT_NAME)_reclean :
	@make fclean bonus -C $(LIBFT_DIR) && make clean -C $(LIBFT_DIR)

$(LIBFT_NAME)_clean :
	@make clean -C $(LIBFT_DIR)

$(LIBFT_NAME)_fclean :
	@make fclean -C $(LIBFT_DIR)
