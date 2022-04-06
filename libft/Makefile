NAME = libft.a
SRCS =	ft_atoi.c\
		ft_bzero.c\
		ft_calloc.c\
		ft_isalnum.c\
		ft_isalpha.c\
		ft_isascii.c\
		ft_isdigit.c\
		ft_isprint.c\
		ft_itoa.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_memcpy.c\
		ft_memmove.c\
		ft_memset.c\
		ft_putchar_fd.c\
		ft_putendl_fd.c\
		ft_putnbr_fd.c\
		ft_putstr_fd.c\
		ft_split.c\
		ft_strchr.c\
		ft_strdup.c\
		ft_striteri.c\
		ft_strjoin.c\
		ft_strlcat.c\
		ft_strlcpy.c\
		ft_strlen.c\
		ft_strmapi.c\
		ft_strncmp.c\
		ft_strndup.c\
		ft_strnstr.c\
		ft_strrchr.c\
		ft_strtrim.c\
		ft_substr.c\
		ft_tolower.c\
		ft_toupper.c\
		ft_strtoupper.c\
		ft_realloc.c\
		ft_strmerge.c\
		ft_strappend.c\
		ft_strprepend.c\
		ft_splitfree.c\
		ft_splitdup.c\
		ft_wordcount.c\
		ft_strchri.c\
		ft_strdiv.c

SRCS_BONUS =	ft_lstadd_back.c\
				ft_lstadd_front.c\
				ft_lstclear.c\
				ft_lstdelone.c\
				ft_lstiter.c\
				ft_lstlast.c\
				ft_lstmap.c\
				ft_lstnew.c\
				ft_lstsize.c\
				ft_lstdup.c\
				ft_lstpop_front.c\
				bi_lstadd_back.c\
				bi_lstadd_front.c\
				bi_lstdelone.c\
				bi_lstfind_backward.c\
				bi_lstfind_forward.c\
				bi_lstlast.c\
				bi_lstnew.c\
				bi_lstpop_back.c\
				bi_lstpop_front.c\
				bi_lstsize.c\
				cir_lstadd_back.c\
				cir_lstadd_front.c\
				cir_lstclear.c\
				cir_lstdelone.c\
				cir_lstfind_backward.c\
				cir_lstfind_forward.c\
				cir_lstlast.c\
				cir_lstnew.c\
				cir_lstpop_back.c\
				cir_lstpop_front.c\
				cir_lstsize.c\
				stack.c\
				queue.c\
				free_deque.c\
				new_deque.c\
				pop_deque.c\
				push_deque.c

ifeq ($(CHECK_BONUS), 1)
	SRCS := $(SRCS) $(SRCS_BONUS)
endif

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)
AR = ar
ARFLAGS = -rcs
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCS = libft.h
RM = rm -f
VPATH = $(shell ls -R)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

%.o: %.c $(INCS)
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME)
	$(RM) libft.so

re: fclean all

.PHONY: re clean fclean all

bonus:
	@make CHECK_BONUS=1 all

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRCS)
	gcc -nostartfiles -shared -o libft.so $(OBJS) $(OBJS_BONUS)


