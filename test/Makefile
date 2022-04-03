# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/22 18:23:49 by mypark            #+#    #+#              #
#    Updated: 2022/04/04 01:08:48 by mypark           ###   ########.fr        #
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

INCS_EXPANDER =	-I../parser/expander/\
				-I../parser/expander/env\
				-I../parser/expander/quote

SRCS_EXPANDER =	quote_remover_actions.c\
				quote_remover.c\
				env_expander_actions.c\
				env_expander_actions_dollar.c\
				env_expander.c\
				wildcard_check_format.c\
				wildcard_matcher_actions.c\
				wildcard_spliter_actions.c\
				wildcard_expander.c\
				wildcard_split.c\
				dup_filenames.c\
				expander.c\
				expand_token.c\
				expansion_record.c\
				expansion_range.c

SRCS_REDIRECTION =	make_exetree.c\
					listen_heredoc_quoted.c\
					listen_heredoc.c\
					make_cmd.c\
					meet_redir.c

SRCS_INFO =	cmd_info.c\
			err_info.c\
			exe_info.c\
			exe_info_insert.c\

SRCS_TREE =	exe_tree.c\
			parse_tree.c

SRCS_PRINT =	print_syntax_error.c\
				print_malloc_error.c\
				print_strerror.c

SRCS_TEST_PRINT =	print_tokens.c\
					print_parsetree.c\
					print_exetree.c\
					print_expansion_record.c\
					print_splited.c\
					print_exe_info.c

SRCS_UTILS =	buffer.c\
				is_chars.c\
				dupenv.c\
				is_same.c\
				set_state.c

SRCS_STRICT =	strict_malloc.c\
				strict_fork.c\
				strict_dup2.c\
				strict_close.c\
				strict_open.c\
				strict_execve.c\
				strict_waitpid.c\

SRCS_EXECUTOR =	calc_exit_status.c\
				close_pipes.c\
				close_pipe_oneside.c\
				exe_and.c\
				exe_bool_child.c\
				exe_or.c\
				exe_pipe.c\
				exe_redir.c\
				executor.c\
				set_exe_node_fd.c

SRCS =	test_executor.c\
		count_token.c\
		tokens_to_splited.c\
		tokenizer.c\
		tokenizer_utils.c\
		token.c\
		cut_tokens.c\
		find_token_forward.c\
		merge_tokens.c\
		tokenizer_actions.c\
		parse_bool.c\
		parse_pipe.c\
		parse_redir.c\
		parse.c\
		pass_parentheses.c\
		edge_parentheses.c\
		syntax_error_check.c\
		syntax_unexpected_token.c\
		syntax_incorrect_pairs.c\
		issue_token.c\
		$(SRCS_EXPANDER) \
		$(SRCS_REDIRECTION)\
		$(SRCS_INFO)\
		$(SRCS_TREE)\
		$(SRCS_TEST_PRINT)\
		$(SRCS_PRINT)\
		$(SRCS_UTILS)\
		$(SRCS_STRICT)\
		$(SRCS_EXECUTOR)

OBJ_DIR = ./obj
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
INC_DIR = ../include
VPATH = $(shell ls -R ..)

all : $(NAME)

on_test :
	gcc test_signal.c -L../libft -lft -I../libft -L/usr/include -lreadline

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

re : fclean all

$(OBJ_DIR)/%.o : %.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCS_EXPANDER) -I $(LIBFT_DIR) -I$(RL_INC) -I$(INC_DIR) -c $< -o $@

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
