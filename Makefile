# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mypark <mypark@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/06 15:54:50 by dha               #+#    #+#              #
#    Updated: 2022/04/05 18:54:24 by mypark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -g -fsanitize=address -Wall -Wextra -Werror
AR = ar rcs
RM = rm -rf
NAME = minishell

LIBFT_DIR = ./libft
LIBFT_NAME = ft
LIBFT = $(LIBFT_DIR)/lib$(LIBFT_NAME).a

RL_DIR = $(shell brew --prefix readline)#/usr/include
RL_INC = $(RL_DIR)/include
RL_LIB = $(RL_DIR)/lib

INCS_LEXER		=	-I./parser/lexer\
					-I./parser/lexer/tokenizer\
					-I./parser/lexer/syntax
INCS_EXPANDER 	=	-I./parser/expander/\
					-I./parser/expander/env\
					-I./parser/expander/quote\
					-I./parser/expander/wildcard\
					-I./parser/expander/wildcard/wildcard_spliter\
					-I./parser/expander/expand_token\
					-I./parser/expander/expansion_record
INCS_PARSER		=	-I./parser\
					-I./parser/parsing\
					$(INCS_EXPANDER)\
					$(INCS_LEXER)
INCS_BUILTIN	=	-I./builtin
INCS_UTILS		=	-I./utils
INCS_STRUCTURE	=	-I./structure/info\
					-I./structure/token\
					-I./structure/tree
INCS_ERROR		=	-I./error\
					-I./error/strict

INCS =	$(INCS_BUILTIN) $(INCS_PARSER) $(INCS_STRUCTURE) $(INCS_UTILS) $(INCS_ERROR)

SRCS_EXPANDER		=	quote_remover_actions.c\
						quote_remover.c\
						env_expander_actions.c\
						env_expander_actions_dollar.c\
						env_expander.c\
						wildcard_match.c\
						wildcard_matcher_actions.c\
						wildcard_spliter_actions.c\
						wildcard_expander.c\
						wildcard_split.c\
						dup_filenames.c\
						expander.c\
						expand_token.c\
						expansion_record.c\
						expansion_range.c

SRCS_REDIRECTION	=	make_exetree.c\
						listen_heredoc_quoted.c\
						listen_heredoc.c\
						make_cmd.c\
						meet_redir.c

SRCS_INFO			=	cmd_info.c\
						err_info.c\
						exe_info.c\
						exe_info_insert.c

SRCS_TREE			=	exe_tree.c\
						parse_tree.c

SRCS_PRINT			=	print_syntax_error.c\
						print_malloc_error.c\
						print_strerror.c

SRCS_TEST_PRINT		=	print_tokens.c\
						print_parsetree.c\
						print_exetree.c\
						print_expansion_record.c\
						print_splited.c\
						print_exe_info.c

SRCS_BUILTINS		=	builtin.c\
						cd.c\
						pwd.c


SRCS_UTILS			=	buffer.c\
						is_chars.c\
						dupenv.c\
						is_same.c\
						set_state.c

SRCS_STRICT			=	strict_malloc.c\
						strict_fork.c\
						strict_dup2.c\
						strict_close.c\
						strict_open.c\
						strict_execve.c\
						strict_waitpid.c

SRCS_EXECUTOR		=	calc_exit_status.c\
						close_fd.c\
						close_pipes.c\
						close_pipe_oneside.c\
						exe_and.c\
						exe_bool_child.c\
						exe_or.c\
						exe_pipe.c\
						exe_redir.c\
						executor.c\
						set_exe_node_fd.c

SRCS_TOKEN			=	count_token.c\
						tokens_to_splited.c\
						token.c\
						cut_tokens.c\
						merge_tokens.c\
						issue_token.c\
						find_token_forward.c

SRCS_TOKENIZER		=	tokenizer.c\
						tokenizer_actions.c
SRCS_PARSER			=	parse_bool.c\
						parse_pipe.c\
						parse_redir.c\
						parser.c\
						pass_parentheses.c\
						edge_parentheses.c\
						syntax_error_check.c\
						syntax_unexpected_token.c\
						syntax_incorrect_pairs.c

SRCS =	minishell.c \
		$(SRCS_TOKEN)\
		$(SRCS_TOKENIZER)\
		$(SRCS_PARSER)\
		$(SRCS_EXPANDER) \
		$(SRCS_REDIRECTION)\
		$(SRCS_INFO)\
		$(SRCS_TREE)\
		$(SRCS_TEST_PRINT)\
		$(SRCS_PRINT)\
		$(SRCS_UTILS)\
		$(SRCS_STRICT)\
		$(SRCS_EXECUTOR)\
		$(SRCS_BUILTINS)

OBJ_DIR = ./objs
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
INC_DIR = ./include
VPATH = $(shell ls -R)

all : $(NAME)

$(NAME) : $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) \
	-L $(LIBFT_DIR) -l$(LIBFT_NAME) \
	-L $(RL_LIB) -lreadline \
	-L $(RL_LIB) -lhistory \
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
	@$(CC) $(CFLAGS) $(INCS) -I $(LIBFT_DIR) -I $(RL_INC) -I$(INC_DIR) -c $< -o $@ -g

.PHONY : all clean fclean wclean re rr \
	$(LIBFT_NAME)_clean $(LIBFT_NAME)_fclean

$(LIBFT) :
	@make -C $(LIBFT_DIR)

$(LIBFT_NAME)_clean :
	@make -C $(LIBFT_DIR) clean

$(LIBFT_NAME)_fclean :
	@make -C $(LIBFT_DIR) fclean

$(LIBFT_NAME)_reclean :
	@make fclean bonus -C $(LIBFT_DIR) && make clean -C $(LIBFT_DIR)
